#include "Practical04/BinaryOperators.hpp"
#include <cmath>
#include <complex>
#include <valarray>
//
// Created by jcong on 11/11/24.
//


double exercises::DF2Yield::operator()(const double dDiscountFactor, const double dTimeToMaturity) const {
        return - std::log(dDiscountFactor) / dTimeToMaturity;
    }

double exercises::Yield2DF::operator()(const double dYield, const double dTimeToMaturity) const {
        return std::exp( - dYield * dTimeToMaturity );
    }

double exercises::DF2Libor::operator()(const double dDiscountFactor, const double dTimeToMaturity) const {
        return (1/dDiscountFactor - 1)/dTimeToMaturity;
    }

double exercises::Libor2DF::operator()(const double dLibor, const double dTimeToMaturity) const {
        return 1/(1 + dLibor * dTimeToMaturity);
    }
