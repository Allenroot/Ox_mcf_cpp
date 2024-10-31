#include "Practical01/Practical01Exercises.hpp"
#include <cmath>
// Created by jcong on 10/18/24.
//

namespace exercises {
    double Norm2(const std::vector<double> & dVec) {
        double result = 0;
        for (int i = 0; i < dVec.size(); i++) {
            result = result + dVec[i] * dVec[i];
        }
        return sqrt(result);
    }

    double NormInf(const std::vector<double> & dVec) {
        double max = -1;
        for (int i = 0; i < dVec.size(); i++) {
            if (abs(dVec[i]) > max) {
                max = abs(dVec[i]);
            }
        }
        return max;
    }
}
