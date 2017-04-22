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
ll dp[11][2][(1<<11)+5],dpp[(1<<11)+5],mod=1000000007,ar[11]={0,1,2,3,4,5,6,7,8,9},arr[15],tak;
ll rec(int p,int msk,int cr,int n)
{
    if(p==0)
    {
        if(msk==tak)
            return cr;
        return 0;
    }
    ll &ret=dp[p][cr][msk];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0;i<10;i++)
    {
        if(tak&(1<<i))
        {
           if(i==0&&msk==0)
            continue;
           if(ar[i]<arr[n-p])
                ret=(ret+rec(p-1,msk|(1<<i),1,n))%mod;
           else if(ar[i]==arr[n-p])
            ret=(ret+rec(p-1,msk|(1<<i),cr,n))%mod;
           else if(ar[i]>arr[n-p]&&cr==1)
           {
               ret=(ret+rec(p-1,msk|(1<<i),cr,n))%mod;;
           }
        }
    }
    return ret;
}
ll dpd[1<<11][(1<<11)];
ll rec1(int p,int msk,int par)
{
    ll &ret=dpd[msk][par];
    if(ret!=-1)
    {
        return ret;
    }
    ret=0;
    for(int i=par-1;i>0;i--)
    {
        if((msk&i)==0)
        {
            ret=(ret+(dpp[i]*(1+rec1(p+1,msk|i,i))%mod))%mod;
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
            sn("%d",&n);
    //n=1000000000;
    a=n+1;b=0;
    while(a>0)
    {
        a/=10;
        b++;
    }
    a=n+1;
    for(i=b-1;i>=0;i--)
    {
        arr[i]=a%10;a/=10;
    }
    m=1<<10;
    dpp[0]=dpp[1]=0;
    for(i=2;i<m;i++)
    {
        memset(dp,-1,sizeof(dp));
        tak=i;
        dpp[tak]=0;
        for(j=1;j<=b;j++)
        {
            if(j==b)
            dpp[tak]=(dpp[tak]+rec(j,0,0,j))%mod;
            else
            dpp[tak]=(dpp[tak]+rec(j,0,1,j))%mod;
        }
//        if(dpp[tak]>0)
//        {
//            pf("%lld %lld\n",dpp[tak],tak);
//        }
    }
    ll ans=0;
    memset(dpd,-1,sizeof(dpd));
    ans=rec1(0,0,m);
//    for(i=0;i<10;i++)
//    {
//        if(dpd[i]>0)
//         pf("%lld %d\n",dpd[i],i);
//    }
    pf("Case %d: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

