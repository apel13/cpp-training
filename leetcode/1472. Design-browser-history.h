//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_1472_DESIGN_BROWSER_HISTORY_H
#define CPP_TRAINING_1472_DESIGN_BROWSER_HISTORY_H

// problem:
// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class BrowserHistory {
public:
    BrowserHistory(string homepage)
    {
        _back.push(homepage);
    }

    void visit(string url)
    {
        stack<string> empty;
        _forward.swap(empty);
        _back.push(url);
    }

    string back(int steps)
    {
        size_t cur_hist_size = _back.size();
        while (steps-- && (--cur_hist_size > 0)) {
            _forward.push(_back.top());
            _back.pop();
        }
        return _back.top();
    }

    string forward(int steps)
    {
        size_t cur_hist_size = _forward.size();
        if (cur_hist_size == 0) return _back.top();
        while (steps-- && (cur_hist_size--)) {
            _back.push(_forward.top());
            _forward.pop();
        }
        return _back.top();
    }

private:
    stack<string> _forward;
    stack<string> _back;


//    list<string> hist;
//    list<string>::iterator current_url;
};

#endif //CPP_TRAINING_1472_DESIGN_BROWSER_HISTORY_H
