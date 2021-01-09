//
// Created by apel on 05.12.2020.
//


#include "headers.h"
#include "concurrency/1114. Print in Order.h"

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

int main() {
    //    ifstream fin("input.txt", ios::in);
    //    ofstream fout("output.txt", ios::out | ios::trunc);
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(1);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    //    cout << fixed;
    cout << setw(3);
    cout << setfill(' ');
    //    cout << left;
    //    LOG_DURATION("-_-")

//    std::istream_iterator<int>      in_i(std::cin);
//    std::istream_iterator<double >  in_d(std::cin);
//    std::istream_iterator<string>   in_s(std::cin);

    using mv = std::vector<int>;
    using point = std::pair<int, int>;
    //296456UI

    auto cmp = [](const point &p1, const point &p2){return p1.first < p2.first;};
    multiset<point, decltype(cmp)> s(cmp);
    vector<point> pp = {{1,2}, {1, 3}, {1, 7}, {1, 2}};
    for (point &i : pp) {
        s.insert(i);
    }

    for (auto &p : s) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

