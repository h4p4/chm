#include "linear_systems.h"
#include <iomanip>

void print(const std::vector<std::vector<float>>& a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[i].size(); j++)
		{
			std::cout << std::setw(10) << a[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void gauss(const std::vector<std::vector<float>>& matrix_, std::vector<float>& solution)
{
	std::vector<std::vector<float>> a(matrix_);
	std::vector<float>& x(solution);
	size_t n = a.size();
	for (size_t k = 0; k < n; k++)
	{
		float t = a[k][k];
		for (size_t j = n; j != std::numeric_limits<size_t>::max(); --j)
		{
			a[k][j] /= t;
			for (size_t i = n - 1; i > k; --i)
				a[i][j] -= a[k][j] * a[i][k];
		}
	}
	x[n - 1] = a[n - 1][n];
	for (size_t k = n - 2; k != std::numeric_limits<size_t>::max(); --k)
	{
		x[k] = a[k][n];
		float s = 0;
		for (size_t j = k + 1; j < n; j++)
			s += a[k][j] * x[j];
		x[k] -= s;
	}
	// print(matrix_);
	// print(a);
}
