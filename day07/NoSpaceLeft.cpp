#include<iostream>
#include<string>
#include<cstdio>
#include<list>
#include<vector>

struct myList;

struct myList{
	std::list<myList> *one;
	std::vector<int> vec;
}

int main()
{
}