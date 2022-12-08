#include <iostream>
#include <cstdio>
#include <string>

int main()
{
	freopen("./TuningTroubleInput", "r", stdin);
	std::string line;
	getline(std::cin, line);
	int res;
	for (int i = 0; i < line.length(); ++i)
	{
		if (!(line[i] == line[i + 1] || line[i] == line[i + 2] || line[i] == line[i + 3]
		|| line[i + 1] == line[i + 2] || line[i + 1] == line[i + 3]
		|| line[i + 2] == line[i + 3]))
		{
			res = i + 4;
			break;
		}
	}
	std::cout << res;
}