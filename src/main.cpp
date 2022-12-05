
#include <iostream>
#include <cmath>
#include <Equations/equations.hpp>
int main()
{
	// f(x)
	auto f = [=](float x)
	{
		return 30 * cosf(0.31f * x + 0.7f);
	};
	// f'(x)
	auto fd = [=](float x)
	{
		return -9.3f * sinf(0.31f * x + 0.7f);
	};

	float a = 0, b = 5;
	float sp = 4;

	float xDichotomy = dichotomy(f, a, b);
	float xNewton = newton(f, fd, sp);
	float xBruteForce = bruteForce(f, a, b);

	std::cout << "(Dichotomy)x = " << xDichotomy << std::endl;
	std::cout << "(Newton)x = " << xNewton << std::endl;
	std::cout << "(Brute force)x = " << xBruteForce << std::endl;

	return 0;
}
