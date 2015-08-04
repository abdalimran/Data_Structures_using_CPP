/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>

#define endl '\n'

using namespace std;

class disjoint_set
{
    int *parent;
    int *rank;

public:
    disjoint_set(int N);

    int find(int val);
    void unite(int lhs, int rhs);
    bool same_component(int lhs, int rhs);
};

disjoint_set::disjoint_set(int size)
{
    parent = new int[size];
    rank = new int[size];

    for (int i = 0; i < size; ++i)
        parent[i] = i;
}

int disjoint_set::find(int val)
{
    if (val == parent[val])
        return val;

    return parent[val] = find(parent[val]);
}

void disjoint_set::unite(int lhs, int rhs)
{
    int parent_lhs = find(lhs);
    int parent_rhs = find(rhs);

    if (rank[parent_lhs] < rank[parent_rhs])
        parent[parent_lhs] = parent_rhs;
    else
        parent[parent_rhs] = parent_lhs;

    if (rank[parent_lhs] == rank[parent_rhs])
        ++rank[parent_lhs];
}

bool disjoint_set::same_component(int lhs, int rhs)
{
    return find(lhs) == find(rhs);
}

int main()
{
    int N, M;
    cin>>N>>M;

    disjoint_set ds(N);

    for(int i = 0; i < M; ++i)
    {
        int op, x, y;
        cin>> op >> x >> y;
        --x, --y;

        if (op == 1)
        {
            ds.unite(x, y);
        }
        else
        {
            if (ds.same_component(x, y))
            {
                cout<< "YES\n";
            }
            else
            {
                cout<< "NO\n";
            }
        }
    }

    return 0;
}
