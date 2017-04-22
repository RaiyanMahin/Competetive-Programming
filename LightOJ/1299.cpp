
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
ll ar[10005],dp[1005][1005],len;
char st[1005];
ll rec(int p,int u)
{
    if(p+u==len)
    {
        if(p==len)
            return 1;
        return 0;
    }

    ll &ret=dp[p][u];
    if(ret!=-1)
        return ret;
    ret=0;
    if(st[p+u]=='U')
    {
        if(u>0)ret=ret+u*rec(p+1,u);
        ret=ret+rec(p,u+1);
    }
    else if(u>0)
    {
        ret=ret+u*u*rec(p+2,u-1);
        ret=ret+u*rec(p+1,u);
    }
    ret=ret%1000000007;
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
        l=strlen(st);u=v=0;
        for(i=0,j=0;i<l;i++)
        {
            if(st[i]!='E')
                st[j++]=st[i];
            if(st[i]=='U')
             u++;
            if(st[i]=='D')
                v++;
        }
        st[j]=0;
        l=j;
        c=v;
        for(i=0;i<l;i++)
        {
            ar[i]=10000;
           if(st[i]=='D')
                ar[i]=c,c--;
        }
        pf("Case %d: ",cs++);
        if(l==0)
            pf("1\n");
        else if(st[0]=='D'||st[l-1]=='U')
            pf("0\n");
        else
        {
            memset(dp,-1,sizeof(dp));
            len=l;
            pf("%lld\n",rec(0,0));
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
