
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
typedef unsigned long long int llu;
using namespace std;
llu dp[5][13][13][13][13];
bool dpp[5][13][13][13][13];
llu rec(int p,int a,int b,int c,int d)
{
    if(a+b+c+d==0)
    {
        return (llu)1;
    }
    llu &ret=dp[p][a][b][c][d];
    if(dpp[p][a][b][c][d]!=0)
        return ret;
    dpp[p][a][b][c][d]=1;
    ret=0;
    llu s=0;
    if(a>0)
    {
        s=a;
        ret=ret+a*rec(3,a-1,b+1,c,d);
    }
    if(b>0)
    {
        if((p==3&&b>1))
            ret=ret+(b-1)*rec(2,a,b-1,c+1,d);
        else if(p!=3)
            ret=ret+b*rec(2,a,b-1,c+1,d);
    }
    if(c>0)
    {
        if((p==2&&c>1))
            ret=ret+(c-1)*rec(1,a,b,c-1,d+1);
        else if(p!=2)
            ret=ret+(c)*rec(1,a,b,c-1,d+1);
    }
    if(d>0)
    {
        if((p==1&&d>1))
            ret=ret+(d-1)*rec(0,a,b,c,d-1);
        else if(p!=1)
            ret=ret+(d)*rec(0,a,b,c,d-1);
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    //freopen(".txt","r",stdin);
    memset(dpp,0,sizeof(dpp));
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        int vis[100];
        char st[22];
        memset(vis,0,sizeof(vis));
        int ar[5];
        ar[0]=1;
        for(i=1;i<=4;i++)
        {
            ar[i]=ar[i-1]*i;
        }
        for(i=0;i<n;i++)
            {
                sn("%s",&st);
                vis[st[0]]++;
            }
        llu ans=1;
        int cnt[5];
        memset(cnt,0,sizeof(cnt));
        for(i=1;i<=100-7;i++)
        {
            if(vis[i]>0)
            {
                llu uu=ar[vis[i]];
                cnt[vis[i]]++;
                ans=ans*uu;
            }
        }
        pf("Case %d: %llu\n",cs++,ans*rec(0,cnt[4],cnt[3],cnt[2],cnt[1]));
    }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
