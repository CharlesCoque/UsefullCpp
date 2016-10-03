#include <iostream>

int gErrorCode = 0;

void foo(int i)
{
    gErrorCode = 1;
	std::cout << "in foo with i = " << i << "\n";
}

int foo()
{
	return 1;
}

int getLastError()
{
	return 1; //Dummy error to test the code
}

struct Checker
{
	~Checker()
	{
		if( gErrorCode != 0 )
		{
			//An error happened, log it 
			std::cout << "Error detected value = " << gErrorCode << "\n";
		}
	}
};

#define check ( Checker(), false ) ? throw 0 :  

int main()
{
	int i = check foo();
    std::cout << "in main with i = " << i << "\n";
	check foo(12);
}
