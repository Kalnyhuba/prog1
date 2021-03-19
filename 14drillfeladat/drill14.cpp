#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"


class B1 {

	public:
			virtual void vf() { cout << "B1 :: vf()" << endl; };
			void f() { cout << "B1 :: f()" << endl; };
			virtual void pvf() {};

};

class D1 : public B1 {

	public:
			void vf() override { cout << "D1 :: vf()" << endl; };
			void f() { cout << "D1 :: f()" << endl; };
			void pvf() override { cout << "D1 :: pvf()" << endl; };

};

class D2 : public D1 {

	public:
			void pvf() override { cout << "D2 :: pvf()" << endl; };
};

class B2 {

	public:
			virtual void pvf() {};

};

class D21 : public B2 {

	public:
			string s = "14drill";
			void pvf() override { cout << s << endl; };

};

class D22 : public B2 {

	public:
			int i = 14;
			void pvf() override { cout << i << endl; };

};

void f(B2& refarg) {

		refarg.pvf();
}

int main()
{
	
	//1-es pont

	B1 b1obj;
	b1obj.vf();
	b1obj.f();
	cout << endl;

	//2-es pont

	D1 d1obj;
	d1obj.vf();
	d1obj.f();
	cout << endl;

	//3-as pont

	B1& brefobj=d1obj;
	brefobj.vf();
	brefobj.f();
	cout << endl;

	//5-ös pont

	b1obj.pvf();
	d1obj.pvf();
	brefobj.pvf();
	cout << endl;

	//6-os pont

	D2 d2obj;
	d2obj.f();
	d2obj.vf();
	d2obj.pvf();
	cout << endl;

	//7-es pont

	D21 d21obj;
	D22 d22obj;

	f(d21obj);
	f(d22obj);
}