#include <iostream>
using std::cout;

class Base {
public:
	virtual void fooVirtual() const { cout << "Base class virtual function\n"; }
	void fooNotVirtual() const { cout << "Base class non-virtual function\n"; }
};

class Derived : public Base {
public:
	void fooVirtual() const override { cout << "Derived class virtual function\n"; }
	void fooNotVirtual() const { cout << "Derived class non-virtual function\n"; }
};

int main() {
	Base b;
	Derived d;

	//  1) A base class pointer to the base class object.
	Base* bPb = &b;

	//  2) A base class pointer to the derived class object.
	Base* bPd = &d;

	//  3) A derived class pointer to the derived class object.
	Derived* dad = &d;
	//  4) A base class reference to the base class object.
	Base& brb = b;
	//  5) A base class reference to the derived class object.
	Base& brd = d;
	//  6) A derived class reference to the derived class object.
	Derived& drd = d;

	cout << "Calling non-virtual function from Base class pointer to base: ";
	bPb->fooNotVirtual();

	cout << "Calling virtual function from Base class pointer to base: ";
	bPb->fooVirtual();

	//Call both functions from pointers 2-6

	cout << "Calling non-virtual function from Base class pointer to derived: ";
	bPd->fooNotVirtual();

	cout << "Calling virtual function from Base class pointer to derived: ";
	bPd->fooVirtual();
	////////
	cout << "Calling non-virtual function from Derived class pointer to derived: ";
	dad->fooNotVirtual();

	cout << "Calling virtual function from Derived class pointer to derived: ";
	dad->fooVirtual();
	////////////////
	cout << "Calling non-virtual function from Base class reference to base: ";
	brb.fooNotVirtual();

	cout << "Calling virtual function from Base class reference to base: ";
	brb.fooVirtual();
	//

	cout << "Calling non-virtual function from Base class reference to derived: ";
	brd.fooNotVirtual();

	cout << "Calling virtual function from Base class reference to derived: ";
	brd.fooVirtual();
	//

	cout << "Calling non-virtual function from Derived class reference to derived: ";
	drd.fooNotVirtual();

	cout << "Calling virtual function from Derived class reference to deroved: ";
	drd.fooVirtual();

	return 0;
}