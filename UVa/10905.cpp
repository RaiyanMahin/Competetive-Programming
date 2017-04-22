//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string>
#include<math.h>
#include<algorithm>
#include<iostream>
#define N 100000
using namespace std;
bool cmp(string  x,string y)
{
     string t1=x+y;
     string t2=y+x;
     if(t1>t2)
       return true;

         return false;
}

int main()
{
    int test,i;
    string a[60];
    while(scanf("%d",&test)==1)
    {
    if(test==0)
      break;

    for(i=0;i<test;i++)
      cin>>a[i];

    sort(a,a+test,cmp);

    for(i=0;i<test;i++)
    cout<<a[i];
    cout<<endl;
    }
   return 0;
}
