//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1052_RABBIT_HUNT_H
#define CPP_TRAINING_1052_RABBIT_HUNT_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1052&locale=en

class Solution {
public:
    void solver() {
        size_t n; cin >> n;
        vector<pair<int, int>> a(n);
        for (size_t i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        int max_all = 0;
        for (size_t i = 0; i < n; ++i) {
            set<pair<int, int>> lines;
            int max_cur = 0;
            int cur = 1;
            auto &p0 = a[i];

            std::sort(a.begin() + 1 + i, a.end(), [&p0, &lines](const auto &p1, const auto &p2) {
                int dx1 =  p0.first - p1.first;
                int dx2 =  p0.first - p2.first;
                int dy1 =  p0.second - p1.second;
                int dy2 =  p0.second - p2.second;
                if (dx1 == 0)
                    lines.insert(p1);
                if (dx2 == 0)
                    lines.insert(p2);

                return dy1 * dx2 < dx1 * dy2;
            });
            for (size_t j = i + 2; j < n; ++j) {
                int dx1 =  a[i].first - a[j - 1].first;
                int dx2 =  a[i].first - a[j].first;
                int dy1 =  a[i].second - a[j - 1].second;
                int dy2 =  a[i].second - a[j].second;
                if (dy1 * dx2 == dx1 * dy2)
                    ++cur;
                else {
                    max_cur = max(cur, max_cur);
                    cur = 1;
                }
            }
            max_cur = max(cur, max_cur);
            max_all = max(max_all, max_cur + 1);
        }
        cout << max_all;
    }
};

#endif //CPP_TRAINING_1052_RABBIT_HUNT_H
