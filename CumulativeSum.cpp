/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAX 7
int CSArray[MAX];

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
    int arr[]={4,-9,3,7,1,0,2};

    CumulativeSum(arr,7);

    int i,j;

    while(cin>>i>>j)
    {
        cout<<"The array is: ";
        for(auto i:arr)
            cout<<i<<" ";
        cout<<"\nThe sum from index "<<i<<" to "<<j<<" = "<<SumRange(i,j)<<endl;
    }

    return 0;
}

