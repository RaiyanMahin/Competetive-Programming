
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
ll dp[75][75],len;
char st[105];
ll rec(int a,int b)
{
    if(a>b)
        return 1;
    ll &ret=dp[a][b];
    if(ret!=-1)
        return ret;
    ret=0;
    int c=0,d,e;
    if(st[a]=='R')
        c++;
    for(int i=a+1;i<=b;i+=3)
    {
        if(st[i]=='R')d=1;
        else d=0;
        if(c+d<2)
        for(int j=i+1;j<=b;j+=3)
        {
            e=0;
            if(st[j]=='R')e=1;
            if(c+d+e<2)
             ret=ret+rec(a+1,i-1)*rec(i+1,j-1)*rec(j+1,b);
        }
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
        sn("%s",&st);
        l=strlen(st);
        ll ans=0;
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %lld\n",cs++,rec(0,l-1));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

