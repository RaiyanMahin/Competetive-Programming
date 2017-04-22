
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
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
int a;
};
const int sz=(1<<22);
queue<int>Q;
vector<int>ans;
int id[sz],next[sz],vis[sz],ng[35],step[sz],par[sz];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    for(i=0;i<22;i++)
    {
        id[1<<i]=i;
    }
    while(sn("%d %d",&n,&m)!=EOF&&n+m)
    {
        memset(ng,0,sizeof(ng));
        for(i=0;i<m;i++)
        {
            sn("%d %d",&u,&v);
            ng[u]|=(1<<v);
            ng[v]|=(1<<u);
        }
        next[0]=0;vis[0]=0;par[0]=-1;
        for(i=1;i<(1<<n);i++)
        {
            next[i]=0;
            next[i]=next[i-(i&-i)]|ng[id[(i&-i)]];
            //pf(" %d",next[i]);
            vis[i]=0;
            par[i]=-1;
        }
        Q.push((1<<n)-1);vis[(1<<n)-1]=1;
        while(!Q.empty())
        {
            u=Q.front();Q.pop();
            if(u==0)
            {
                break;
            }
            a=u;
            while(a>0)
            {
                v=next[u^(a&-a)];
                if(vis[v]==0)
                {
                    vis[v]=1;
                    step[v]=id[(a&-a)];
                    par[v]=u;
                    Q.push(v);
                }
                a-=(a&-a);
            }
        }
        while(!Q.empty())
            Q.pop();
        if(vis[0]==0)
        {
            pf("Impossible\n");
        }
        else
        {
           ans.clear();
            u=0;
            while(par[u]!=-1)
            {
                ans.pb(step[u]);
                u=par[u];
            }
            pf("%d:",ans.size());
            for(i=ans.size()-1;i>=0;i--)
            {
                pf(" %d",ans[i]);
            }
            pf("\n");
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

