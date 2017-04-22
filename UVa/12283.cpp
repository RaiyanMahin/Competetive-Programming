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
int a,b;
}ans[105];
int dp[105][105],ar[105],n,arr[105];
int rec(int st,int en)
{
    if(st>en)
    {
        return 0;
    }
    int m=1,&ret=dp[st][en];
    if(ret!=-1)
        return ret;
    ret=min(rec(st+1,en)+1,rec(st,en-1)+1);
    for(int i=st+1;i<n;i++)
    {
        if(ar[st]==ar[i])
            ret=min(ret,rec(st+1,i)+rec(i+1,en));
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,a,b,c,d,e,f,g,h,u,v;
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d",&n,&m);
         j=0;
         for(i=0;i<n;i++)
         {
             sn("%d",&ar[i]);
         }
         memset(dp,-1,sizeof(dp));
         pf("Case %d: %d\n",cs++,rec(0,n-1));
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

