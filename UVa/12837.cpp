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

typedef long long int ll;
using namespace std;
struct T{
int a,nxt[27];
}tree[1000050];
char st[1005],su[50],pre[50];
int vis[1005];
vector<int >pos[500050];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
   // freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%s",&st);
        memset(tree,-1,sizeof(tree));
        memset(vis,-1,sizeof(vis));
        n=strlen(st);
       int  cnt=1;
        int root=0;
        for(i=0;i<n;i++)
        {
            root=0;
            for(j=i;j<n;j++)
            {
                a=st[j]-'a';
                if(tree[root].nxt[a]==-1)
                {
                    if(vis[i]==-1)vis[i]=j;
                    tree[root].nxt[a]=cnt;
                    tree[root].a=0;
                    root=cnt;
                    cnt++;
                }
                else
                    root=tree[root].nxt[a];
            }
        }
        for(i=0;i<n;i++)
        {
            int root=0;
            for(j=i;j<n&&j<i+11;j++)
            {
                a=st[j]-'a';
                root=tree[root].nxt[a];
                pos[root].pb(i);
            }
        }
        int q;
        pf("Case %d:\n",cs++);
        sn("%d",&q);
        while(q--)
        {
            sn("%s %s",&pre,&su);
            a=strlen(pre);
            b=strlen(su);
            root=0;
            u=-1;v=-1;
            for(i=0;i<a;i++)
            {
                if(tree[root].nxt[pre[i]-'a']==-1)
                    break;
                if(i==a-1)
                {
                    u=tree[root].nxt[pre[i]-'a'];
                }
                root=tree[root].nxt[pre[i]-'a'];
            }
            root=0;
            for(i=0;i<b;i++)
            {
                if(tree[root].nxt[su[i]-'a']==-1)
                    break;
                if(i==b-1)
                {
                    v=tree[root].nxt[su[i]-'a'];
                }
                root=tree[root].nxt[su[i]-'a'];
            }
           if(u==-1||v==-1)
           {
               pf("0\n");
           }
           else
           {
                int ans=0;
                for(i=j=0;i<pos[u].size();i++)
                {
                   // pf("i=%d %d\n",pos[u][i],vis[pos[u][i]]);
                    if(vis[pos[u][i]]!=-1)
                    for(;j<pos[v].size();j++)
                    {
                       // pf("j=%d\n",pos[v][j]);
                        if(max(vis[pos[u][i]]-b+1,pos[u][i])<=pos[v][j]&&pos[u][i]+a<=pos[v][j]+b)
                        {
                            ans+=(pos[v].size()-j);
                            break;
                        }
                    }
                }
                pf("%d\n",ans);
           }
        }
        for(i=0;i<=cnt;i++)
            pos[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

