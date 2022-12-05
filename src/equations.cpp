
#include <Equations/equations.hpp>

float dichotomy(std::function<float(float)> f, float a, float b, float epsilon)
{
	float x = 0, y = 0;
	do
	{
		x = (a + b) / 2;
		y = f(x);
		if (f(a) * y < 0)
			b = x;
		else 
			a = x;		
	} while (std::abs(y) > epsilon);
	
	return x;
}

float newton(std::function<float(float)> f, std::function<float(float)> fd, float x, float epsilon)
{
	do
	{
		x -= f(x) / fd(x);
	} while (std::abs(f(x)) > epsilon);
	
	return x;
}

float bruteForce(std::function<float(float)> f, float a, float b, float step)
{
	float xMin = a, y;
	float yMinAbs = std::abs(f(a));
	for (float x = a + step; x < b; x += step)
	{
		y = std::abs(f(x));
		if (y < yMinAbs)
		{
			xMin = x;
			yMinAbs = y;
		}
	}
	return xMin;
}
