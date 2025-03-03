#include <iostream>
#include <string>
#include <cctype>

#include "CException.h"

using namespace std;

int gb_transStringToInt(string str);

int main()
{
    string str;
    int num = 0;

    while(1)
    {
        try
        {
            cout << "Please enter a number: ";
            getline(cin, str);
            num = gb_transStringToInt(str);
        }
        catch(CExceptionEmptyString)
        {
            cout << "Empty string" << endl;
        }
        catch(CExceptionInvalidChar)
        {
            cout << "Invalid character" << endl;
        }
        catch(CExceptionInvalidSign)
        {
            cout << "Invalid sign" << endl;
        }
        catch(CExceptionInvalidLength)
        {
            cout << "Invalid length" << endl;
        }
        catch(CExceptionInvalidZero)
        {
            cout << "Invalid zero" << endl;
        }
        catch(...)
        {
            cout << "Unknown exception" << endl;
        }

        cout << "The number is: " << num << endl;
        num = 0;
    }

    // try
    // {
    //     cout << "Please enter a number: ";
    //     getline(cin, str);
    //     num = gb_transStringToInt(str);
    // }
    // catch(CExceptionEmptyString)
    // {
    //     cout << "Empty string" << endl;
    // }
    // catch(CExceptionInvalidChar)
    // {
    //     cout << "Invalid character" << endl;
    // }
    // catch(CExceptionInvalidSign)
    // {
    //     cout << "Invalid sign" << endl;
    // }
    // catch(CExceptionInvalidLength)
    // {
    //     cout << "Invalid length" << endl;
    // }
    // catch(CExceptionInvalidZero)
    // {
    //     cout << "Invalid zero" << endl;
    // }
    // catch(...)
    // {
    //     cout << "Unknown exception" << endl;
    // }

    // cout << "The number is: " << num << endl;

    return 0;
}

int gb_transStringToInt(string str)
{
    if(str.empty())
    {
        CExceptionEmptyString e;
        throw e;
    }

    if(str.find_first_not_of("+-0123456789") != string::npos)
    {
        CExceptionInvalidChar e;
        throw e;
    }

    if(str.find_first_of("+-") != str.find_last_of("+-"))
    {
        CExceptionInvalidSign e;
        throw e;
    }

    if(str.find_first_of("+-") != 0 && str.find_first_of("+-") != string::npos)
    {
        CExceptionInvalidSign e;
        throw e;
    }

    if(str[0] == '+' || str[0] == '-')
    {
        if(str.length() == 1)
        {
            CExceptionInvalidChar e;
            throw e;
        }
    }

    if(str[str.find_first_not_of("+-")] == '0' && str.length() > 1)
    {
        CExceptionInvalidZero e;
        throw e;
    }

    if(!isdigit(str[0]))
    {
        if(str.length() > 11)
        {
            CExceptionInvalidLength e;
            throw e;
        }

        long long num = stoll(str);
        if(num > INT_MAX || num < INT_MIN)
        {
            CExceptionInvalidLength e;
            throw e;
        }
    }
    else
    {
        if (str.length() > 10)
        {
            CExceptionInvalidLength e;
            throw e;
        }

        long long num = stoll(str);
        if (num > INT_MAX || num < INT_MIN)
        {
            CExceptionInvalidLength e;
            throw e;
        }
    }

    return stoi(str);

}
