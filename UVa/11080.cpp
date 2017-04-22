


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

int vis[1000],col[1000],p,kk,k;

void dfs(int d)
{
    int j,k1,u;
    for(j=0,k1=ar[d].size();j<k1;j++)
    {
        u=ar[d][j];
       if(vis[u]==-1)
       {
           vis[u]=(vis[d]+1)%2;
           if(vis[u]==0)
            k++;
           dfs(u);
       }
       else if(vis[u]==vis[d])
         p=2;
    }
}

int main()
{
    int i,j,r=1,s,t,sx,sy,dx,dy,m,n,a,c,b,xx,yy,x,y;
    char st[10000],*CP;
    sn("%d",&t);
    while(t--)
    {

            scanf("%d %d",&n,&m);
            for(i=0;i<m;i++)
            {
                scanf("%d %d",&x,&y);
                ar[x].push_back(y);
                ar[y].push_back(x);
            }
            memset(vis,-1,sizeof(vis));
            memset(col,0,sizeof(col));
         c=0;
        for(i=0;i<n;i++)
        {

            if(col[i]==0)
            {
                 a=0;b=0;
                p=1;vis[i]=0;
                dfs(i);
                if(p%2==0)
                {
                    i=N;break;
                }
                for(j=0;j<n;j++)
                {
                    if(vis[j]==0&&col[j]==0)
                        a++,col[j]=1;
                    if(vis[j]==1&&col[j]==0)
                        b++,col[j]=1;
                }
               // pf("%d   %d\n",a,b);
                if(b==0)
                    b=a;
                if(a==0)
                    a=b;
                c+=(a<b)?a:b;
            }

        }

        if(i==N)
            printf("-1\n");
        else
            pf("%d\n",c);
        for(i=0;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}






