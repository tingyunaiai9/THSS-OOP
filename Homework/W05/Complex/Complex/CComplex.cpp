#include "pch.h"

#include "CComplex.h"

CComplex::CComplex(double real, double imaginary)
	: m_real(real), m_imaginary(imaginary)
{

}

double CComplex::mb_getReal() const
{
	return m_real;
}

double CComplex::mb_getImaginary() const
{
	return m_imaginary;
}

void CComplex::mb_show(string str) const
{
	cout << str << *this << endl;
}

//———————————————— + - * / == != << >> overload to be friend ————————————————
CComplex operator + (const CComplex& c1, const CComplex& c2)
{
	CComplex c3;
	c3.m_real = c1.m_real + c2.m_real;
	c3.m_imaginary = c1.m_imaginary + c2.m_imaginary;
	return c3;
}

CComplex operator - (const CComplex& c1, const CComplex& c2)
{
	CComplex c3;
	c3.m_real = c1.m_real - c2.m_real;
	c3.m_imaginary = c1.m_imaginary - c2.m_imaginary;
	return c3;
}

CComplex operator * (const CComplex& c1, const CComplex& c2)
{
	CComplex c3;
	c3.m_real = c1.m_real * c2.m_real - c1.m_imaginary * c2.m_imaginary;
	c3.m_imaginary = c1.m_real * c2.m_imaginary + c1.m_imaginary * c2.m_real;
	return c3;
}

CComplex operator / (const CComplex& c1, const CComplex& c2)
{
	if (c2.m_real == 0 && c2.m_imaginary == 0)
	{
		cout << "Error: DIVISOR CANNOT BE ZERO!" << endl;
		return 0;
	}
	CComplex c3;
	c3.m_real = (c1.m_real * c2.m_real + c1.m_imaginary * c2.m_imaginary) / (pow(c2.m_real, 2) + pow(c2.m_imaginary, 2));
	c3.m_imaginary = (c1.m_imaginary * c2.m_real - c1.m_real * c2.m_imaginary) / (pow(c2.m_real, 2) + pow(c2.m_imaginary, 2));
	return c3;
}

bool operator == (const CComplex& c1, const CComplex& c2)
{
	return c1.m_real == c2.m_real && c1.m_imaginary == c2.m_imaginary;
}

bool operator != (const CComplex& c1, const CComplex& c2)
{
	return c1.m_real != c2.m_real || c1.m_imaginary != c2.m_imaginary;
}

istream& operator >> (istream& is, CComplex& c)
{
	string str;
	is >> str;

	int pos = 0; // position of + or - in front of i

	if(str[str.length() - 1] == 'i')
	{
		if(str.length() == 1) // i
			c.m_imaginary = 1;
		else if(str[str.length() - 2] == '+') // a+i
		{
			c.m_imaginary = 1;
			pos = str.length() - 2;
		}
		else if(str[str.length() - 2] == '-') // a-i
		{
			c.m_imaginary = -1;
			pos = str.length() - 2;
		}
		else // a+-bi
		{
			pos = str.find_last_of("+-");
			if(pos == string::npos) // bi
				pos = 0;
			c.m_imaginary = atof(str.substr(pos, str.length() - pos - 1).c_str());
		}

		if(pos == 0)
			c.m_real = 0;
		else
			c.m_real = atof(str.substr(0, pos).c_str());
	}
	else
	{
		c.m_real = atof(str.c_str());
		c.m_imaginary = 0;
	}

	return is;
}

ostream& operator << (ostream& os, const CComplex& c)
{
	if(c.m_imaginary == 0)
		os << c.m_real;
	else if(c.m_real == 0)
	{
		if(c.m_imaginary == 1)
			os << "i";
		else if(c.m_imaginary == -1)
			os << "-i";
		else
			os << c.m_imaginary << "i";
	}
	else if(c.m_imaginary == 1)
		os << c.m_real << "+i";
	else if(c.m_imaginary == -1)
		os << c.m_real << "-i";
	else if(c.m_imaginary < 0)
		os << c.m_real << "-" << -c.m_imaginary << "i";
	else
		os << c.m_real << "+" << c.m_imaginary << "i";
	return os;
}
// ————————————————————————————————————————————————————————————————————————

// ———————————————— ++ -- += -= *= /= overload to be member function ————————————————
CComplex CComplex::operator ++ () // ++c
{
	++m_real;
	return (*this);
}

CComplex CComplex::operator ++ (int) // c++
{
	CComplex temp_c = *this;
	m_real++;
	return temp_c;
}

CComplex CComplex::operator -- () // --c
{
	--m_real;
	return (*this);
}

CComplex CComplex::operator -- (int) // c--
{
	CComplex temp_c = *this;
	m_real--;
	return temp_c;
}

CComplex CComplex::operator += (const CComplex& c)
{
	m_real += c.m_real;
	m_imaginary += c.m_imaginary;
	return (*this);
}

CComplex CComplex::operator -= (const CComplex& c)
{
	m_real -= c.m_real;
	m_imaginary -= c.m_imaginary;
	return (*this);
}

CComplex CComplex::operator *= (const CComplex& c)
{
	CComplex temp_c = *this;
	m_real = temp_c.m_real * c.m_real - temp_c.m_imaginary * c.m_imaginary;
	m_imaginary = temp_c.m_real * c.m_imaginary + temp_c.m_imaginary * c.m_real;
	return (*this);
}

CComplex CComplex::operator /= (const CComplex& c)
{
	CComplex temp_c = *this;
	m_real = (temp_c.m_real * c.m_real + temp_c.m_imaginary * c.m_imaginary) / (pow(c.m_real, 2) + pow(c.m_imaginary, 2));
	m_imaginary = (temp_c.m_imaginary * c.m_real - temp_c.m_real * c.m_imaginary) / (pow(c.m_real, 2) + pow(c.m_imaginary, 2));
	return (*this);
}
// ————————————————————————————————————————————————————————————————————————
