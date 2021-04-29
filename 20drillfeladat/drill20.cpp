#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

//6.feladat

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		f1++;
		f2++;
	}
	return f2;
}


int main()
{
	//1.feladat

	int int_array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//2.feladat

	std::vector<int> vi{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//3.feladat

	std::list<int> li{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//4.feladat

	int int_array2[10];
	std::copy( int_array, int_array + 10, int_array2 );

	std::vector<int> vi2 = vi;

	std::list<int> li2 = li;

	//5.feladat

	for (int i = 0; i < 10; i++)
	{
		int_array[i] += 2;
	}

	for (std::vector<int>::iterator p = vi.begin(); p != vi.end(); p++ )
	{
		*p += 3;
	}

	for (std::list<int>::iterator q = li.begin(); q != li.end(); q++)
	{
		*q += 5;
	}

	//7.feladat

	my_copy(int_array, int_array + 10, vi.begin());

	my_copy(li.begin(), li.end(), int_array);

	//8.feladat

	std::vector<int>::iterator p = std::find(vi.begin(), vi.end(), 3);
	if (p != vi.end())
	{
		std::cout << std::distance(vi.begin(), p) << std::endl;
	}

	std::list<int>::iterator q = std::find(li.begin(), li.end(), 27);
	if (q != li.end())
	{
		std::cout << std::distance(li.begin(), q) << std::endl;
	}


	return 0;
}
