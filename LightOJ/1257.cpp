//BISMILLAHIR RAHMANIR RAHIM
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
#define N 500000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
vector<int>ar[30005];
vector<int>cst[30005];
int dis[30005],diss[30005];
queue<int>Q;
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
   // freopen("Input.txt","r",stdin);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            ar[u].push_back(v);
            cst[u].push_back(c);
            ar[v].push_back(u);
            cst[v].push_back(c);
        }
        for(i=0;i<n;i++)
            dis[i]=N;
        Q.push(0);dis[0]=0;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            for(i=0,j=ar[u].size();i<j;i++)
            {
                v=ar[u][i];
                if(dis[v]>dis[u]+cst[u][i])
                {
                    dis[v]=dis[u]+cst[u][i];
                    Q.push(v);
                }
            }
        }
        int mx=0;
        for(i=0;i<n;i++)
        {
            if(dis[i]>mx&&dis[i]!=N) mx=dis[i],u=i;
        }
         for(i=0;i<n;i++)
            dis[i]=N;
        Q.push(u);dis[u]=0;a=u;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            for(i=0,j=ar[u].size();i<j;i++)
            {
                v=ar[u][i];
                if(dis[v]>dis[u]+cst[u][i])
                {
                    dis[v]=dis[u]+cst[u][i];
                    Q.push(v);
                }
            }
        }
        mx=0;
        for(i=0;i<n;i++)
        {
            if(dis[i]>mx) mx=dis[i],u=i;
            diss[i]=dis[i];
        }
         for(i=0;i<n;i++)
            dis[i]=N;
        Q.push(u);dis[u]=0;b=u;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            for(i=0,j=ar[u].size();i<j;i++)
            {
                v=ar[u][i];
                if(dis[v]>dis[u]+cst[u][i])
                {
                    dis[v]=dis[u]+cst[u][i];
                    Q.push(v);
                }
            }
        }
        printf("Case %d:\n",r);
        for(i=0;i<n;i++)
        {
            printf("%d\n",dis[i]>diss[i]?dis[i]:diss[i]);
            ar[i].clear();
            cst[i].clear();
        }
    }
    return 0;
}


