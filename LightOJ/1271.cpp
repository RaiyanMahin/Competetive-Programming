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
#define N 10000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int dis[50005],pr[50005],arr[50005];
queue<int>Q;
vector<int>ar[50005];

int par(int a,int b)
{
    int p=1;
    if(a>b)p=0;
    while(pr[a]!=-1)
    {
        if(pr[a]<pr[b])
            p=1;
        else if(pr[a]>pr[b])
            p=0;
        a=pr[a];b=pr[b];
    }
    return p;
}

int main()
{
    int i,j,x,y,mn,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    //freopen("Input.txt","r",stdin);
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
        scanf("%d",&n);
        for(i=0;i<=50000;i++)
        {
            dis[i]=N;pr[i]=N;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);

        }
        for(i=1;i<n;i++)
        {
            b=arr[i-1];c=arr[i];
            ar[b].push_back(c);
            ar[c].push_back(b);
        }
        a=arr[0];b=arr[n-1];pr[a]=-1;
        Q.push(a);dis[a]=0;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            for(i=0,j=ar[u].size();i<j;i++)
            {
                v=ar[u][i];
               if(dis[v]>dis[u]+1)
               {
                  pr[v]=u;dis[v]=dis[u]+1;
                  Q.push(v);
               }
               else if(dis[v]==dis[u]+1)
               {
                   if(par(u,pr[v])==1)
                    pr[v]=u;
               }
            }
        }
        printf("Case %d:\n",r);
        pr[a]=-1;
        j=0;d=b;
        while(d!=-1)
        {
            arr[j]=d;j++;
            d=pr[d];
        }
        for(i=j-1;i>=0;i--)
        {
            if(i!=j-1)printf(" ");
            printf("%d",arr[i]);
        }
        printf("\n");
        for(i=0;i<=50000;i++)
            ar[i].clear();
     }
    return 0;
}
/*
11
1 5 1 6 5 3 8 7 6 2 8
10
1 6 1 5 3 8 7 6 2 8
*/
