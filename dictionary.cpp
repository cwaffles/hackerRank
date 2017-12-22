//https://www.hackerrank.com/challenges/30-dictionaries-and-maps/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	scanf("%i", &n);
	
	char name[100];
	long int phone;
	std::map<std::string, long int> dict;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%s %li", name, &phone);
		dict[name] = phone;
	}
	
	int status = scanf("%s", name);
	while(status != EOF)
	{
		if(dict.count(name) == 0)
		{
			std::cout << "Not found\n";
		}
		else
		{
			std::cout << name << '=' << dict[name] << '\n';
		}
		status = scanf("%s", name);
//		std::cout << "i=" << j << '\n';
	}
}
