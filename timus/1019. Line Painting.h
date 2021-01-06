//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1019_LINE_PAINTING_H
#define CPP_TRAINING_1019_LINE_PAINTING_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1019&locale=en

class Solution {
public:
    void solver() {
        list<pair<int, int>> a;
        size_t a_size = 1;
        int n;
        cin >> n;

        a.emplace_back(0, 1e9);

        char color;
        int left, right;
        while (n--) {
            cin >> left >> right >> color;
            if (color == 'b') {
                auto it = a.begin(), jt = it;
                while (it != a.end() && it->second <= left) ++it;
                if (it == a.end() || right <= it->first)
                    continue;
                jt = it;
                while (jt != a.end() && jt->second <= right) ++jt;
                if (it == jt) {
                    if (it->first < left) {
                        int tmp_left = it->first;
                        it->first = right;
                        a.insert(it, make_pair(tmp_left, left));
                        continue;
                    } else {
                        it->first = right;
                    }
                }
                if (it->first < left) {
                    it->second = left;
                    it++;
                }
                if (jt->first < right) {
                    jt->first = right;
                }
                if (it != jt) {
                    a.erase(it, jt);
                }
            } else {
                // color == w
                auto it = a.begin(), jt = it;
                while (it != a.end() && it->second < left) {
                    ++it;
                }
                if (it == a.end() || it->first > right) {
                    a.insert(it, make_pair(left, right));
                    continue;
                }
                jt = it;
                while (jt != a.end() && jt->second <= right) {
                    ++jt;
                }
                if (it == jt) {
                    if (right < it->first) {
                        a.insert(it, make_pair(left, right));
                    } else {
                        if (left < it->first)
                            it->first = left;
                    }
                    continue;
                }
                if (jt == a.end()) {
                    int grad_l = min(left, it->first);
                    a.erase(it, jt);
                    a.emplace_back(grad_l, right);
                    continue;
                }

                int left_gran = min(left, it->first);
                if (right < jt->first) {
                    it = a.erase(it, jt);
                    a.insert(it, make_pair(left_gran, right));
                } else {
                    jt->first = left_gran;
                    it = a.erase(it, jt);
                }
            }

        }
        int max = 0;
        pair<int, int> max_p;
        for (auto &p : a) {
            if (p.second - p.first > max) {
                max = p.second - p.first;
                max_p = p;
            }
        }
        cout << max_p.first << " " << max_p.second;
    }
};

#endif //CPP_TRAINING_1019_LINE_PAINTING_H
