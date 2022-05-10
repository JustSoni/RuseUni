// ComplexOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Complex.h"


int main()
{
	CComplex c1(2,2);
	CComplex c2(2,2);
	CComplex c4(-1,3);
	CComplex c5(1,-3);
	CComplex c6(-1,-3);

	CComplex c3 = c1+c2; // c1.operator+(c2); && operator(c1,c2);
	c3.display();
	c3 = c1-c2;
	c3.display();
	c3=c1++;
	c3.display();
	c3=c1--;
	c3.display();
	c3=~c4;
	c3.display();
	c3=~c5;
	c3.display();
	c3=~c6;
	c3.display();


	std::cout<<"START\n";

	CComplex C1, C2(3,2), C3(-1,-2), result;

	result = (C1 + C2) * C3;
	
	
	std::cout<<"C1 = ";
	C1.display();
	std::cout<<"C2 = ";
	C2.display();
	std::cout<<"C3 = ";
	C3.display();

	std::cout<<"Result = (C1 + C2) * C3\n";


	std::cout<<"Result = ";
	result.display();
	(C1+C2).display();

	std::cout<<"TRY <<\n";
	cout<<result;

	return 0;
}

