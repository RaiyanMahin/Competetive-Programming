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
vector<int>Ed[2000];
int vis[2000],ar[2000],lv[2000],par[2000],loc[2000][2000];
void dfs(int  u,int l)
{
    lv[u]=l;
    int i,j=Ed[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=Ed[u][i];
        if(lv[v]==-1)
        {
            par[v]=u;
            dfs(v,l+1);
        }
    }
}
vector<int>task,path;
int key=-1,arr[2000];
int source(int s)
{
    int i,j,v=task.back(),x=s,y=v;
    vector<int>A,B;
    while(lv[x]>lv[y])
    {
        A.pb(x);x=par[x];
    }
    while(lv[x]<lv[y])
    {
        B.pb(y);y=par[y];
    }
    while(x!=y)
    {
        A.pb(x);B.pb(y);x=par[x];y=par[y];
    }
    A.pb(x);
    for(i=B.size()-1;i>=0;i--)
    {
        A.pb(B[i]);
    }
    for(i=0;i<A.size();i++)
    {
      //  pf("%d\n",A[i]);
        if(s==A[i])
        {
            if(path.size()>0)
            {
                if(path.back()!=s)
                    path.pb(s);
            }
            else
                path.pb(s);
        }
        else
        {
            if(loc[s][A[i]]==-1)
            {
                path.pb(A[i]);s=A[i];
            }
            else
            {
                if(key==loc[s][A[i]])
                {
                    loc[s][A[i]]=loc[A[i]][s]=-1;key=-1;
                    path.pb(A[i]);s=A[i];
                }
                else
                {
                    task.pb(ar[loc[s][A[i]]]);
                    if(vis[task.back()]==1)
                    {
                        return -1;
                    }
                    vis[task.back()]=1;
                    return s;
                }
            }
        }
    }
    return s;
}
int found(int s)
{
   int i,j,k,l,m,n,a,b,c;
   while(task.size()>0)
   {
       s=source(s);
       if(s==-1)
        return -1;
       if(s==task.back())
       {
           key=arr[s];
           task.pop_back();
       }
   }
   return 0;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%d %d %d %d",&n,&c,&s,&d)!=EOF&&n+c+s+d)
    {
        memset(arr,-1,sizeof(arr));
        for(i=0;i<c;i++)
        {
            sn("%d",&ar[i]);
            arr[ar[i]]=i;
        }
        for(j=0;j<n-1;j++)
        {
            sn("%d %d %d",&u,&v,&l);
            Ed[u].pb(v);
            Ed[v].pb(u);
            loc[u][v]=l;
            loc[v][u]=l;
        }
        memset(lv,-1,sizeof(lv));
        memset(par,-1,sizeof(par));
        dfs(s,0);task.clear();path.clear();
        memset(vis,0,sizeof(vis));
        vis[d]=1;
        task.pb(d);key=-1;
        s=found(s);
        if(s==-1)
        {
            pf("Impossible\n");
        }
        else
        {
            pf("%d:",path.size()-1);
            for(i=0;i<path.size();i++)
            {
                pf(" ");
                pf("%d",path[i]);
            }
            pf("\n");
        }
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

