#include "stdafx.h"
#include "SimpleFunction.h"

template<typename T>
T RandomGeneratoer(T min, T max)
{
	//½¬¹Ù
	return T();
}

template<>
int RandomGeneratoer<int>(int min, int max)
{
	random_device rd;
	mt19937_64 result(rd());

	uniform_int_distribution<int> range(min, max);

	return range(result);
}

template<>
double RandomGeneratoer<double>(double min, double max)
{
	random_device rd;
	mt19937_64 result(rd());

	uniform_real_distribution<double> range(min, max);

	return range(result);
}