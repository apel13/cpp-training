//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_1499_MAX_VALUE_OF_EQUATION_H
#define CPP_TRAINING_1499_MAX_VALUE_OF_EQUATION_H

class Solution {
public:
    int findMaxValueOfEquation(vector <vector<int>> &points, int k)
    {
        using p = pair<int, int>;
        queue<p> cur_points;
        deque<int> max;
        int res = INT_MIN;

        for (auto & point : points) {
            while (!cur_points.empty() && (point[0] - cur_points.front().first > k)) {
                auto de = cur_points.front();
                if (max.front() == de.second - de.first) {
                    max.pop_front();
                }
                cur_points.pop();
            }
            cur_points.emplace(point[0], point[1]);
            if (!max.empty()) {
                res = std::max(res, point[1] + point[0] + max.front());
            }
            while (!max.empty() && (max.back() < point[1] - point[0])) {
                max.pop_back();
            }
            max.push_back(point[1] - point[0]);

        }
        return res;

    }
};

#endif //CPP_TRAINING_1499_MAX_VALUE_OF_EQUATION_H
