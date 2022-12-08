#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	std::ifstream inputFile("./CampCleanupInput");
	int firstSection1, lastSection1;
	int firstSection2, lastSection2;
	char toSkip;
	int res = 0;
	while (!inputFile.eof())
	{
		inputFile >> firstSection1 >> lastSection1;
		inputFile >> toSkip;
		inputFile >> firstSection2 >> lastSection2;
		if (firstSection2 >= firstSection1 && firstSection2 <= abs(lastSection1)
		|| firstSection1 >= firstSection2 && firstSection1 <= abs(lastSection2))
			++res;
	}
	std::cout << res << std::endl;
	return (0);
}