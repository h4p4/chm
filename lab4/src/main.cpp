
#include <iostream>
#include <cmath>
#include "interpolation.h"
#include <fstream>

int readFile(const std::string&, std::vector<float>&, std::vector<float>&);

int writeFile(const std::string&, const std::vector<float>&, const std::vector<float>&);

int main()
{
	using namespace std;

	vector<float> inputX, inputY, outputX, outputY;
    auto f = [=](float x)
	{
		return std::cos(x + (std::pow(std::cos(x), 3.f)));
	};
    float a = 0.f, b = 2.f; // интервал
    float s = (a + b) / 3; // шаг
    for (float x = a; x <= b; x += s)
    {
        inputX.push_back(x);
        inputY.push_back(f(x));
    }
    if (writeFile("src/input.txt", inputX, inputY))
	{
		cout << "Error";
		return 1;
	}
	inputX.clear();
	inputY.clear();

	if (readFile("src/input.txt", inputX, inputY))
	{
		cout << "Error";
		return 1;
	}

	float step = 0.1f; // шаг
	// 0, 0.1, 0.2, 0.3, ..., 2
	for (float x = inputX.front(); x <= inputX.back() + step; x += step)
	{
		outputX.push_back(x);
		outputY.push_back(lagrange(inputX, inputY, x));
		// std::cout << "L(" << x << ") = " << outputY.back() << std::endl;
	}

	if (writeFile("src/output.txt", outputX, outputY))
	{
		cout << "Error";
		return 1;
	}

	return 0;
}



int readFile(const std::string& filename, std::vector<float>& x, std::vector<float>& y)
{
	using namespace std;

	fstream input(filename, fstream::in);
	if (input.is_open())
	{
		float pointX = 0, pointY = 0;
		while (!input.eof())
		{
			input >> pointX >> pointY;
			x.push_back(pointX);
			y.push_back(pointY);
		}
	}
	else
	{
		input.close();
		return 1;
	}

	input.close();
	return 0;
}



int writeFile(const std::string& filename, const std::vector<float>& x, const std::vector<float>& y)
{
	using namespace std;

	assert(x.size() == y.size());

	fstream output(filename, fstream::out);
	if (output.is_open())
	{
		for (size_t i = 0; i < x.size(); ++i)
		{
			if (filename == "src/output.txt")
				output << "(" << x[i] << "; " << y[i] << ") ";
			else
			{
				if (i == x.size() - 1)
					output << x[i] << " " << y[i];
				else 
					output << x[i] << " " << y[i] << "\n";
			}
		}
	}
	else
	{
		output.close();
		return 1;
	}

	output.close();
	return 0;
}
