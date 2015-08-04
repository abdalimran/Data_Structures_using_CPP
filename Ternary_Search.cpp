/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

template<typename T>

int Ternary_Search(vector<T>&List, T data)

{
    int lbound=0;
    int ubound=List.size();
    while(lbound<=ubound)
    {
        int mid1=(lbound*2+ubound)/3;
        int mid2=(lbound+lbound*2)/3;

        if(data==List[mid1])
        {
            return mid1;
            break;
        }
        else if(List[mid1]>data)
            ubound=mid1-1;
        else if(data==List[mid2])
        {
            return mid2;
            break;
        }
        else if(List[mid2]<data)
             lbound=mid2+1;
        else
        {
            lbound=mid1+1;
            ubound=mid2-1;
        }
    }
    return -1;

}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    vector<int>List={1,2,3,4,5,6,7,8};

    cout<<Ternary_Search(List,7)<<endl;

    return 0;
}
