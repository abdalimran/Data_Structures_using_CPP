/*  Bismillah hir rahmanir raheem. Thanks to Allah for everything.
    Coder: Abdullah Al Imran
    Email: abdalimran@gmail.com   */

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int arraySize;
int *internalArray;

void InitializeBIT(vector<int> inputArray)
{
    arraySize = inputArray.size() + 1;
    internalArray = new int[arraySize];

    for(int i = 0; i < arraySize; i++)
       internalArray[i] = 0;

    for(int i = 1; i < arraySize; i++)
    {
       int valueToBeAdded = inputArray[i - 1];
       internalArray[i] += valueToBeAdded;
       int k = i;

       while( k < arraySize)
       {
           k += (k & -k);
           internalArray[k] += valueToBeAdded;
       }
    }
}

void IncrementValue(int value, int index)
{
  int indexToModify = index + 1;

  while(indexToModify < arraySize)
  {
    internalArray[indexToModify] += value;
    indexToModify += (indexToModify & -indexToModify);
  }
}

int Query(int index)
{
   int indexToRetrieve = index + 1;
   int retValue = 0;

   while(indexToRetrieve)
   {
      retValue += internalArray[indexToRetrieve];
      indexToRetrieve -= (indexToRetrieve & -indexToRetrieve);
   }
   return retValue;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    vector<int>v={1,2,3,4,5,6,7};

    InitializeBIT(v);
    IncrementValue(2,0);
    cout<<Query(3);


    return 0;
}

