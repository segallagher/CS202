#pragma once
#ifndef MYCLASS
#define MYCLASS

class MyClass
{
public:
	MyClass();
	MyClass(const MyClass& g);
	MyClass(const int& h);
	void SetNum(const int &num);
	const int ReadNum();
	~MyClass();

private:
	int _num;
};

#endif