//g++ drill15_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_2 `fltk-config --ldflags --use-images`

#include <iostream>
#include "std_lib_facilities.h"

class Person
{
	private:
		string first_name;
		string second_name;
		int age;

	public:
		Person()
		{

		}

		Person(string first_name1, string second_name1, int age1)
		{
			string name1 = first_name1 + second_name1;
			for (int i = 0; i < name1.length(); i++)
			{
				if (name1[i] == ';' || name1[i] == ':' || name1[i] == '"' || name1[i] == '\'' ||
					name1[i] == '[' || name1[i] == ']' || name1[i] == '*' || name1[i] == '&' ||
					name1[i] == '^' || name1[i] == '%' || name1[i] == '$' || name1[i] == '#' ||
					name1[i] == '@' || name1[i] == '!')
					error("Invalid name.");
			}
			if (age1 < 0 || age1 >= 150)
				error("Invalid age.");
			first_name = first_name1;
			second_name = second_name1;
			age = age1;
		}

		const string get_first_name()
		{
			return first_name;
		}

		const string get_second_name()
		{
			return second_name;
		}

		const string get_name()
		{
			return first_name + " " + second_name;
		}

		const int get_age()
		{
			return age;
		}

		void set_first_name(string name)
		{
			first_name = name;
		}

		void set_second_name(string name)
		{
			second_name = name;
		}

		void set_age(int age1)
		{
			age = age1;
		}
};

ostream& operator<<(ostream& os, Person p)
{
	return os << p.get_name() << ", " << p.get_age();
}

istream& operator>>(istream& is, Person& p)
{
	string first_name;
	string second_name;
	int age;
	is >> first_name >> second_name >> age;
	p.set_first_name(first_name);
	p.set_second_name(second_name);
	p.set_age(age);
	return is;
}

int main()
{
	//Person p = { "Goofy", 63 };
	Person p = { "Kálny", "Huba", 23};
	cout << p << endl;
	cin >> p;
	cout << p << endl;
	vector<Person> v;
	for (int i = 0; i < 2; i++)
	{
		cin >> p;
		v.push_back(p);
		cout << v[i] << endl;
	}
}