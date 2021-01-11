//
// Created by apel on 09.01.2021.
//

#ifndef CPP_TRAINING_295_FIND_MEDIAN_FROM_DATA_STREAM_H
#define CPP_TRAINING_295_FIND_MEDIAN_FROM_DATA_STREAM_H

// problem:
// https://leetcode.com/problems/find-median-from-data-stream/

// Multiset + 2 pointer (164 ms)
class MedianFinder {
public:
    MedianFinder() : p1(nums.end()), p2(nums.end()){}
    void addNum(int num) {
        nums.insert(num);
        int n = nums.size();
        if (n == 1) {
            p1 = p2 = nums.begin();
            return;
        }

        if (n & 1) {
            if (num < *p1) {
                p2 = std::prev(p2);
            } else if (*p2 <= num) {
                p1 = std::next(p1);
            } else {
                p1 = std::next(p1);
                p2 = std::prev(p2);
            }
        } else {
            if (num < *p1) {
                p1 = std::prev(p1);
            } else
                p2 = std::next(p2);
        }
    }

    double findMedian() {
        return (*p1 + *p2) * 0.5;
    }
    std::multiset<int> nums;
    decltype(nums)::iterator p1;
    std::multiset<int>::iterator p2;
};

// 2 heap (236 ms)
class MedianFinder3 {
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
