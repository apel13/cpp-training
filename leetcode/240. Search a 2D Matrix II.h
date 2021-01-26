#pragma once

// problem:
// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;

        j = (upper_bound(matrix[0].begin(),
                         matrix[0].end(), target) - matrix[0].begin()) - 1;
        if (j < 0) return false;

        while (true) {
            while (i < n && matrix[i][j] < target) 
                ++i;
            if (i == n) return false;

            while (j >= 0 && matrix[i][j] > target) 
                --j;
            if (j < 0) return false;
            if (matrix[i][j] == target) return true;
        }
        return false;
    }
};