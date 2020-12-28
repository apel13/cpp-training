//
// Created by apel on 28.12.2020.
//

#ifndef CPP_TRAINING_239_SLIDING_WINDOW_MAXIMUM_H
#define CPP_TRAINING_239_SLIDING_WINDOW_MAXIMUM_H

// problem:
// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    // 2 * o(n) mem
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> d; int f;
        for (int i = 0; i < nums.size(); ++i) {
            while (!d.empty() && d.back() < nums[i]) d.pop_back();
            d.push_back(nums[i]);
            if (i >= k - 1) {
                f = d.front();
                if (nums[i - k + 1] == f) d.pop_front();
                nums[i - k + 1] = f;
            }
        }
        nums.erase(nums.begin() + nums.size() - k + 1, nums.end());
        return nums;
    }

    // 3 * o(n) mem
    vector<int> maxSlidingWindow2(vector<int> &nums, int k) {
        int numWindows = nums.size() - k;
        numWindows = numWindows > 0 ? numWindows : 1;
        vector<int> res;
        res.reserve(numWindows);

        queue<int> que;
        deque<int> deq;

        for (int i = 0; i < nums.size(); ++i) {
            int el = nums[i];

            if (que.empty()) {
                que.push(el);
                deq.push_back(el);
            } else {
                que.push(el);

                while (!deq.empty() && deq.back() < el) {
                    deq.pop_back();
                }
                deq.push_back(el);

                if (que.size() > k) {
                    int de = que.front();
                    if (deq.front() == de) {
                        deq.pop_front();
                    }
                    que.pop();
                }
            }

            if (que.size() == k) {
                res.push_back(deq.front());
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_239_SLIDING_WINDOW_MAXIMUM_H
