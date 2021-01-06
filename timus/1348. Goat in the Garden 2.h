//
// Created by apel on 06.01.2021.
//

#ifndef CPP_TRAINING_1348_GOAT_IN_THE_GARDEN_2_H
#define CPP_TRAINING_1348_GOAT_IN_THE_GARDEN_2_H

// problem:
// https://acm.timus.ru/problem.aspx?space=1&num=1348&locale=en

class Solution {
public:
    void solver() {
        pair<int, int> a, b, x;
        int l;
        cin >> a.first >> a.second >> b.first >> b.second;
        cin >> x.first >> x.second;
        cin >> l;

        double xa_sq = pow(x.first - a.first, 2) +
                       pow(x.second - a.second, 2);
        double xb_sq = pow(x.first - b.first, 2) +
                       pow(x.second - b.second, 2);
        double ab_sq = pow(a.first - b.first, 2) +
                       pow(a.second - b.second, 2);


        int max_line = max(xa_sq, xb_sq);
        int min_line = min(xa_sq, xb_sq);

        if (max_line >= min_line + ab_sq) {
            cout << max(0.0, sqrt(min_line) - l) << " " << max(0.0, sqrt(max_line) - l);
            return 0;
        }

        double da = sqrt(xa_sq);
        double db = sqrt(xb_sq);
        double dc = sqrt(ab_sq);
        double p = (da + db + dc) / 2;

        double s = sqrt(p * (p - da) * (p - db) * (p - dc));
        double h = 2 * s / dc;

        cout << max(0.0, h - l) << " " << max(0.00, max(da, db) - l);
    }
};

#endif //CPP_TRAINING_1348_GOAT_IN_THE_GARDEN_2_H
