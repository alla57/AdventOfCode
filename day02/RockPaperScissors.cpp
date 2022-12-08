#include <iostream>
#include <fstream>

int main()
{
	std::ifstream inputFile("./RockPaperScissorsInput");
	std::string line;
	int res = 0;
	while (getline(inputFile, line))
	{
		if (line[0] == 'A')
		{
			if (line[2] == 'X')
				res +=3 + 1;
			else if (line[2] == 'Y')
				res +=6 + 2;
			else if (line[2] == 'Z')
				res +=0 + 3;
		}
		else if (line[0] == 'B')
		{
			if (line[2] == 'X')
				res +=0 + 1;
			else if (line[2] == 'Y')
				res +=3 + 2;
			else if (line[2] == 'Z')
				res +=6 + 3;
		}
		else if (line[0] == 'C')
		{
			if (line[2] == 'X')
				res +=6 + 1;
			else if (line[2] == 'Y')
				res +=0 + 2;
			else if (line[2] == 'Z')
				res +=3 + 3;
		}
	}
	std::cout << res << std::endl;
}