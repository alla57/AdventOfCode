#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inputFile("./ElvesDietInput");
	std::string line;
	int res = 0;
	int foodItemCalories = 0;
	while (std::getline(inputFile, line) )
	{
		if (line.empty())
		{
			if (foodItemCalories > res)
				res = foodItemCalories;
			foodItemCalories = 0;
		}
		else
			foodItemCalories += std::stoi(line);
	}
	std::cout << res << std::endl;
	return (0);
}