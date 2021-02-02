#pragma once 

// problem:
// https://leetcode.com/problems/basic-calculator-ii/ 

class Solution {
public:
    int calculate(string s) {
        std::stringstream ss(s);
        ss >> std::ws;

        stack<int> nums;


        int prev_num;
        bool isNum = true;

        if (!(ss >> prev_num))
            return 0;
        nums.push(prev_num);

        while (true) {
            char op;
            int num;

            if (!(ss >> std::ws >> op >> std::ws >> num)) break;

            if (op == '-')
                num *= -1;
            else if (op == '*') {
                num = num * nums.top();
                nums.pop();
            }
            else if (op == '/') {
                num = nums.top() / num;
                nums.pop();
            }
            nums.push(num);
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};