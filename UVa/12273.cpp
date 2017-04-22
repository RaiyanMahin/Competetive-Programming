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
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
vector<int>Ed[10005],ty[10005];
char st[10005];
int vis[10005],cnt=0;
void dfs(int u)
{
    vis[u]=1;
    ty[cnt].pb(u);
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}
int ckk[10005],ar[10005],arr[10005],viss[10005],dir[]={11,7,14,13},id[200],val[10005];
vector<int>fnd;
int check(int u,int v,int n)
{
    memset(ckk,0,sizeof(ckk));
    int i,a,b,c,d;
    for(i=0;i<n;i++)
    {
        val[i]=fnd[i];ckk[i]=0;
    }
    val[u]&=v;
    queue<int>Q;
    ckk[u]=1;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(i=0;i<ty[u].size();i++)
        {
            a=ty[u][i];
            b=u;
            if(val[b]!=1<<id[st[a]])
            {
                c=ty[u][i]-1;
                if(c>=0&&viss[c]>=0&&vis[viss[c]]==0)
                {
                    d=viss[c];
                    val[d]&=(1<<id[st[c]]);
                    if(ckk[d]==0)
                    {
                        ckk[d]=1;
                        Q.push(d);
                    }
                }
                c=ty[u][i]+1;
                if(c>=0&&viss[c]>=0&&vis[viss[c]]==0)
                {
                    d=viss[c];
                    val[d]&=(1<<id[st[c]]);
                    if(ckk[d]==0)
                    {
                        ckk[d]=1;
                        Q.push(d);
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(val[i]==0)
        {
            return 0;
        }
    }
    for(i=0;i<n;i++)
    {
        if(ckk[i]==1)
            vis[i]=1;
    }
    return 1;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    id['A']=0;id['G']=1;
    id['T']=2;id['C']=3;
    //freopen(".txt","r",stdin);
    while(sn("%d %d",&n,&m)!=EOF&&n+m)
    {
        sn("%s",&st);
        for(i=0;i<n;i++)
        {
            arr[i]=dir[id[st[i]]];
        }
        for(i=0;i<m;i++)
        {
            sn("%d:",&h);
            for(j=0;j<h;j++)
            {
                sn("%d",&ar[j]);
            }
            a=0;b=h-1;
            while(a<b)
            {
                Ed[ar[a]].pb(ar[b]);
                Ed[ar[b]].pb(ar[a]);
                a++;b--;
            }
        }
        cnt=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                if(ty[cnt].size()<=1)
                {
                    ty[cnt].clear();
                }
                else
                {
                    cnt++;
                }
            }
        }
        s=0;
        memset(viss,-1,sizeof(viss));
        for(i=0;i<cnt;i++)
        {
            a=15;
            for(k=0;k<ty[i].size();k++)
            {
                a=a&arr[ty[i][k]];
                viss[ty[i][k]]=i;
            }
            if(a==0)s=-1;
            fnd.pb(a);
        }
        memset(vis,0,sizeof(vis));
        if(s==0)
        for(i=0;i<cnt;i++)
        {
            if(vis[i]==0)
            {
                for(j=0;j<4;j++)
                {
                    if((fnd[i]&(1<<j))&&check(i,1<<j,cnt)==1)
                    {
                         break;
                    }
                }
                if(j==4)
                   {
                        s=-1;
                        break;
                   }
            }
        }
        if(s==-1)
            pf("NO\n");
        else
            pf("YES\n");
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
        }
        for(i=0;i<=cnt;i++)
        {
            ty[i].clear();
        }
        fnd.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

