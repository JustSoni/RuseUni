#include "StdAfx.h"
#include "Complex.h"

#include <iostream>
#include <string>

using namespace std;

CComplex::CComplex()
{
	real = 0.0;
	imag = 0.0;
}

CComplex::CComplex(double re, double im)
{
	real = re;
	imag = im;
}

void CComplex::display()
{
	if(imag<0)
	cout<<real<<imag<<"i"<<'\n';
	else
	cout<<real<<'+'<<imag<<"i"<<'\n';
}

CComplex CComplex::operator+(const CComplex c1)
{
	CComplex temp;
	temp.real = real + c1.real;
	temp.imag = imag + c1.imag;

	return temp;
}

CComplex CComplex::operator-(const CComplex c1)
{
	CComplex temp;
	temp.real = real - c1.real;
	temp.imag = imag - c1.imag;

	return temp;
}

CComplex CComplex::operator*(const CComplex c1)
{
	CComplex temp;
	temp.real = real * c1.real;
	temp.imag = imag * c1.imag;

	return temp;
}

CComplex CComplex::operator++()
{
	real = real++;
	imag = imag++;

	return *this;
}

CComplex CComplex::operator--()
{
	real = real--;
	imag = imag--;

	return *this;
}

CComplex CComplex::operator~()
{
	if(real < 0)
		real *= -1;
	if(imag < 0)
		imag *= -1;

	return *this;
}

CComplex::~CComplex()
{
}

ostream& operator<<(ostream& stream, const CComplex& c1)
{
	
	if(c1.imag<0)
	return stream<<c1.real<<c1.imag<<"i"<<'\n';
	else
	return stream<<c1.real<<'+'<<c1.imag<<"i"<<'\n';

}