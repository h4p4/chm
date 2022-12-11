#include "linear_systems.h"

int main()
{
	std::vector<std::vector<float>> matrix = 
	{
		{ 3, 5, 1, 165 }, 
		{ 4, 1, 4, 136 },
		{ 6, 4, 2, 210 }
	};
	// matrix[0][0] = 3;
	// matrix[0][1] = 5;
	// matrix[0][2] = 1;
	// matrix[0][3] = 165;
	// matrix[1][0] = 4;
	// matrix[1][1] = 1;
	// matrix[1][2] = 4;
	// matrix[1][3] = 136;
	// matrix[2][0] = 6;
	// matrix[2][1] = 4;
	// matrix[2][2] = 2;
	// matrix[2][3] = 210;

	std::vector<float> gaussSolution(matrix.size());

	gauss(matrix, gaussSolution);

	for (size_t i = 0; i < gaussSolution.size(); ++i)
		std::cout << "x[" << (i + 1) << "] = " << gaussSolution[i] << std::endl;

	return 0;
}
