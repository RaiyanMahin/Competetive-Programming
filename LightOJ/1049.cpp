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
#define N 1000000
#define sn scanf
#define pf printf
#define inf 1<<30;

typedef long long int ll;
using namespace std;


vector<int>ar[500];
queue<int>Q;
int dis[200][200],vis[200];
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        v=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            v+=c;
            dis[a][b]=0;dis[b][a]=c;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        u=0;a=1;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<2;j++)
            {
                if(vis[ar[a][j]]==0)
                {
                    u+=dis[a][ar[a][j]];
                    a=ar[a][j];vis[a]=1;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",r,(u>v-u)?v-u:u);
        for(i=1;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}

