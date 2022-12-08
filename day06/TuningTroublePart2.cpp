#include <iostream>
#include <cstdio>
#include <string>

bool isDuplicate(std::string line)
{
	for (int i = 0; i < line.length(); ++i)
	{
		for (int j = i + 1; j < line.length(); ++j)
		{
			if (line[i] == line[j])
				return (true);
		}
	}
	return (false);
}

int main()
{
	freopen("./TuningTroubleInput", "r", stdin);
	std::string line;
	getline(std::cin, line);
	int res;
	for (int i = 0; i < line.length(); ++i)
	{
		if (!isDuplicate(line.substr(i, 14)))
		{
		std::cout << line.substr(i, 14) << std::endl;
			res = i + 14;
			break;
		}
	}
	std::cout << res;
}