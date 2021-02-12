#pragma once

// problem:
// https://leetcode.com/problems/print-foobar-alternately/

class FooBar {
public:
    FooBar(int n)
            : _n(n) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < _n; i++) {
//            unique_lock lck(m);
//            cv.wait(lck, [this]() { return isFoo; });
            while (!isFoo.load(std::memory_order_acquire)) std::this_thread::yield();
            printFoo();
            isFoo.store(false, std::memory_order_release);
//            isFoo = false;
//            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < _n; i++) {
//            unique_lock lck(m);
//            cv.wait(lck, [this]() { return !isFoo; });
            while (isFoo.load(std::memory_order_acquire)) std::this_thread::yield();
            printBar();
            isFoo.store(true, std::memory_order_release);
//            isFoo = true;
//            cv.notify_all();
        }
    }

private:
    int _n;

//    mutex m;
//    condition_variable cv;
//    bool isFoo = true;

    std::atomic<bool> isFoo{true};
};