/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int BIT[100000];

void initBIT(int *Array,int Size)
{
    for(int i=1; i<=Size; i++)
    {
        int Add=Array[i-1];
        int j=i;
        while(j<=Size)
        {
            BIT[j] += Add;
            j += (j & (-j));
        }
    }
}

int SumQuery(int Index)
{
    int Sum=0;
    while(Index>0)
    {
        Sum += BIT[Index];
        Index -= Index & (-Index);
    }
    return Sum;
}

int RangeSumQuery(int i,int j)
{
    return SumQuery(j)-SumQuery(i-1);
}

void Update(int Index, int Value, int Size)
{
    while(Index<=Size)
    {
        BIT[Index] += Value;
        Index += Index & (-Index);
    }
}


int main()
{
    ios::sync_with_stdio(false);

    int a[10]={4,1,6,7,2,8,9,2,5,3};

    initBIT(a,10);
    cout<<SumQuery(4)<<endl;
    Update(2,3,10);
    cout<<SumQuery(4)<<endl;
    cout<<RangeSumQuery(2,4)<<endl;

    return 0;
}

