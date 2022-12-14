#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

bool isCovered(std::vector< std::vector<int> >& forest, int i, int j)
{
	int x = i, y = j;
	while (--y >= 0)
	{
		if (forest[x][y] >= forest[i][j])
			break;
	}
	if (y == -1)
		return (false);
	y = j;
	while (++y < forest[i].size())
	{
		if (forest[x][y] >= forest[i][j])
			break;
	}
	if (y == forest[i].size())
		return (false);
	y = j;
	while (--x >= 0)
	{
		if (forest[x][y] >= forest[i][j])
			break;
	}
	if (x == -1)
		return (false);
	x = i;
	while (++x < forest.size())
	{
		if (forest[x][y] >= forest[i][j])
			break;
	}
	if (x == forest.size())
		return (false);
	return (true);
}

int main()
{
	std::ifstream inputFile("./TreetopTreeHouseInput");
	char buf[1];
	std::vector< std::vector<int> > forest;
	std::vector<int> tmp;
	while (1)
	{
		inputFile.read(buf, 1);
		if (inputFile.eof() || !isdigit(buf[0]))
		{
			forest.push_back(tmp);
			tmp.clear();
			if (inputFile.eof())
				break;
		}
		else
		{
			tmp.push_back(atoi(buf));
		}
	}
	int res = 0;
	for (int i = 0; i < forest.size(); ++i)
	{
		for (int j = 0; j < forest[i].size(); ++j)
		{
			if (i == 0 || i == forest.size() - 1 || j == 0 || j == forest[i].size() || !isCovered(forest, i, j))
				++res;
		}
	}
	std::cout << res << std::endl;
	return (0);
}