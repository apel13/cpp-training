//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1572_YEKATERINOZAVODSK_GREAT_WELL_H
#define CPP_TRAINING_1572_YEKATERINOZAVODSK_GREAT_WELL_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1572&locale=en

class Solution {
public:
    void solver() {
        int type, size;
        cin >> type >> size;

        double max_size;
        if (type == 1)
            max_size = 2 * size;
        else if (type == 2)
            max_size = sqrt(2) * size;
        else
            max_size = size;

        int n; cin >> n;
        int res = 0;
        while (n--) {
            int t, s; cin >> t >> s;
            double p;
            if (t == 1)
                p = s * 2;
            else if (t == 2)
                p = s;
            else
                p = s * sqrt(3) / 2.0;
            if (p <= max_size)
                ++res;
        }
        cout << res;
    }
};

#endif //CPP_TRAINING_1572_YEKATERINOZAVODSK_GREAT_WELL_H
