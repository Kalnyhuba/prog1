#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>

struct Item
{
	std::string name;
	int iid;
	double value;

	Item() : name(), iid(0), value(0) {}
	Item(std::string n, int i, double val) : name(n), iid(i), value(val) {}
};

struct sort_by_name
{
	bool operator()(const Item& p, const Item& q) const
	{
		return p.name < q.name;
	}
};

struct sort_by_iid
{
	bool operator()(const Item& p, const Item& q) const
	{
		return p.iid < q.iid;
	}
};

struct sort_by_value
{
	bool operator()(const Item& p, const Item& q) const
	{
		return p.value > q.value;
	}
};

void printout(std::vector<Item>& v)
{
	for (std::vector<Item>::iterator p = v.begin(); p != v.end(); p++)
	{
		std::cout << (*p).name << " " << (*p).iid << " " << (*p).value << std::endl;
	}
}

void printout2(std::list<Item>& l)
{
	for (std::list<Item>::iterator q = l.begin(); q != l.end(); q++)
	{
		std::cout << (*q).name << " " << (*q).iid << " " << (*q).value << std::endl;
	}
}

std::vector<Item>& string_erase(std::vector<Item>& v, std::string n)
{
	for (std::vector<Item>::iterator p = v.begin(); p != v.end(); p++)
	{
		if ((*p).name == n)
		{
			v.erase(p);
			return v;
		}
	}
}

std::vector<Item>& int_erase(std::vector<Item> v, int i)
{
	for (std::vector<Item>::iterator q = v.begin(); q != v.end(); q++)
	{
		if ((*q).iid == i)
		{
			v.erase(q);
			return v;
		}
	}
}

int main()
{
	//1.feladat

	std::string s;
	int i = 0;
	double d = 0;
	Item m;
	std::vector<Item> vi;

	std::ifstream ifs("vectorlist.txt");

	while (ifs >> s >> i >> d)
	{
		m.name = s;
		m.iid = i;
		m.value = d;
		vi.push_back(m);
	}
	ifs.close();
	printout(vi);

	//2.feladat

	std::sort(vi.begin(), vi.end(), [](const Item& p, const Item& q) {return p.name < q.name; });
	printout(vi);

	//3.feladat

	std::sort(vi.begin(), vi.end(), [](const Item& p, const Item& q) {return p.iid < q.iid; });
	printout(vi);

	//4.feladat

	std::sort(vi.begin(), vi.end(), [](const Item& p, const Item& q) {return p.value > q.value; });
	printout(vi);

	//5.feladat

	vi.insert(vi.end(), Item{"horse shoe", 99, 12.34});
	vi.insert(vi.end(), Item{"Canon S400", 9988, 499.95});
	printout(vi);

	//6.feladat

	string_erase(vi, "Programozás");
	string_erase(vi, "Programozás4");
	printout(vi);

	//7.feladat

	int_erase(vi, 60);
	int_erase(vi, 90);
	printout(vi);

	//Ugyanezek a feladatok csak listára nézve

	std::list<Item> l;
	std::ifstream ifs("vectorlist.txt");
	while(ifs >> s >> i >> d)
		 {
		m.name = s;
		m.iid = i;
		m.value = d;
		l.push_back(m);
		 }

	ifs.close();
	printout2(l);

	std::sort(l.begin(), l.end(), [](const Item& p, const Item& q) {return p.name < q.name; });
	printout(l);

	std::sort(l.begin(), l.end(), [](const Item& p, const Item& q) {return p.iid < q.iid; });
	printout(l);

	std::sort(l.begin(), l.end(), [](const Item& p, const Item& q) {return p.value > q.value; });
	printout(l);


	l.insert(l.end(), Item{"horse shoe", 99, 12.34});
	l.insert(l.end(), Item{"Canon S400", 9988, 499.95});
	printout(l);

	return 0;
}