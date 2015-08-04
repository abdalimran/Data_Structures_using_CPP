/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAX 100001
int Array[MAX];
int ST[MAX*3];

void initST(int Node, int bNode,int eNode)
{
    if(bNode==eNode)
    {
        ST[Node]=Array[bNode];
        return;
    }

    int Left=Node*2;
    int Right=Node*2+1;
    int Mid=(bNode+eNode)/2;

    initST(Left,bNode,Mid);
    initST(Right,Mid+1,eNode);

    ST[Node]=ST[Left]+ST[Right];
}

int SumQuery(int Node,int bNode,int eNode,int From,int To)
{
    if (From>eNode|| To<bNode) return 0;
    if (bNode>=From && eNode<=To) return ST[Node];

    int Left=Node*2;
    int Right=Node*2+1;
    int Mid=(bNode+eNode)/2;

    int Sum1=SumQuery(Left,bNode,Mid,From,To);
    int Sum2=SumQuery(Right,Mid+1,eNode,From,To);

    return Sum1+Sum2;
}

void Update(int Node,int bNode,int eNode,int Index, int Value)
{
    if (Index>eNode || Index<bNode) return;
    if (bNode>=Index && eNode<=Index)
    {
        ST[Node]=Value;
        return;
    }

    int Left=Node*2;
    int Right=Node*2+1;
    int Mid=(bNode+eNode)/2;

    Update(Left,bNode,Mid,Index,Value);
    Update(Right,Mid+1,eNode,Index,Value);

    ST[Node]=ST[Left]+ST[Right];
}

void Increment(int Node,int bNode,int eNode,int Index, int Value)
{
    if (Index>eNode || Index<bNode) return;
    if (bNode>=Index && eNode<=Index)
    {
        ST[Node]+=Value;
        return;
    }

    int Left=Node*2;
    int Right=Node*2+1;
    int Mid=(bNode+eNode)/2;

    Increment(Left,bNode,Mid,Index,Value);
    Increment(Right,Mid+1,eNode,Index,Value);

    ST[Node]=ST[Left]+ST[Right];
}

//Lazy Propagation
void UpdateRange(int Node, int bNode, int eNode, int From, int To, int Value)
{
	if(bNode>eNode || bNode>To || eNode<From)
		return;
  	if(bNode == eNode)
    {
        ST[Node]+=Value;
		return;
	}

	int Left=Node*2;
	int Right=Node*2+1;
	int Mid=(bNode+eNode)/2;

	UpdateRange(Left, bNode, Mid, From, To, Value);
	UpdateRange(Right, Mid+1, eNode, From, To, Value);

	ST[Node]=ST[Left]+ST[Right];
}


int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>Array[i];

    initST(1,1,n);

    Update(1,1,n,2,1);
    cout<<SumQuery(1,1,n,1,3)<<endl;

    UpdateRange(1,1,n,1,3,2);
    cout<<SumQuery(1,1,n,1,3)<<endl;

    return 0;
}

