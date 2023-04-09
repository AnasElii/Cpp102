#include <iostream>
#include <string>

using namespace std;

class GoodClass
{

	string _str;
public:
	GoodClass(int id, string name, int age) : _id(id), _name(name), _age(age)
	{
		
	}
protected:
	int _id;
	string _name;
	int _age;
};

class BadClass : public GoodClass
{
	string _str;
public:
	BadClass(string str, int id, string name, int age) : GoodClass(id, name, age)
	{
		this->_str = str;
	}
};

/*
class ClassB
{
public:
	ClassB(int number)
	{
		
	}
};

class ClassA
{
private:
	int& _number;
	int& _number2;
	int& _number3 ;
	ClassB classB;
public:
	ClassA(int& number) : _number(number) , _number2(number), _number3(number), classB(10)
	{
		
	}
	int getNumber() { return _number; }
	int getNumber2() { return _number2; }
	int getNumber3() { return _number3; }
};
*/

int main()
{
	/*int number = 10;
	ClassA* classA = new ClassA(number);
	cout << "Number: " << classA->getNumber() << " | Number2: " << classA->getNumber2() << " | Number3: " << classA->getNumber3() << endl;*/


	return 0;
}