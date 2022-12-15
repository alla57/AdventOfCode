#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <stdlib.h>

int sight(std::vector< std::vector<int> >& forest, int i, int j)
{
	int x = i, y = j;
	int sight = 0, final_sight;
	//left
	for (y = j - 1; y >= 0 || y == j - 1; --y)
	{
		++sight;
		if (forest[x][y] >= forest[i][j])
			break;
	}
	final_sight = sight;
	sight = 0;
	//right
	for (y = j + 1; y < forest[i].size() || y == j + 1; ++y)
	{
		++sight;
		if (forest[x][y] >= forest[i][j])
			break;
	}
	final_sight *= sight;
	sight = 0;
	//up
	y = j;
	for (x = i - 1; x >= 0 || x == i - 1; --x)
	{
		++sight;
		if (forest[x][y] >= forest[i][j])
			break;
	}
	final_sight *= sight;
	sight = 0;
	//down
	for (x = i + 1; x < forest.size() || x == i + 1; ++x)
	{
		++sight;
		if (forest[x][y] >= forest[i][j])
			break;
	}
	final_sight *= sight;
	return (final_sight);
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
	std::vector<int> res;
	for (int i = 0; i < forest.size(); ++i)
	{
		for (int j = 0; j < forest[i].size(); ++j)
		{
			if (i != 0 && i != forest.size() - 1 && j != 0 && j != forest[i].size() - 1)
				res.push_back(sight(forest, i, j));
		}
	}
	std::sort(res.begin(), res.end());
	std::cout << *(res.end() - 1) << std::endl;
	return (0);
}