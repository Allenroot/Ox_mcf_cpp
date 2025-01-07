//
// Created by allenroot on 25-1-6.
//

#include <random>
#include <valarray>
#include <src/gtest-internal-inl.h>

#include "Practical05/Practical05Exercises.hpp"
#include "../boost/numeric/ublas/lu.hpp"
#include "Utils/UtilityFunctions.hpp"

namespace exercises{

    unsigned int subtract(unsigned int a, unsigned int b){
        while (b != 0) {
            unsigned int borrow = (~a) & b;
            a = a ^ b;
            b = borrow << 1;
        }
        return a;
    }


    void swap(unsigned int & a, unsigned int & b){
        if (a != b) {
            a = a ^ b;
            b = a ^ b;
            a = a ^ b;
        }
    }

    BVector Regression(const BVector & yVals,
           const std::vector<BVector> & factors,
           const FVector & testFunctions){
        std::size_t row = yVals.size();
        std::size_t col = testFunctions.size();
        BMatrix Phi(row, col);
        for (std::size_t i = 0; i < row; i++)
        {
            for (std::size_t j = 0; j < col; j++)
            {
                Phi(i,j) = testFunctions[j](factors[i]);
            }
        }

        BMatrix Phitrans_Phi = boost::numeric::ublas::prod(boost::numeric::ublas::trans(Phi),Phi);
        boost::numeric::ublas::lu_factorize(Phitrans_Phi);
        BMatrix inv = boost::numeric::ublas::identity_matrix<double>(Phitrans_Phi.size1());
        boost::numeric::ublas::lu_substitute<const BMatrix,BMatrix>(Phitrans_Phi, inv);

        BVector coeff = boost::numeric::ublas::prod(boost::numeric::ublas::prod(inv, boost::numeric::ublas::trans(Phi)),yVals);
        return coeff;
    }

    double Projection(const BVector & factor,
          const FVector & testFunctions,
          const BVector & coefficients)
    {
        BVector x(coefficients.size());
        for (std::size_t i = 0; i < coefficients.size(); i++)
        {
            x[i] = testFunctions[i](factor);
        }
        return boost::numeric::ublas::inner_prod(coefficients, x);
    }

    EuropeanOptionPricer::EuropeanOptionPricer(const std::vector<BVector>& factorsAt0, const BVector& valuesAtT, const FVector& testFunctions)
    {
        m_TestFunctions = testFunctions;
        m_Coefficients = Regression(valuesAtT,factorsAt0,m_TestFunctions);
    }

    double EuropeanOptionPricer::operator()(const BVector& factorAt0)
    {
        return Projection(factorAt0,m_TestFunctions,m_Coefficients);
    }

    BVector MonteCarlo4(std::vector<BVector> vS0,
                double dR,
                double dSigma1,
                double dSigma2,
                double dRho,
                double dT,
                Function const& payoff)
    {
        double discount = std::exp(-dR * dT);
        BVector result(vS0.size());

        for (std::size_t i = 0; i < vS0.size(); i++)
        {
            double W1 = std::sqrt(dT) * utils::NormalDist();
            double W2 = std::sqrt(dT) * utils::NormalDist();
            double S1 = vS0[i][0] * std::exp((dR - dSigma1 * dSigma1 / 2) * dT + dSigma1 * W1 );
            double S2 = vS0[i][1] * std::exp((dR - dSigma2 * dSigma2 / 2) * dT + dSigma2 * ( dRho * W1 + std::sqrt(1 - dRho * dRho) * W2));
            BVector St(2);
            St[0] = S1;
            St[1] = S2;
            result[i] = discount * payoff(St);
        }
        return result;
    }

















}




















