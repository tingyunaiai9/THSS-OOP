#pragma once

class CComplex
{
private:
    double m_real;
    double m_imaginary;

public:
    CComplex(double real = 0, double imaginary = 0);

private:
    double mb_getReal() const;
    double mb_getImaginary() const;

public:
    void mb_show(string str = "") const;

// + - * / == != << >> overload to be friend
public:
    friend CComplex operator + (const CComplex& c1, const CComplex& c2);
    friend CComplex operator - (const CComplex& c1, const CComplex& c2);
    friend CComplex operator * (const CComplex& c1, const CComplex& c2);
    friend CComplex operator / (const CComplex& c1, const CComplex& c2);

    friend bool operator == (const CComplex& c1, const CComplex& c2);
    friend bool operator != (const CComplex& c1, const CComplex& c2);

    friend istream& operator >> (istream& is, CComplex& c);
    friend ostream& operator << (ostream& os, const CComplex& c);

// ++ -- += -= *= /= overload to be member function
public:
    CComplex operator ++ ();
    CComplex operator ++ (int);
    CComplex operator -- ();
    CComplex operator -- (int);

    CComplex operator += (const CComplex& c);
    CComplex operator -= (const CComplex& c);
    CComplex operator *= (const CComplex& c);
    CComplex operator /= (const CComplex& c);
};
