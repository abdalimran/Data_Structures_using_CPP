/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int CSArray[10];

void CumulativeSum(int arr[], int Size)
{
    CSArray[0]=arr[0];
    for(int i=1;i<Size;i++)
        CSArray[i]=CSArray[i-1]+arr[i];
}

int SumRange(int Start, int End)
{
    int result;
    if(Start<=End)
         result=CSArray[End]-CSArray[Start-1];

    return result;
}

int main()
{
    ios::sync_with_stdio(false);

    int a[10]={4,1,6,7,2,8,9,2,5,3};
    int MapEven[10];

    for(int i=0;i<10;i++)
    {
        if(a[i]%2==0)
            MapEven[i]=1;
        else
            MapEven[i]=0;
    }
    CumulativeSum(MapEven,10);
    cout<<SumRange(4,9)<<endl;

    return 0;
}

