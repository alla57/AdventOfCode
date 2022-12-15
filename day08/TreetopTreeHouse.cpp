#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
//   problem for now is that some digit are counted twice
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
	int i = 0, j = 0;
	int x = 0, y = 0;
	int res = 0;
	while (i < forest.size())
	{
		
	}//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	std::cout << res << std::endl;
	return (0);
}