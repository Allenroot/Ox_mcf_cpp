#include "Practical02/ComplexNumber.hpp"


ComplexNumber::ComplexNumber() : dRe_(0.0), dIm_(0.0) {}

ComplexNumber::ComplexNumber(double dReArg, double dImArg) 
	: dRe_(dReArg), dIm_(dImArg) {}

ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & cnArg)
{
	dRe_+=cnArg.dRe_;
	dIm_+=cnArg.dIm_;
	return *this;
}

ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & cnArg)
{
	dRe_-=cnArg.dRe_;
	dIm_-=cnArg.dIm_;
	return *this;
}

ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & cnArg)
{
	dRe_ = dRe_ * cnArg.dRe_ - dIm_ * cnArg.dIm_;
	dIm_ = dRe_ * cnArg.dIm_ + dIm_ * cnArg.dRe_;
	return *this;
}
ComplexNumber & ComplexNumber::operator/=(const ComplexNumber & cnArg)
{
	double denominator = cnArg.dRe_* cnArg.dRe_ + cnArg.dIm_* cnArg.dIm_;
	dRe_ = (dRe_ * cnArg.dRe_ + dIm_ * cnArg.dIm_)/denominator;
	dIm_ = (dIm_ * cnArg.dRe_ - dRe_ * cnArg.dIm_)/denominator;
	return *this;
}

ComplexNumber & ComplexNumber::operator+=(const double & realPart) {
	dRe_+=realPart;
	return *this;
}
ComplexNumber & ComplexNumber::operator-=(const double & realPart) {
	dRe_-=realPart;
	return *this;
}
ComplexNumber & ComplexNumber::operator*=(const double & realPart) {
	dRe_*=realPart;
	return *this;
}
ComplexNumber & ComplexNumber::operator/=(const double & realPart) {
	dRe_/=realPart;
	return *this;
}

std::ostream & ComplexNumber::print(std::ostream & os) const
{
	return os << "(" << dRe_ << ", " << dIm_ << "i)";
}


//non-members
ComplexNumber operator+(const ComplexNumber & Arg1,
			const ComplexNumber & Arg2)
{
	ComplexNumber Res(Arg1);
	return Res+=Arg2;
}


ComplexNumber operator-(const ComplexNumber & Arg1,const ComplexNumber & Arg2) {
	ComplexNumber Res(Arg1);
	return Res-=Arg2;
}
ComplexNumber operator*(const ComplexNumber & Arg1,const ComplexNumber & Arg2) {
	ComplexNumber Res(Arg1);
	return Res*=Arg2;
}
ComplexNumber operator/(const ComplexNumber & Arg1,const ComplexNumber & Arg2) {
	ComplexNumber Res(Arg1);
	return Res/=Arg2;
}

ComplexNumber operator+(const ComplexNumber & cnArg,const double & realPart) {
	ComplexNumber Res(cnArg);
	return Res+=realPart;
}
ComplexNumber operator-(const ComplexNumber & cnArg,const double & realPart) {
	ComplexNumber Res(cnArg);
	return Res-=realPart;
}
ComplexNumber operator*(const ComplexNumber & cnArg,const double & realPart) {
	ComplexNumber Res(cnArg);
	return Res*=realPart;
}
ComplexNumber operator/(const ComplexNumber & cnArg,const double & realPart) {
	ComplexNumber Res(cnArg);
	return Res/=realPart;
}

ComplexNumber operator+(const double & realPart,const ComplexNumber & cnArg) {
	return cnArg+realPart;
}
ComplexNumber operator-(const double & realPart,const ComplexNumber & cnArg) {
	return cnArg-realPart;
}
ComplexNumber operator*(const double & realPart,const ComplexNumber & cnArg) {
	return cnArg*realPart;
}
ComplexNumber operator/(const double & realPart,const ComplexNumber & cnAgr) {
	return cnAgr/realPart;
}

std::ostream & operator<<(std::ostream & os, const ComplexNumber & cnArg)
{
	return cnArg.print(os);
}

