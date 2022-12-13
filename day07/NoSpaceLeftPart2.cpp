#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<cctype>
#include<vector>
#include<algorithm>

void	parentPath(std::string& path)
{
	if (path.length() == 1)
		return ;
	if (path.substr(path.length() - 1) == "/")
		path.pop_back();
	while (path.substr(path.length() - 1) != "/")
		path.pop_back();
}

void	refreshPathSizeValue(std::string path, size_t fileSize, std::map<std::string, size_t>& pathSize){
	while (path.length() > 1)
	{
		pathSize[path] += fileSize;
		parentPath(path);
	}
	pathSize[path] += fileSize;
}

int main()
{
	std::ifstream inputFile("./NoSpaceLeftInput");
	std::string line;
	std::string currentPath("/");
	std::map<std::string, size_t> pathSize;
	pathSize.insert(std::pair<std::string, size_t>(currentPath, 0));
	while (getline(inputFile, line))
	{
		if (line[0] == '$' && line.substr(2, 2) == "cd")
		{
			if (line.substr(5) == "/")
				currentPath = "/";
			else if (line.substr(5) == "..")
				parentPath(currentPath);
			else
			{
				currentPath += line.substr(5) + "/";
				pathSize.insert(std::pair<std::string, size_t>(currentPath, 0));
			}
		}
		else if (line[0] != '$')
		{
			if (isdigit(line[0]))
				refreshPathSizeValue(currentPath, stoi(line), pathSize);
		}
	}
	size_t rootSize = pathSize["/"];
	size_t sizeToRemove = rootSize - 40000000;
	size_t res = 0;
	std::map<std::string, size_t>::iterator it;
	it = pathSize.begin();
	std::vector<size_t> vec;
	while (it != pathSize.end())
	{
		if (it->second >= sizeToRemove)
			vec.push_back(it->second);
		++it;
	}
	std::sort(vec.begin(), vec.end());
	std::cout << *vec.begin() << std::endl;
}