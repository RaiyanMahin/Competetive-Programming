//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 100000000
#define Inf 200000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

int ar[1000][1000];
vector<int>cost[1000];
queue<int>Q;
map<char,int>Si;
map<int,string>Is;
int dis[105][105],Ya[105][105];


int main()
{
    int i,j,k,l,r=1,t,n,m,s,sc,d,dc,a,b,E;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if(i==j)
                dis[i][j]=0;
            else
                dis[i][j]=Inf;

        }

    for(i=0;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        if(i==m)break;
        dis[a][b]=dis[b][a]=1;
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }

//    for(i=0;i<n;i++)
//        {
//            for(j=0;j<n;j++)
//            {
//                 pf("%4d",dis[i][j]);
//            }
//            pf("\n");
//        }

    l=Inf;s=0;
    for(i=0;i<n;i++)
    {
        l=dis[a][i]+dis[i][b];
        if(l>s)
            s=l;
    }
    pf("Case %d: %d\n",r,s);

    }
    return 0;
}




