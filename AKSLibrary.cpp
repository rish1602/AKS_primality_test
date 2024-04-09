#include"pch.h"
#include"AKSLibrary.h"
#include<cmath>


bool aks(unsigned long long number_)
{
	unsigned long long r_ = static_cast<unsigned long long>(sqrt(number_ * log(number_)));
	for (unsigned long long a_ = 1; a_ <= r_; ++a_)
	{
		if (gcd(number_,a_) > 1) return false;

		if (modPow(a_, number_, number_) != a_) return false;

	}
	return true;
}

unsigned long long gcd(unsigned long long a_, unsigned long long b_)
{
	if (b_ == 0) return a_;
	return gcd(b_, a_%b_);
}

unsigned long long modPow(unsigned long long base_, unsigned long long exponent_, unsigned long long modulus_)
{
	unsigned long long result_ = 1;
	while (exponent_ > 0)
	{
		if (exponent_ % 2 == 1) result_ = (static_cast<unsigned long long>(result_) * base_) % modulus_;
		base_ = (static_cast<unsigned long long>(base_) * base_) % modulus_;
		exponent_ /= 2;
	}
	return result_; 
}




