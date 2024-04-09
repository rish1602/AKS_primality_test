#pragma once
#ifndef AKSLIBRARY_EXPORTS
#define AKSLIBRARY_API __declspec(dllexport)
#else 
#define AKSLIBRARY_API __declspec(dllimport) 
#endif

extern "C" AKSLIBRARY_API bool aks(unsigned long long number_);
extern "C" AKSLIBRARY_API unsigned long long gcd(unsigned long long a_, unsigned long long b_);
extern "C" AKSLIBRARY_API unsigned long long modPow(unsigned long long base_, unsigned long long exponent_, unsigned long long modulus_);

