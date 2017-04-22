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
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
 int a,b,c,d;
}ar[1005];
bool cmp(T x,T y)
{
    return x.a>y.a;
}
int dp[1005][15];
int rec(int p,int cost,int n)
{
    if(p>=n)
        return 0;
    int &ret=dp[p][cost];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=cost*ar[p].d+rec(p+1,cost,n);
    ret=min(ret,ar[p].b+ar[p].c*ar[p].d+rec(p+1,ar[p].c,n));
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d %d %d %d",&ar[i].a,&ar[i].b,&ar[i].c,&ar[i].d);
        }
        memset(dp,-1,sizeof(dp));
        sort(ar,ar+n,cmp);
        pf("Case %d: %d\n",cs++,ar[0].b+rec(0,ar[0].c,n));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

