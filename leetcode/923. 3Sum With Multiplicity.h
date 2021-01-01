//
// Created by apel on 01.01.2021.
//

#ifndef CPP_TRAINING_923_3SUM_WITH_MULTIPLICITY_H
#define CPP_TRAINING_923_3SUM_WITH_MULTIPLICITY_H

// problem:
// https://leetcode.com/problems/3sum-with-multiplicity/

class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int MOD = 1e9 + 7;
        long long answer = 0;
        int max_n = 101;

        int keys_size = 0;
        std::vector<long long> counts(max_n, 0);

        for (auto &el : A) {
            counts[el]++;
            if (counts[el] == 1) ++keys_size;
        }
        std::vector<int> keys(0); keys.reserve(keys.size());
        for (int i = 0; i < max_n; ++i)
            if (counts[i] > 0)
                keys.push_back(i);

        for (int xp = 0 ; xp < keys_size; ++xp) {
            int lp = xp,
                    rp = keys_size - 1;
            int need_to_find = target - keys[xp];
            while (lp <= rp) {
                if (keys[lp] + keys[rp] < need_to_find) {
                    ++lp;
                } else if (keys[lp] + keys[rp] > need_to_find) {
                    --rp;
                } else {
                    if (xp < lp && lp < rp) {
                        answer += counts[keys[xp]]
                                  * counts[keys[lp]]
                                  * counts[keys[rp]];
                    } else if (xp == lp && lp < rp) {
                        answer += counts[keys[rp]]
                                  * counts[keys[lp]]
                                  * (counts[keys[lp]] - 1)
                                  / 2;
                    } else if (xp < lp && lp == rp) {
                        answer += counts[keys[xp]]
                                  * counts[keys[lp]]
                                  * (counts[keys[lp]] - 1)
                                  / 2;
                    } else {
                        answer += (counts[keys[xp]]
                                   * (counts[keys[xp]] - 1)
                                   * (counts[keys[xp]] - 2)
                                   / 6) % MOD;
                    }
                    answer %= MOD;
                    ++lp;
                    --rp;
                }
            }

        }
        return answer;
    }

    // 89.25% / 67.75%
    int threeSumMulti2(vector<int> &A, int target) {
        int MOD = 1e9 + 7;
        int max_n = 101;
        long long res = 0; 

        std::vector<long long> counts(max_n, 0);
        for (auto &el : A)
            counts[el]++;
        
        for (int i = 0; i < max_n; ++i) 
            for (int j = i + 1; j < max_n; ++j) 
                if (counts[i] && counts[j]) {
                    int val = target - i - j;
                    if (j < val && val < max_n){
                        res += counts[i] * counts[j] * counts[val];
                        res %= MOD;
                    }   
                }
            
        for (int i = 0; i < max_n; ++i) 
            if (counts[i]) {
                int val = target - 2 * i;
                if (i < val && val < max_n){
                    res += (counts[i] - 1) * counts[i] / 2 * counts[val];
                    res %= MOD;
                }   
            }

        for (int i = 0; i < max_n; ++i) 
            if (counts[i] && ((target - i) % 2 == 0)) {
                int val = (target - i) / 2;
                if (i < val && val < max_n) {
                    res += counts[i] * counts[val] * (counts[val] - 1) / 2;
                    res %= MOD;
                }
            }
        

        if (target % 3 == 0) {
            int val = target / 3;
            if (0 <= val && val < max_n) {
                res += (counts[val] * (counts[val] - 1) * (counts[val] - 2) / 6) % MOD;
                res %= MOD;
            }
        }
        return res;
    }
    // 36.48% / 67.75%
    int threeSumMulti1(std::vector<int>& A, int target) {
        int n = A.size();
        int mod = 1e9 + 7;
        std::sort(A.begin(), A.end());

        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (A[i] + A[l] + A[r] > target) {
                    --r;
                } else if (A[i] + A[l] + A[r] < target) {
                    ++l;
                } else {
                    int ll = 1, rr = 1;
                    while (l < r && A[l] == A[l+1]) {
                        ++l; ll++;
                    }
                    while (l < r && A[r] == A[r-1]) {
                        --r; rr++;
                    }
                    res += ll * rr;
                    ++l;
                }
            }
        }
        return res;
    }
};

#endif //CPP_TRAINING_923_3SUM_WITH_MULTIPLICITY_H
