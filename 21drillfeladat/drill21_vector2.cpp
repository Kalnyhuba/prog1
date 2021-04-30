#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <numeric>

int main()
{
	//1.feladat

	const std::string file = "doublevector.txt";
	std::ifstream ifstr(file.c_str());

	std::vector<double> vd;
	double d;

	while(ifstr >> d) vd.push_back(d);

	//2.feladat

	for (const auto& e : vd)
	{
		std::cout << e << std::endl;
	}

	//3.feladat

	std::vector<int> vi(vd.size());

	copy(vd.begin(), vd.end(), vi.begin());

	//4.feladat

	std::cout << "Párok: " << std::endl;

	for (int i = 0; i < vd.size(); i++)
	{
		std::cout << vd[i] << " " << vi[i] << std::endl;
	}

	//5.feladat

	double sum = 0;
	sum = accumulate(vd.begin(), vd.end(), sum);

	std::cout << "Szumma: " << sum << std::endl;

	//6.feladat

	int sumint = 0;
	sumint = accumulate(vi.begin(), vi.end(), sumint);

	std::cout << "Szummakülönbség a két vektor között: " << sum - sumint << std::endl;

	//7.feladat

	reverse(vd.begin(), vd.end());

	for (const auto& e : vd)
	{
		std::cout << e << std::endl;
	}

	//8.feladat

	double mean = sum / vd.size();

	std::cout << "Double vektor átlaga: " << mean << std::endl;

	//9.feladat

	//std::vector<double> vd2

	//10.feladat

	sort(vd.begin(), vd.end());

	for (const auto& e : vd)
	{
		std::cout << e << std::endl;
	}

	return 0;
}