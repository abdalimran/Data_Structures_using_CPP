/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

#define MAX_SIZE 100000

int parent[MAX_SIZE],Rank[MAX_SIZE];

void Make_Set(const int x)
{
    parent[x] = x;
    Rank[x] = 0;
}

int Find(const int x)
{
    if(parent[x] != x)
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y)
{
    int PX = Find(x),PY = Find(y);

    if(Rank[PX] > Rank[PY])
        parent[PY] = PX;
    else
    {
        parent[PX] = PY;
        if(Rank[PX]==Rank[PY])
            Rank[PY]++;
    }
}

int main()
{
    Make_Set(1);
    Make_Set(2);
    Make_Set(3);
    Make_Set(4);

    cout<<Find(1)<<endl;
    cout<<Find(4)<<endl;

    Union(1,3);
    Union(2,4);

    cout<<Find(1)<<endl;
    cout<<Find(4)<<endl;

    return 0;
}
