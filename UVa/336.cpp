//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int dis[N];
int vis[N];
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,aa[1000];
    vector<int>ar[100005];
    queue<int>Q;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
            memset(dis,0,sizeof(dis));
        m=0;

        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            ar[a].push_back(b);
            ar[b].push_back(a);
            if(dis[a]==0)
                {
                    aa[m]=a;
                    m++,dis[a]=a;
                }
            if(dis[b]==0)
                {
                    aa[m]=b;
                    m++,dis[b]=b;
                }
        }
        for(;;)
        {
            scanf("%d %d",&s,&t);
            if(s==0&&t==0)
                break;
                memset(dis,N,sizeof(dis));
            Q.push(s);dis[s]=0;c=0;
            while(!Q.empty())
            {
                d=Q.front();
                c++;
                Q.pop();
                for(i=0,j=ar[d].size();i<j;i++)
                {
                    h=ar[d][i];
                    if(dis[h]>dis[d]+1)
                    {
                        dis[h]=dis[d]+1;
                        if(dis[h]<=t)
                            Q.push(h);
                    }
                }
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",r++,m-c,s,t);
        }

       for(i=0;i<m;i++)
            ar[aa[i]].clear();
    }
    return 0;
}

