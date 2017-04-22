//BISMILLAHIR RAHMANIR RAHIM
//#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
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
int dp[101][101],ar[102],vis[101][101];

int rec(int st,int en)
{
    if(st>en)
    {
        return 0;
    }
    int &ret=dp[st][en],u=0,s,tt;
    if(vis[st][en]!=-1)
        return ret;
     vis[st][en]=1;

     ret=-100000000;s=tt=0;
     for(int i=st;i<=en;i++)
       tt=tt+ar[i];
     for(int i=st;i<=en;i++)
     {
          s+=ar[i];u=1;
         ret=max(ret,s+(tt-s)-rec(i+1,en));
       //  printf("%d\n",ret);
     }
     s=0;
      for(int i=en;i>=st;i--)
     {
          s+=ar[i];u=1;
         ret=max(ret,s+(tt-s)-rec(st,i-1));

        // printf("%d\n",ret);
     }
    return ret;
}

int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d",&n);m=0;
         for(i=0;i<n;i++)
         {
             scanf("%d",&ar[i]);m+=ar[i];
         }
         memset(vis,-1,sizeof(vis));
         printf("Case %d: %d\n",r++,2*rec(0,n-1)-m);
     }
    return 0;
}

