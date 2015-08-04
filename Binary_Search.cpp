/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

template<typename T>
int Binary_Search(vector<T>List, T data)
{
    int lbound=0;
    int ubound=List.size();

    while(lbound<=ubound)
    {
        int mid=(lbound+ubound)/2;

        if(List[mid]==data)
            return mid;
        else if(List[mid]>data)
            ubound=mid-1;
        else
            lbound=mid+1;
    }
    return -1;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    vector<int>i={1,2,3,4,5,6,7};
    vector<double>d={1.45,2.78,3.14,4.90,5.76,6.32,7.49};
    vector<char>c={'a','b','c','d','e','f','g'};

    cout<<Binary_Search(i,4)<<endl;
    cout<<Binary_Search(d,7.49)<<endl;
    cout<<Binary_Search(c,'f')<<endl;

    return 0;
}

//Recursive:http://www.fredosaurus.com/notes-cpp/algorithms/searching/rbinarysearch.html

