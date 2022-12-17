#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <cctype>

void	getCloser(std::pair<int, int>& hPos, std::pair<int, int>& tPos, std::set< std::pair<int, int> >& res)
{
	if (((hPos.first - tPos.first == 1 || hPos.first - tPos.first == -1) && (hPos.second - tPos.second > 1 || hPos.second - tPos.second < -1))
		|| ((hPos.first - tPos.first > 1 || hPos.first - tPos.first < -1) && (hPos.second - tPos.second == 1 || hPos.second - tPos.second == -1)))
	{
		if (hPos.first - tPos.first >= 1)
			++tPos.first;
		else if (hPos.first - tPos.first <= -1)
			--tPos.first;
		res.insert(tPos);
		if (hPos.second - tPos.second >= 1)
			++tPos.second;
		else if (hPos.second - tPos.second < -1)
			--tPos.second;
		res.insert(tPos);
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
		res.insert(tPos);
	}
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
	// freopen("./RopeBridgeInput", "w", stdin);
	int x = 0, y = 0;
	std::pair<int, int> hPos(0, 0);
	std::pair<int, int> tPos(0, 0);
	std::set< std::pair<int, int> > res;
	res.insert(tPos);
	std::map< std::string, std::pair<int, int> > moves = {{"L", {-1, 0}}, {"R", {1, 0}}, {"U", {0, 1}}, {"D", {0, -1}}};
	std::string direction;
	int step;
	int k = 0;
	while (!inputFile.eof())
	{
		++k;
		inputFile >> direction >> step;
		std::cout << "STEP " << k << std::endl;
		for (int i = 0; i < step; ++i)
		{
			hPos.first += moves[direction].first;
			hPos.second += moves[direction].second;
			if (isTooFar(hPos, tPos))
			{
				getCloser(hPos, tPos, res);
			}
			std::cout << "hPos {" << hPos.first << ", " << hPos.second << "}" << std::endl;
			std::cout << "tPos {" << tPos.first << ", " << tPos.second << "}" << std::endl;
			std::cout << "moves: " << res.size() << std::endl;
			std::cout << std::endl;
		}
	}
	std::cout << res.size() << std::endl;
	return (0);
}