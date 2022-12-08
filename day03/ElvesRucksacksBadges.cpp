#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
	std::ifstream inputFile("./ElvesRucksacksInput");
	std::string line1;
	std::string line2;
	std::string line3;
	int res = 0;
	char c;
	bool found;
	while (!inputFile.eof())
	{
		getline(inputFile, line1);
		getline(inputFile, line2);
		getline(inputFile, line3);
		int i = 0;
		found = false;
		while (found == false)
		{
			c = line1[i];
			if (line2.find(c) != std::string::npos)
			{
				if (line3.find(c) != std::string::npos)
					found = true;
				else
					++i;
			}
			else
				++i;
		}
		if (isupper(c))
			res += c - 38;
		else
			res += c - 96;
	}
	std::cout << res << std::endl;
}