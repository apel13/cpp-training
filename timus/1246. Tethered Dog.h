//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1246_TETHERED_DOG_H
#define CPP_TRAINING_1246_TETHERED_DOG_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1246&locale=en

class Solution {
public:
    void solver() {
        int n;
        cin >> n;

        pair<int, int> p1, p2, pn;
        cin >> p1.first >> p1.second >> p2.first >> p2.second;

        pair<int, int> prev = p2;

        pair<int, int> max_left_up = p2;
        pair<int, int> prev_max = p1;
        pair<int, int> next_max;

        bool isMax = true;

        for (size_t i = 2; i < n; ++i) {
            pair<int, int> cur_point;
            cin >> cur_point.first >> cur_point.second;
            if (isMax) {
                next_max = cur_point;
                isMax = false;
            }

            if (cur_point.first < max_left_up.first ||
                (cur_point.first == max_left_up.first && cur_point.second > max_left_up.second)) {
                prev_max = prev;
                max_left_up = cur_point;
                isMax = true;
            }
            prev = cur_point;
            if (i == n - 1) {
                pn = cur_point;
                if (isMax) {
                    next_max = p1;
                }
            }
        }

        if (p1.first < max_left_up.first ||
            (p1.first == max_left_up.first && p1.second > max_left_up.second)) {
            prev_max = pn;
            max_left_up = p1;
            next_max = p2;
        }

        int dx1 = next_max.first - max_left_up.first;
        int dy1 = next_max.second - max_left_up.second;
        int dx2 = prev_max.first - max_left_up.first;
        int dy2 = prev_max.second - max_left_up.second;
        if (dx2 == 0 || dy1 * dx2 > dy2 * dx1)
            cout << "cw";
        else cout << "ccw";
    }
};

#endif //CPP_TRAINING_1246_TETHERED_DOG_H
