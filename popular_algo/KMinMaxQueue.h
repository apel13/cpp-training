//
// Created by apel on 05.12.2020.
//

#ifndef CPP_TRAINING_KMINMAXQUEUE_H
#define CPP_TRAINING_KMINMAXQUEUE_H


class KMinMaxQueue {
public:
    explicit KMinMaxQueue(int k) : _k(k)
    {};

    void push(int val)
    {
        q.push(val);

        while (!d_min.empty() && d_min.back() < val)
            d_min.pop_back();
        d_min.push_back(val);

        while (!d_max.empty() && d_max.back() < val)
            d_max.pop_back();
        d_max.push_back(val);

        if (q.size() > _k) {
            int de = q.front();
            if (d_min.front() == de)
                d_min.pop_front();

            if (d_max.front() == de)
                d_max.pop_front();
            q.pop();
        }
    };

    void pop()
    {
        int de = q.front();
        if (d_min.front() == de)
            d_min.pop_front();

        if (d_max.front() == de)
            d_max.pop_front();
        q.pop();
    };

    int min()
    {
        return d_min.front();
    }

    int max()
    {
        return d_max.front();
    }

    int back() const
    {
        return q.back();
    };

    int front() const
    {
        return q.front();
    }

    size_t size() const
    {
        return q.size();
    }

    bool empty() const
    {
        return q.empty();
    }

private:
    int _k;
    queue<int> q;

    deque<int> d_min;
    deque<int> d_max;

};


#endif //CPP_TRAINING_KMINMAXQUEUE_H
