/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

class BIT
{
    vector<int>data;

public:

    BIT(int Size)
    {
        data.resize(Size+1);
    }

    void Insert(int idx, int value)
    {
        while(idx < data.size())
        {
            data[idx] += value;
            idx += idx & -idx;
        }
    }

    int RangeSumQuery(int from, int to)
    {
        return getSum(to) - getSum(from-1);
    }

    int getSum(int element)
    {
        int value = 0;
        while(element != 0)
        {
            value += data[element];
            element = element & (element-1);
        }
        return value;
    }
};


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    BIT T(5);
    T.Insert(1,2);
    T.Insert(2,3);
    T.Insert(3,4);
    T.Insert(4,5);
    T.Insert(5,6);


    cout<<T.RangeSumQuery(2,4)<<endl;
    cout<<T.getSum(3)<<endl;


    return 0;
}

