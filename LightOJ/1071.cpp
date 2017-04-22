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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
int dp[105][101][101],ar[105][105];
int rec(int p,int a,int b,int n,int m)
{
    if(p>=n)
        return 0;
    int &ret=dp[p][a][b];
    if(ret!=-1)
        return ret;
    ret=0;
    int aa=0,bb=0;
    ret=max(ret,rec(p+1,a,b,n,m)+ar[p][b+1]+ar[p+1][a]);
    if(b+1<m)
    {
       ret=max(ret,rec(p,a,b+1,n,m)+ar[p][b+1]);
    }
    if(a+1<=b)
    {
       ret=max(ret,rec(p,a+1,b,n,m)+ar[p+1][a]);
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                sn("%d",&ar[i][j]);
            }
        }

        if(n==1&&m==1)
        {
            pf("Case %d: %d\n",cs++,ar[0][0]);
        }
        else
        {
            memset(dp,-1,sizeof(dp));
            pf("Case %d: %d\n",cs++,rec(0,0,0,n-1,m-1)+ar[0][0]+ar[n-1][m-1]);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

