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
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
int a;
};
int two[25],dp[1<<20][21],ar[1<<20],N;

void rec(int p,int h)
{
   // if(N==0)return;
    sn("%d",&ar[p]);
    if(h>0)
    {
        rec(2*p,h-1);
        rec(2*p+1,h-1);
    }
}
const int inf=200000000;
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    two[0]=1;
    for(i=1;i<22;i++)
    {
        two[i]=two[i-1]*2;
    }
    while(sn("%d",&h)!=EOF&&h!=-1)
    {
        sn("%d",&k);
        n=two[h+1]-1;
        N=n;
        rec(1,h);
        for(i=n;i>=1;i--)
        {
            dp[i][1]=ar[i];
            for(j=2;j<=k;j++)
                dp[i][j]=-inf;
            if(2*i<n)
            {
                for(j=2;j<=k;j++)
                {
                    for(a=1;a<j;a++)
                    {
                        dp[i][j]=max(dp[i][j],dp[2*i][a]+dp[2*i+1][j-a]);
                    }
                }
            }
        }
        int ans=-inf;
        for(i=1;i<=k;i++)
            ans=max(dp[1][i],ans);
        pf("%d\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
