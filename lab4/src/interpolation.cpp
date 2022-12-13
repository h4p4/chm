
#include "interpolation.h"

float lagrange(const std::vector<float>& x, const std::vector<float>& y, float arg)
{
	assert(x.size() == y.size());
	float polynomial = 0.f;
	for (size_t i = 0; i < x.size(); i++)
	{
		float monomial = y[i];
		for (size_t j = 0; j < x.size(); j++)
		{
			if (j == i) continue;
			monomial *= (arg - x[j]) / (x[i] - x[j]);
		}
		polynomial += monomial;
	}

	return polynomial;
}
