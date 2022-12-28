#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <cctype>

int main()
{
	freopen("./out.txt", "w", stdout);
	std::ifstream inputFile("./CathodeRayTubeInput");
	int cycle = 0, x = 1, xtmp, cycleCheckpoint = 40;
	std::string op;
	int crt = cycle;
	while (!inputFile.eof())
	{
		inputFile >> op;
		if (op == "addx")
		{
			inputFile >> xtmp;
			for (int i = 0; i < 2; ++i)
			{
				++cycle;
				if (abs(x - crt) <= 1)
					std::cout << "#";
				else
					std::cout << ".";
				if (cycle % cycleCheckpoint == 0)
				{
					std::cout << std::endl;
					crt = 1;
				}
				++crt;
			}
			x += xtmp;
		}
		else if (op == "noop")
		{
			++cycle;
			if (abs(x - crt) <= 1)
				std::cout << "#";
			else
				std::cout << ".";
			if (cycle % cycleCheckpoint == 0)
			{
				std::cout << std::endl;
				crt = 1;
			}
			++crt;
		}
	}
}
