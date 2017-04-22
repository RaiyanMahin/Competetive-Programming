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
vector<int>ar[100];
int vis[100];

void dfs(int u,int n)
{
    vis[u]=1;
    int i,v,j=ar[u].size();
    for(i=0;i<j;i++)
    {
        v=ar[u][i];
        if(!vis[v])
        {
            dfs(v,n);
        }
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;
    char ch[5],st[5];
    scanf("%d",&t);
   scanf("\n");
    for(r=1;r<=t;r++)
    {
        gets(ch);
        n=ch[0]-'A';
        for(i=0;i<=n;i++)
        {
            ar[i].clear();
        }
        memset(vis,0,sizeof(vis));
         while(gets(st)&&st[0]){
            ar[st[0]-'A'].push_back(st[1]-'A');
            ar[st[1]-'A'].push_back(st[0]-'A');
        }

        for(i=0,k=0;i<=n;i++)
        {
            if(!vis[i])
            {
                k++;
                dfs(i,n);
            }
        }

        printf("%d\n",k);
         if(r!=t)
            printf("\n");
    }
    return 0;
}

