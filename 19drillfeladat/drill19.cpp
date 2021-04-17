#include "std_lib_facilities.h"

template<typename T> struct S {
	
	private:

		T val;	

	public:
		S() {}
		S(T x) : val(x) {}

		T& get();
		void set(T value);

		void operator=(const T&);

		T& operator[](int n);

};

template<typename T> T& S<T>::get() {
	return val;
}

template<typename T> void S<T>::set(T value) {
	val = value;
}

template<typename T> void S<T>::operator=(const T& t)
{
	t = val;
}

template<typename T> T& S<T>::operator[](int n) {
	return val;
}

template<typename T> void read_val(T& v)
{
	cin >> v;
}

void harmas()
{
	/*S<int> ii(4);
	cout << ii.val <<endl;

	S<char> ch('h');
	cout << ch.val <<endl;

	S<double> db(4.4);
	cout << db.val <<endl;

	S<string> st("huba");
	cout << st.val <<endl;

	S<vector<int>> vti(vector<int>{1,2,3});
	for (int i=0; i<vti.val.size(); i++)
	{
		cout << vti.val[i] <<endl;
	}

	cout << st.get() << endl; 

	privát adattag miatt kikommentezve*/

}

void nyolcas()
{
	S<int> ii(4);
	cout << ii.get() <<endl;

	S<char> ch('h');
	cout << ch.get() <<endl;

	S<double> db(4.4);
	cout << db.get() <<endl;

	S<string> st("huba");
	cout << st.get() <<endl;

	S<vector<int>> vti(vector<int>{1,2,3});
	for (int i=0; i<vti.get().size(); i++)
	{
		cout << vti.get()[i] <<endl;
	}
}

void kilences()
{
	S<string> st("huba");
	cout << st.get() <<endl;
	st.set("kilencesdrill");
	cout << st.get() <<endl;
}

void tizes()
{
	 S<string> st("huba");
	 cout << st[0] << endl;
	 
}

void tizenharmas()
{
	S<int> ii;

	S<char> ch;

	S<double> db;

	S<string> st;

	read_val(ii.get());
	cout << ii.get() <<endl;
	
	read_val(ch.get());
	cout << ch.get() <<endl;
	
	read_val(db.get());
	cout << db.get() <<endl;
	
	read_val(st.get());
	cout << st.get() <<endl;
}

int main()
{
	/*cout << "Hármas feladat: \n";
	harmas(); 
	kikommentezve a privát adattag miatt*/ 
	
	cout << "Nyolcas feladat: \n";
	nyolcas();
	cout << "Kilences feladat: \n";
	kilences();
	cout << "Tizes feladat \n";
	tizes();
	cout << "Tizenharmas feladat: \n";
	tizenharmas();
}