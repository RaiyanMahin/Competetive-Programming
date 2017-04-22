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
int dp[1005][1005],ar[1005];
bool vis[1005][1005];
int rec(int l,int r,int p)
{
    if(l>r)
    {
        return 0;
    }
    int &ret=dp[l][r];
    if(vis[l][r]==true)
        return ret;
    vis[l][r]=true;
    ret=-100000000;
    if(p==0)
    {
        ret=max(ret,ar[l]+rec(l+1,r,1));
        ret=max(ret,ar[r]+rec(l,r-1,1));
    }
    else
    {
        if(ar[l]>=ar[r])
            ret=rec(l+1,r,0);
        else
            ret=rec(l,r-1,0);
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%d",&n)!=EOF&&n)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
            s=s+ar[i];
        }
        memset(vis,false,sizeof(vis));
        pf("In game %d, the greedy strategy might lose by as many as %d points.\n",cs++,2*rec(0,n-1,0)-s);
    }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

