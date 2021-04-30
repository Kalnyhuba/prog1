#include <iostream>
#include <algorithm>
#include <map>

//5.feladat

void read(std::map<std::string, int>& msi)
{
	std::pair<std::string, int> pairs;
	std::map<std::string, int>::iterator q = msi.begin();
	while(std::cin >> pairs.first >> pairs.second)
	{
		msi.insert(q, pairs);
	}
}

int sum(std::map<std::string, int> map)
{
	int sum = 0;
	for (std::map<std::string, int>::iterator q = map.begin(); q != map.end(); q++)
	{
		sum += (*q).second;
	}
	return sum;
}

int main()
{
	//1.feladat

	std::map<std::string, int> msi;

	//2.feladat

	msi["prog1"] = 10;
	msi["prog2"] = 20;
	msi["prog3"] = 30;
	msi["prog4"] = 40;
	msi["prog5"] = 50;
	msi["prog6"] = 60;
	msi["prog7"] = 70;
	msi["prog8"] = 80;
	msi["prog9"] = 90;
	msi["prog10"] = 100;

	//3.feladat

	for (const auto& e : msi)
	{
		std::cout << e.first << " " << e.second << std::endl;
	}

	//4.feladat

	msi.erase(msi.begin(), msi.end());

	//6.feladat

	read(msi);

	//7.feladat

	for (const auto& e : msi)
	{
		std::cout << e.first << " " << e.second << std::endl;
	}

	//8.feladat

	std::cout << sum(msi) << std::endl;
	 
	//9.feladat

	std::map<int, std::string> mis;

	//10.feladat

	for (auto e : msi)
	{
		mis[e.second] = e.first;
	}

	//11.feladat

	for (const auto& e : mis)
	{
		std::cout << e.first << " " << e.second << std::endl;
	}

	return 0;
}