//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
//#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;

#define sz 200005

int L[sz],P[sz][25],T[sz],dp[sz],vis[25],ar[25];
vector<int> g[sz];
int cmp[sz],nc,szc[sz];
int dfs(int from,int u,int dep)
{
    cmp[u]=nc;
    szc[nc]++;
    T[u]=from;
    L[u]=dep;
    int res=1;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        res+=dfs(u,v,dep+1);
    }
    dp[u]=res;
    return res;
}

int lca_query(int N, int p, int q) //N=নোড সংখ্যা
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P)); //শুরুতে সবগুলো ঘরে -১ থাকবে
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];


      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
 }
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,h,u,v;
    //freopen(".txt","r",stdin);
//    int n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&u);
        T[i]=u;
        g[u].push_back(i);
    }
    memset(cmp,-1,sizeof(cmp));
    nc=0;
    for(i=1;i<=n;i++)
    {
        if(cmp[i]==-1)
        {
            nc++;
            szc[nc]=0;
            dfs(i,i,0);
//            lca_init(szc[nc]);
        }
    }
    for(i=1;i<=n;i++)
            printf("%d\n",dp[i]);
    lca_init(n);
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&m);
        memset(vis,0,sizeof(vis));
        for(j=0;j<m;j++)
        {
            scanf("%d",&ar[j]);
        }
        for(j=0;j<m;j++)
        {
            if(vis[j]==0)
            for(k=0;k<m;k++)
            {
                b=lca_query(n,ar[j],ar[k]);
                if(b==ar[j]) vis[k]=1;
            }
        }
        int res=0;
        for(j=0;j<m;j++)
        {
            if(vis[j]==0)
                res+=dp[ar[j]];
        }
        printf("%d\n",res);
    }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
