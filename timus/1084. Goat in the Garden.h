//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1084_GOAT_IN_THE_GARDEN_H
#define CPP_TRAINING_1084_GOAT_IN_THE_GARDEN_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1084&locale=en

class Solution {
public:
    void solver() {
        double a, r;
        cin >> a >> r;
        if (2 * r < a)
            cout << M_PI * r * r;
        else if (2 * r > a * sqrt(2))
            cout << a * a;
        else {
            double alpha = 2 * acos((a / 2.0) / r);
            double s = r * r / 2.0 * (alpha - sin(alpha));
            cout << M_PI * r * r - 4 * s;
        }
    }
};

#endif //CPP_TRAINING_1084_GOAT_IN_THE_GARDEN_H
