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
const int maxn=205;
int A[maxn],B[maxn],vis[maxn];
vector<int>adj[maxn];
int tp;
bool kuhn(int u)
{
    int i,j=adj[u].size(),v;
    if(A[u]==0)
        return false;
    for(i=0;i<j;i++)
    {
        v=adj[u][i];
        if(vis[v]!=tp&&A[v]==-1)
        {
            vis[v]=tp;
            if(B[v]==-1||kuhn(B[v]))
            {
                B[v]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);tp=1;
    memset(vis,0,sizeof(vis));
    while(t--)
    {
        sn("%d",&n);
        set<int>ck;
        vector<int>ar;
        for(i=j=0;i<n;i++)
        {
            sn("%d",&a);
            if(ck.count(a)==0)
            {
                ck.insert(a);
                ar.pb(a);
            }
        }
        n=ar.size();
        sort(ar.begin(),ar.end());
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(ar[j]%ar[i]==0)
                {
                    adj[i].pb(n+j);
                }
            }
          }
            memset(A,-1,sizeof(A));
            memset(B,-1,sizeof(B));
            int max_match=0;
            for(i=0;i<n;i++)
            {
                ++tp;
                if(kuhn(i))
                {
                    max_match++;
                }
                ++tp;
            }
            g=n;
            for(i=n-1;i>=0;i--)
            {
                memset(B,-1,sizeof(B));
                h=0;A[i]=A[i+n]=0;g--;
                for(j=0;j<n;j++)
                {
                    ++tp;
                    if(A[j]==-1&&kuhn(j))
                    {
                        h++;
                    }
                    ++tp;
                }
                if(g-h!=n-max_match)
                {
                    A[i]=A[i+n]=-1;g++;
                }
            }
            pf("Case %d:",cs++);
            for(i=0;i<n;i++)
            {
                if(A[i]==-1)
                {
                    pf(" %d",ar[i]);
                }
            }
            pf("\n");
            for(i=0;i<203;i++)
                adj[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


