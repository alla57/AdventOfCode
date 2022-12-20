#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>

void	getCloser(std::pair<int, int>& hPos, std::pair<int, int>& tPos, std::set< std::pair<int, int> >& res)
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
	res.insert(tPos);
}

bool isTooFar(std::pair<int, int>& hPos, std::pair<int, int>& tPos)
{
	if (hPos.first - tPos.first > 1 || hPos.first - tPos.first <  -1)
		return (true);
	else if (hPos.second - tPos.second > 1 || hPos.second - tPos.second < -1)
		return (true);
	return (false);
}

int main()
{
	std::ifstream inputFile("./RopeBridgeInput");
	int x = 0, y = 0;
	std::pair<int, int> hPos(0, 0);
	std::pair<int, int> tPos(0, 0);
	std::set< std::pair<int, int> > res;
	res.insert(tPos);
	std::map< std::string, std::pair<int, int> > moves = {{"L", {-1, 0}}, {"R", {1, 0}}, {"U", {0, 1}}, {"D", {0, -1}}};
	std::string direction;
	int step;
	while (!inputFile.eof())
	{
		inputFile >> direction >> step;
		for (int i = 0; i < step; ++i)
		{
			hPos.first += moves[direction].first;
			hPos.second += moves[direction].second;
			if (isTooFar(hPos, tPos))
			{
				getCloser(hPos, tPos, res);
			}
		}
	}
	std::cout << res.size() << std::endl;
	return (0);
}