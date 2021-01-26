#pragma once

// problem:
// https://leetcode.com/problems/search-a-2d-matrix/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;

        while (i < n && matrix[i][j] <= target) 
            i++;
        if (i == 0) return false;
        --i;
        while (j < m && matrix[i][j] < target)
            ++j;
        if (j > m - 1) return false;
        if (matrix[i][j] == target) return true;
        return false;
    }
};
