//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
char st[100000];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,q,m,n,a,b,c,d,e,f,g,h,u,v;
     sn("%d",&t);
     while(t--)
     {
         sn("%s %d",&st,&q);
           pf("Square %d:\n",cs++);r=1;
         while(q--)
         {
             int r1,r2,c1,c2;
             sn("%d %d %d %d",&r1,&c1,&r2,&c2);
             pf("Query %d:\n",r++);
             l=strlen(st);
             for(i=r1;i<=r2;i++)
             {
                 b=abs(l+l-i);
                     b=min(i,b);
                 for(j=c1;j<=c2;j++)
                 {
                     a=abs(l+l-j);
                     a=min(j,a);
                     a=min(a,b);
                     pf("%c",st[a-1]);
                 }
                 pf("\n");
             }
         }
         pf("\n");
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

