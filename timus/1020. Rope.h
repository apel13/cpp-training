//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1020_ROPE_H
#define CPP_TRAINING_1020_ROPE_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1020&locale=en

class Solution {
public:
    void solver() {
        int n; cin >> n;
        double r; cin >> r;

        double res = 0.0;

        double x_last,y_last; cin >> x_last >> y_last;
        double x1 = x_last, y1 = y_last;
        double x_cur, y_cur;
        while (--n) {
            cin >> x_cur >> y_cur;
            res += sqrt(pow(x_cur - x_last, 2) + pow(y_cur - y_last, 2));
            x_last = x_cur; y_last = y_cur;
        }
        res += sqrt(pow(x1 - x_last, 2) + pow(y1 - y_last, 2));
        cout <<  res + M_PI * r * 2;
    }
};

#endif //CPP_TRAINING_1020_ROPE_H
