#include "Utils.h"

float ToRadians(float angle)
{	
	return angle * M_PIl / 180.0f;
}

float RandomRange(float range_from, float range_to)
{
	std::random_device  rand_dev;
	std::mt19937 generator(rand_dev());
	std::uniform_int_distribution<int> distr(range_from, range_to);
	return distr(generator);
	
}
