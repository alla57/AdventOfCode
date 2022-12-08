#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
	std::ifstream inputFile("./ElvesRucksacksInput");
	std::string line;
	int res = 0;
	while (getline(inputFile, line))
	{
		for (int i = 0; i < (line.length() / 2); ++i)
		{
			for (int j = line.length() / 2; j < line.length(); ++j)
			{
				if (line[i] == line[j])
				{
					if (isupper(line[i]))
						res += line[i] - 38;
					else
						res += line[i] - 96;
					i = line.length() / 2;
					break;
				}
			}
		}
	}
	std::cout << res << std::endl;
}