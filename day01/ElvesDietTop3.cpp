#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inputFile("./ElvesDietInput");
	std::string line;
	int elf1, elf2, elf3;
	elf1 = elf2 = elf3 = 0;
	int foodItemCalories = 0;
	while (std::getline(inputFile, line) )
	{
		if (line.empty())
		{
			if (foodItemCalories > elf3)
			{
				if (foodItemCalories > elf2)
				{
					if (foodItemCalories > elf1)
					{
						elf3 = elf2;
						elf2 = elf1;
						elf1 = foodItemCalories;
					}
					else
					{
						elf3 = elf2;
						elf2 = foodItemCalories;
					}
				}
				else
					elf3 = foodItemCalories;
			}
			foodItemCalories = 0;
		}
		else
			foodItemCalories += std::stoi(line);
	}
	std::cout << elf1 + elf2 + elf3 << std::endl;
	return (0);
}