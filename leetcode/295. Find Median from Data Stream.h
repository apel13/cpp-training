//
// Created by apel on 09.01.2021.
//

#ifndef CPP_TRAINING_295_FIND_MEDIAN_FROM_DATA_STREAM_H
#define CPP_TRAINING_295_FIND_MEDIAN_FROM_DATA_STREAM_H

// problem:
// https://leetcode.com/problems/find-median-from-data-stream/

// 2 heap (236 ms)
class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
        lower.push(num);
        upper.push(lower.top()); lower.pop();
        if (lower.size() < upper.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }

    double findMedian() {
        if (lower.size() != upper.size())
            return lower.size();
        return (lower.top() + upper.top()) / 2.0;
    }
    priority_queue<int, vector<int>, std::greater<>> lower;
    priority_queue<int> upper;
};

// Insertion Sort (276 ms)
class MedianFinder2 {
public:
    MedianFinder() {}
    void addNum(int num) {
        nums.insert(std::upper_bound(nums.begin(), nums.end(), num), num);
    }

    double findMedian() {
        int n = nums.size();
        return (n & 1) ? nums[n/2] : (nums[n / 2] + nums[n / 2 - 1]) / 2.0;
    }
    vector<int> nums;
};

// Sort (TL)
class MedianFinder1 {
public:
    MedianFinder() {}
    void addNum(int num) {
        nums.push_back(num);
    }
    double findMedian() {
        std::sort(nums.begin(), nums.end());
        return (nums.size() % 2) ? nums[nums.size()] : (nums[nums.size() / 2 - 1] + nums[nums.size() / 2 - 1]) / 2.0.
    }
    vector<int> nums;
};

#endif //CPP_TRAINING_295_FIND_MEDIAN_FROM_DATA_STREAM_H
