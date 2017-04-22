//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
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
int vis[30000005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    c=0;
    for(i=1;i<=30000000;i++)
    {
        for(j=i;j<=30000000;j+=i)
        {
            u=j^i;
            if(i==1)vis[j]=0;
            if(u>=2&&u%2==0&&j%u==i)
            {
                vis[j]++;
            }
        }
    }
    vis[0]=0;
    for(i=1;i<=30000000;i++)
    {
        vis[i]+=vis[i-1];
    }
     sn("%d",&t);
     while(t--)
     {
         sn("%d",&n);
         pf("Case %d: %d\n",cs++,vis[n]);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

