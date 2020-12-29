//
// Created by apel on 29.12.2020.
//

#ifndef CPP_TRAINING_1114_PRINT_IN_ORDER_H
#define CPP_TRAINING_1114_PRINT_IN_ORDER_H

// problem:
// https://leetcode.com/problems/print-in-order/

class Foo {
public:
    // TODO
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    mutex m2, m3;
};

#endif //CPP_TRAINING_1114_PRINT_IN_ORDER_H
