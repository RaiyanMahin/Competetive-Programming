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
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}

int vis[10],gr[505][505];
int R[]={-2,-3,-2,-1,-1,1},C[]={1,-1,-1,-2,-3,-2};
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    gr[0][0]=0;
    for(i=1;i<505;i++)
    {
        u=0,v=i;
        while(v>=0&&u<504)
        {
            memset(vis,0,sizeof(vis));
            for(j=0;j<6;j++)
            {
                int x=u+R[j];
                int y=v+C[j];
                if(x>=0&&y>=0&&x<504&&y<504)
                    vis[gr[x][y]]=1;
            }
            for(j=0;j<=7;j++)
            {
                if(vis[j]==0)
                {
                    gr[u][v]=j;
                    break;
                }
            }
            u++;v--;
        }
    }
    for(i=1;i<505;i++)
    {
        u=i,v=503;
        while(v>=0&&u<504)
        {
            memset(vis,0,sizeof(vis));
            for(j=0;j<6;j++)
            {
                int x=u+R[j];
                int y=v+C[j];
                if(x>=0&&y>=0&&x<504&&y<504)
                    vis[gr[x][y]]=1;
            }
            for(j=0;j<=7;j++)
            {
                if(vis[j]==0)
                {
                    gr[u][v]=j;
                    break;
                }
            }
            u++;v--;
        }
    }
//    for(i=0;i<10;i++)
//    {
//        for(j=0;j<10;j++)
//        {
//            pf(" %d",gr[i][j]);
//        }
//        pf("\n");
//    }
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);s=0;
        for(i=0;i<n;i++)
        {
            sn("%d %d",&u,&v);
            s=s^gr[u][v];
        }
        //pf("%d\n",s);
        if(s==0)
            pf("Case %d: Bob\n",cs++);
        else
            pf("Case %d: Alice\n",cs++);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

