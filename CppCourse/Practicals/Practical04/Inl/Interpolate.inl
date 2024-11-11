
#include <set>

namespace exercises {

template<typename PreOp, typename PostOp>
double Interpolate<PreOp,PostOp>::operator()(double dX) const
{
    if (dX < m_xVals.front()) {
        return PostOp()(m_yVals.front(),dX);
    } else if (dX > m_xVals.back()) {
        return PostOp()(m_yVals.back(),dX);
    } else {
        auto Dx_i = std::lower_bound(m_xVals.begin(),m_xVals.end(),dX);
        int position_i = std::distance(m_xVals.begin(),Dx_i);
        double y1 = m_yVals[position_i - 1];
        double y2 = m_yVals[position_i];
        double x1 = m_xVals[position_i - 1];
        double x2 = m_xVals[position_i];

        double z = y1 + (y2 - y1) * (dX - x1) / (x2 - x1);
        return PostOp()(z, dX);
    }
}


}
