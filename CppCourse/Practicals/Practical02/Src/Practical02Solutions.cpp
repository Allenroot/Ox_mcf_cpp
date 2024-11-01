#include "Practical02/Practical02Exercises.hpp"
#include "Utils/UtilityFunctions.hpp"
#include <cmath>



namespace exercises {
    double eulerStep(double dVal,
         double dTime,
         const DVector & drivingNoise,
         const Equation & euqation) {
        return dVal + euqation[0](dTime,dVal) * drivingNoise[0] + euqation[1](dTime,dVal) * drivingNoise[1];
    }

    double milsteinStep(double dVal,
            double dTime,
            const DVector & drivingNoise,
            const Equation & euqation) {
            return dVal + euqation[0](dTime,dVal) * drivingNoise[0] + euqation[1](dTime,dVal) *
            drivingNoise[1] + 0.5 * euqation[1](dTime,dVal) * euqation[2](dTime,dVal) * (drivingNoise[1] * drivingNoise[1] - drivingNoise[0]);
    }

    DVector MonteCarlo3(double dS0,
            double dT,
            double dR,
            Equation const& equation,
            NumericalStep const& numericalStep,
            unsigned long int iNumberOfSteps,
            unsigned long int iNumberOfPaths,
            PayoffFunction const& payoffFunction) {


            std::vector<double> price(iNumberOfPaths);

            for (unsigned long int i = 0; i < iNumberOfPaths; ++i) {
                double delta_t = dT/iNumberOfSteps;
                double S_T = dS0;
                for (int i = 1; i <= iNumberOfSteps; i++) {
                    DVector noise = {delta_t, sqrt(delta_t) * utils::NormalDist()};
                    S_T = numericalStep(S_T,delta_t,noise,equation);
                };
                price[i] = payoffFunction(S_T) * std::exp(-dR * dT);
            }

            double mean = 0;
            for (int i = 0; i < iNumberOfPaths; ++i) {
                mean += price[i];
            }
            mean = mean / iNumberOfPaths;
            double stdDev = 0;
            for (int i = 0; i < iNumberOfPaths; ++i) {
                stdDev += (price[i] - mean) * (price[i] - mean);
            }
            stdDev = std::sqrt(stdDev)/iNumberOfPaths;
            std::vector<double> result(2);
            result[0] = mean;
            result[1] = stdDev;
            return result;
    }





}
//
// Created by jcong on 10/25/24.
//
