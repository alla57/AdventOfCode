#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main()
{
	std::ifstream inputFile("./CathodeRayTubeInput");
	int cycle = 1, x = 1, xtmp, cycleCheckpoint = 20;
	std::vector< std::pair<int, int> > xHistoric(2, std::make_pair(1, 1));
	std::string op;
	int res = 0;
	while (!inputFile.eof())
	{
		inputFile >> op;
		if (op == "addx")
		{
			inputFile >> xtmp;
			cycle += 2;
			x += xtmp;
			xHistoric[1].first = xHistoric[0].first;
			xHistoric[0].first = x;
			xHistoric[1].second = xHistoric[0].second;
			xHistoric[0].second = cycle;
		}
		else if (op == "noop")
			++cycle;
		if (cycle >= cycleCheckpoint && cycle <= 221)
		{
			if (cycle > cycleCheckpoint)
				res += cycleCheckpoint * xHistoric[1].first;
			else
				res += cycleCheckpoint * xHistoric[0].first;
			cycleCheckpoint += 40;
		}
	}
	std::cout << res << std::endl;
}
