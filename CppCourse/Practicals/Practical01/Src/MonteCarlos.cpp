#include <valarray>

#include "Practical01/Practical01Exercises.hpp"
#include "Utils/UtilityFunctions.hpp"
// Created by jcong on 10/19/24.
//

namespace exercises {
    double MonteCarlo1(double dR,
                       double dSigma,
                       double dS0,
                       double dK ,
                       double dT,
                       unsigned long int iN) {
            double a = (dR - dSigma * dSigma / 2) * dT;
            std::vector<double> price(iN);
            utils::NormalDist(price);
            for (int i = 0; i < iN; ++i) {
                price[i] = dS0 * std::exp(price[i] * std::sqrt(dT) * dSigma + a);
                price[i] = std::max(price[i] - dK, 0.0) * std::exp(-dR * dT);
            }
            double result = 0;
            for (int i = 0; i < iN; ++i) {
                result += price[i];
            }
            return result / iN;
    }


    std::vector<double> MonteCarlo2(double dR,
                       double dSigma,
                       double dS0,
                       double dT,
                       unsigned long int iN,
                       const Payoff& call) {
            double a = (dR - dSigma * dSigma / 2) * dT;
            std::vector<double> price(iN);
            utils::NormalDist(price);
            for (int i = 0; i < iN; ++i) {
                price[i] = dS0 * std::exp(price[i] * std::sqrt(dT) * dSigma + a);
                price[i] = call(price[i]) * std::exp(-dR * dT);
            }
            double mean = 0;
            for (int i = 0; i < iN; ++i) {
                mean += price[i];
            }
            mean = mean / iN;
            double stdDev = 0;
            for (int i = 0; i < iN; ++i) {
                stdDev += (price[i] - mean) * (price[i] - mean);
            }
            stdDev = std::sqrt(stdDev/iN);
            std::vector<double> result(2);
            result[0] = mean;
            result[1] = stdDev;
            return result;
    }

    double callAt1(double dS) {
        double strikePrice = 1.0;
        return std::max(dS - strikePrice, 0.0);
    }














}