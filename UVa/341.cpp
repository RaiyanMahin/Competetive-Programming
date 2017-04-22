
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
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

vector<int>ar[1000];
vector<int>cost[1000];
queue<int>Q;
map<string,int>Si;
map<int,string>Is;
int P[10000],dis[10000];

void path(int d)
{
    if(d==-1)
        return;
    path(P[d]);
    printf(" %d",d);
}

int main()
{
    int i,j,k,l,r=1,n,m,s,sc,d,dc,a,b;
    while(sn("%d",&n)==1)
    {
        if(n==0)break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d %d",&a,&b);
                ar[i].push_back(a);
                cost[i].push_back(b);
            }
        }
        scanf("%d %d",&s,&d);
        for(i=0;i<=n;i++)
            dis[i]=100000000;
           Q.push(s);dis[s]=0;P[s]=-1;
        while(!Q.empty())
        {
            sc=Q.front();Q.pop();
            for(i=0,j=ar[sc].size();i<j;i++)
            {
                k=ar[sc][i];l=cost[sc][i];
                if(dis[k]>dis[sc]+l)
                {
                    dis[k]=dis[sc]+l;
                    P[k]=sc;
                    Q.push(k);
                }
            }
        }
        pf("Case %d: Path =",r++);
        path(d);
        printf("; %d second delay\n",dis[d]);
        for(i=0;i<=n;i++)
            ar[i].clear(),cost[i].clear();
    }
    return 0;
}







