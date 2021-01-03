//
// Created by apel on 03.01.2021.
//

#ifndef CPP_TRAINING_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H
#define CPP_TRAINING_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H

// problem:
// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    // o(n) / o(1) (98.8%, 94.74%)
    int minTaps(int n, vector<int>& dist) {
        for (int i = 0; i < n + 1 ; ++i) {
            int idx = std::max(0, i - dist[i]);
            dist[idx] = std::max(dist[idx], i + dist[i]);
        }
        int *res = new int(); *res = 0;
        int cur_dist = 0;
        int max_dist = 0;

        for (int i = 0; i < n + 1; ++i) {
            max_dist = std::max(max_dist, dist[i]);
            if (i == cur_dist) {
                (*res)++;
                if (max_dist >= n) return *res;
                cur_dist = max_dist;
            }
        }
        return -1;
    }

    int minTaps2(int n, vector<int>& ranges) {
        vector<int> dist(n + 1, -1);

        for (int i = 0; i < n + 1 ; ++i) {
            int idx = std::max(0, i - ranges[i]);
            dist[idx] = std::max(dist[idx], i + ranges[i]);
        }
        int res = 0;
        int cur_dist = 0;
        int max_dist = -1;

        for (int i = 0; i < n + 1; ++i) {
            max_dist = std::max(max_dist, dist[i]);
            if (i == cur_dist) {
                res++;
                if (max_dist >= n) return res;
                cur_dist = max_dist;
            }
        }
        return -1;
    }
};


#endif //CPP_TRAINING_1326_MINIMUM_NUMBER_OF_TAPS_TO_OPEN_TO_WATER_A_GARDEN_H
