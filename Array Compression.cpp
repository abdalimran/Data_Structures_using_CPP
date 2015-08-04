/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

void compress()
{
	map<int,int>mymap;

	int input[]={-102,1,134565589,134565589,-102,66666668,134565589,66666668,-102,1,-2};

	int assign=0;
	int compressed[100];
	int c=0;
	int n=sizeof(input)/sizeof(int); //array size;

	for(int i=0;i<n;i++)
    {
		int x=input[i];

		if(mymap.find(x)==mymap.end())
        {
			mymap[x]=assign;
			printf("Mapping %d with %d\n",x,assign);
			assign++;
		}
		x=mymap[x];
		compressed[ c++ ]=x;
	}
	printf("Compressed array: ");
	for(int i=0;i<n;i++) printf("%d ",compressed[i]);puts("");
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    compress();

    return 0;
}
