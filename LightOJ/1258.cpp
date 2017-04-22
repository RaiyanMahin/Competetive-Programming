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
char st[1000005];//main string;
char ss[1000005];// pattern string
int br[1000005];
vector<int>kmm;
void preprocess(int n)
{
    int i=0,j=-1;
    br[i]=j;
    while(i<n)
    {
        while(j>=0&&ss[i]!=ss[j])j=br[j];
        j++;i++;
        br[i]=j;
    }
}
int mm;
void kmpsearch(int n,int m)
{
    int i=0,j=0;
    while(i<n)
    {
       // j=max(j,n-i-1);
        while(j>=0&&st[i]!=ss[j])j=br[j];
       // j=max(j,n-i-1);
        j++;i++;
    }
    mm=min(mm,m-j);
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%s",&st);
         l=strlen(st);j=0;
         for(i=l-1;i>=0;i--)
            ss[j++]=st[i];
         ss[j]=0;
         preprocess(l);
         mm=l-1;
         kmpsearch(l,l);
       pf("Case %d: %d\n",cs++,mm+strlen(st));
     }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


