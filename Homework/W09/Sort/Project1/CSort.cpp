#include "CSort.h"

CSort::CSort()
{
    m_vec.clear();
    m_set.clear();
}

void CSort::mb_getNum()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    int x;
    for(int i = 0; i < n; i++)
    {
        cin >> x;
        m_vec.push_back(CInt(x));
        m_set.insert(CInt(x));
    }
    cout << endl;
}

void CSort::mb_sort()
{
    sort(m_vec.begin(), m_vec.end());

    cout << "Sorted vector: ";
    for(auto i : m_vec)
    {
        cout << i.mb_getNum() << " ";
    }
    cout << endl;

    cout << "Sorted set: ";
    for(auto i : m_set)
    {
        cout << i.mb_getNum() << " ";
    }
    cout << endl;
}
