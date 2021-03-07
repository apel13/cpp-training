#pragma once 

// problem:
// https://leetcode.com/problems/arithmetic-subarrays/ 

class Solution {
public:
// time/mem : 98.90% / 90.07%
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& il, vector<int>& ir) {
        vector<bool> ret; ret.reserve(il.size());
        for (int i = 0; i < il.size(); ++i) {
            int l = il[i], len = ir[i] - il[i] + 1;
            if (len < 3) { ret.push_back(true); continue;}

            int min = nums[l], max = nums[l];
            for (int j = l + 1; j < l + len; ++j) {
                min = std::min(min, nums[j]);
                max = std::max(max, nums[j]);
            }
            
            if (min == max) { ret.push_back(true); continue;}
            if ((max - min) % (len - 1)) { ret.push_back(false); continue;}
            int step = (max - min) / (len - 1);
            vector<bool> isHere(len, false);
            bool isOk = true;
            for (int j = l; j < l + len; ++j) {
                int cnum = nums[j] - min;
                if (cnum % step != 0 || isHere[cnum / step]) { isOk = false; break;}
                isHere[cnum / step] = true;
            }
            ret.push_back(isOk);
        }
        return ret;
    }
};
