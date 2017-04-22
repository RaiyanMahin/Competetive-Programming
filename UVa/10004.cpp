

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
queue<int>Q;
map<string,int>Si;
map<int,string>Is;

int vis[1000],col[1000],p,kk;

void dfs(int d)
{

    int j,k,u;
    for(j=0,k=ar[d].size();j<k;j++)
    {
        u=ar[d][j];
       if(vis[u]==-1)
       {
           vis[u]=(vis[d]+1)%2;
           dfs(u);
       }
       else if(vis[u]==vis[d])
         p=2;
    }
}

int main()
{
    int i,j,k,r=1,s,t,sx,sy,dx,dy,m,n,a,c,b,xx,yy,x,y;
    char st[10000],*CP;
    while(sn("%d",&n)==1)
    {
        if(n==0)
            break;
            scanf("%d",&m);
            for(i=0;i<m;i++)
            {
                scanf("%d %d",&x,&y);
                ar[x].push_back(y);
                ar[y].push_back(x);
            }
            memset(vis,-1,sizeof(vis));
            // memset(col,0,sizeof(col));
        for(i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                p=1;kk=0;vis[i]=0;
                dfs(i);
                if(p%2==0)
                {
                    i=N;break;
                }

            }
        }
        if(i==N)
            printf("NOT BICOLORABLE.\n");
        else
            pf("BICOLORABLE.\n");
        for(i=0;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}






