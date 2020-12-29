//
// Created by apel on 29.12.2020.
//

#ifndef CPP_TRAINING_149_MAX_POINTS_ON_A_LINE_H
#define CPP_TRAINING_149_MAX_POINTS_ON_A_LINE_H

// problem:
// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    using p = std::pair<int, int>;
    // o(n^2)
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size();
        if (n == 0) return 0;
        int ans = 1, dx, dy;
        for (int i = 0; i < n; ++i) {
            map<p, int> m;
            int sim = 0;
            for (int j = i + 1; j < n; ++j) {
                dx = points[j][0] - points[i][0];
                dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    ++sim;
                    continue;
                }
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
                reduce(dx, dy);
                m[make_pair(dx, dy)]++;
            }
            ans = std::max(ans, sim + 1);
            for (auto &pr : m) {
                ans = std::max(ans, pr.second + sim + 1);
            }
        }
        return ans;
    }

    void reduce(int &a, int &b) {
        if (a == 0) b = 1;
        else if (b == 0) a = 1;
        else {
            int d = std::gcd(a, b);
            a /= d;
            b /= d;
        }
    }
};

#endif //CPP_TRAINING_149_MAX_POINTS_ON_A_LINE_H
