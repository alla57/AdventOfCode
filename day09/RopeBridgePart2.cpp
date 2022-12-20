#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <vector>

void	getCloser(std::pair<int, int>& hPos, std::pair<int, int>& tPos)
{
	if (((hPos.first - tPos.first == 1 || hPos.first - tPos.first == -1) && (hPos.second - tPos.second > 1 || hPos.second - tPos.second < -1))
		|| ((hPos.first - tPos.first > 1 || hPos.first - tPos.first < -1) && (hPos.second - tPos.second == 1 || hPos.second - tPos.second == -1)))
	{
		if (hPos.first - tPos.first >= 1)
			++tPos.first;
		else if (hPos.first - tPos.first <= -1)
			--tPos.first;
		if (hPos.second - tPos.second >= 1)
			++tPos.second;
		else if (hPos.second - tPos.second <= -1)
			--tPos.second;
	}
	else
	{
		if (hPos.first - tPos.first > 1)
			++tPos.first;
		else if (hPos.first - tPos.first <  -1)
			--tPos.first;
		else if (hPos.second - tPos.second > 1)
			++tPos.second;
		else if (hPos.second - tPos.second < -1)
			--tPos.second;
	}
}

int main()
{
	std::ifstream inputFile("./RopeBridgeInput");
	std::pair<int, int> hPos(0, 0);
	std::vector< std::pair<int, int> > tPos(9, std::make_pair(0, 0));
	std::set< std::pair<int, int> > res;
	res.insert(tPos[8]);
	std::map< std::string, std::pair<int, int> > moves = {{"L", {-1, 0}}, {"R", {1, 0}}, {"U", {0, 1}}, {"D", {0, -1}}};
	std::string direction;
	int step;
	// int k = 0;
	while (!inputFile.eof())
	{
		// ++k;
		inputFile >> direction >> step;
		for (int i = 0; i < step; ++i)
		{
			hPos.first += moves[direction].first;
			hPos.second += moves[direction].second;
			getCloser(hPos, tPos[0]);
			for (int j = 0; j < 8; ++j)
			{
				getCloser(tPos[j], tPos[j + 1]);
			}
			res.insert(tPos[8]);
		}
	}
	for (std::set<std::pair<int, int>>::iterator it = res.begin(); it != res.end(); ++it)
		std::cout << it->first << " " << it->second << std::endl;
	return (0);
}