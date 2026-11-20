#include <QCoreApplication>
#include <QTemporaryDir>
#include <QDebug>
#include "../src/qmmp/recycler_p.h"

#define CHECK(condition) do { if(!(condition)) { qCritical() << "Failed at line" << __LINE__ << #condition; return 1; } } while(false)

int main(int argc, char **argv)
{
    QTemporaryDir temp;
    CHECK(temp.isValid());
    qputenv("XDG_CONFIG_HOME", temp.path().toUtf8());
    QCoreApplication app(argc, argv);
    Recycler queue;
    queue.configure(44100, 2);
    auto enqueue = [&] {
        auto *block = queue.get();
        block->samples = 1024;
        queue.add();
        return block;
    };

    auto *first = enqueue();
    auto *second = enqueue();
    CHECK(queue.next() == first);
    queue.done();
    CHECK(queue.next() == second);
    queue.clear();
    CHECK(!queue.blocked());
    auto *fresh = enqueue();
    queue.done();
    CHECK(queue.used() == 1 && queue.next() == fresh);

    // A second seek with slot zero in flight must wait for the writer to release it.
    queue.clear();
    queue.clear();
    CHECK(queue.empty() && queue.blocked());
    queue.done();
    CHECK(!queue.blocked() && queue.empty());
    fresh = enqueue();
    CHECK(queue.next() == fresh);
    queue.done();
    CHECK(queue.empty());
    return 0;
}
