#pragma once

// problem:
// https://leetcode.com/problems/print-in-order/

class Foo {
public:
    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(m);
        printFirst();
//        p2.set_value();
        isTwo = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
//        p2.get_future().wait();
        unique_lock<mutex> lck(m);
        cv.wait(lck, [this](){return this->isTwo; });
        printSecond();
        isThree = true;
        cv.notify_all();
//        p3.set_value();
    }

    void third(function<void()> printThird) {
//        p3.get_future().wait();
        unique_lock<mutex> lck(m);
        cv.wait(lck, [this](){return this->isThree; });
        printThird();
    }

private:
    std::promise<void> p2;
    std::promise<void> p3;

    condition_variable cv;
    bool isTwo = false, isThree = false;
    mutex m;

};

#endif //CPP_TRAINING_1114_PRINT_IN_ORDER_H
