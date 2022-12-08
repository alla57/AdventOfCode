#include <cstdio>
#include <iostream>
#include <vector>

int main()
{
	freopen("./SupplyStacksInput", "r", stdin);
	std::vector<std::string> stacks ={"", "CZNBMWQV",
								"HZRWCB",
								"FQRJ",
								"ZSWHFNMT",
								"GFWLNQP",
								"LPW",
								"VBDRGCQJ",
								"ZQNBW",
								"HLFCGTJ"};
	std::string skip;
	getline(std::cin, skip);
	while (skip.length() > 0)
		getline(std::cin, skip);
	int nOfElement, srcStack, destStack;
	while (std::cin >> skip >> nOfElement >> skip >> srcStack >> skip >> destStack)
	{
		for (int i = 0; i < nOfElement; ++i)
		{
			stacks[destStack].push_back(stacks[srcStack].back());
			stacks[srcStack].pop_back();
		}
	}
	for (int i = 1; i < 10; ++i)
		std::cout << stacks[i].back() << " ";
	return (0);
}