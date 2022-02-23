#include <iostream>
#include "MyClass.h"

void rawPtr() {
	std::cout << "Creating raw pointer" << std::endl;
	MyClass* number = new MyClass();
	std::cout << "Deleting raw pointer" << std::endl;
	delete number;
}

void uniquePtr() {
	std::cout << "Creating unique pointer" << std::endl;
	std::unique_ptr<MyClass> numba(new MyClass(6));
	std::cout << "Exiting Scope" << std::endl;
}

void transferPtr() {
	std::cout << "Creating unique pointer" << std::endl;
	std::unique_ptr<MyClass> numba1(new MyClass(30));
	std::cout << "Transfering ownership to another unique pointer" << std::endl;
	std::unique_ptr<MyClass> numba2 = std::move(numba1);
	std::cout << "Calling member function" << std::endl;
	std::cout << numba2.get()->ReadNum() << std::endl;
	std::cout << "Exiting Scope" << std::endl;
}

void sharedPtr() {
	std::cout << "Creating shared pointer" << std::endl;
	std::shared_ptr<MyClass> bean(new MyClass());
	std::cout << "Creating second shared pointer reffering to the first" << std::endl;
	std::shared_ptr<MyClass> grape = bean;
	std::cout << "Exiting Scope" << std::endl;
}

int main()
{
	std::cout << 3["stirng"] << std::endl;
#if 0
	std::cout << "-Starting rawPtr-" << std::endl;
	rawPtr();
	std::cout << std::endl;
	std::cout << "-Starting uniquePtr-" << std::endl;
	uniquePtr();
	std::cout << std::endl;
	std::cout << "-Starting transferPtr-" << std::endl;
	transferPtr();
	std::cout << std::endl;
	std::cout << "-Starting sharedPtr-" << std::endl;
	sharedPtr();
	std::cout << std::endl;
#endif
}
