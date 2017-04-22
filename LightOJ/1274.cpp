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
double dp[2][5003][2];
int vis[2][5003][2];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<=n;i++)
        {
            if(i*2+(n-i)*3==m)
            {
                u=i;v=n-i;
                break;
            }
        }
        c=0;
        memset(dp,0,sizeof(dp));
        double P,Q;
        for(i=n-1;i>=0;i--)
        {
            for(j=min(v,i);i-j<=u&&j>=0;j--)
            {
                P=(double)(v-j*1.0)/(double)(n-i);
                Q=(double)(u-(i-j*1.0))/(double)(n-i);
                dp[1-c][j][0]=(dp[c][j+1][1]+1)*P+dp[c][j][0]*Q;
                dp[1-c][j][1]=(dp[c][j+1][1])*P+(dp[c][j][0]+1)*Q;
            }
            c=1-c;
        }
        pf("Case %d: %.9lf\n",cs++,dp[c][0][1]);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
