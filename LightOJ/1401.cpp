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
int a,b;
}ans[10000];
vector<int>ar[55],arr[55][3];
int dp[55][55][55],vis[100005],dpp[55];
int grund(int st,int en,int p)
{
    int &ret=dp[st][en][p];
    if(ret!=-1)
        return ret;
    ret=0;
    set<int>vs,ss;
    int s=0;
    for(int i=st;i<=en;i++)
    {
       if(ss.count(ar[p][i])==0)
       {
           ss.insert(ar[p][i]);
           s=0;
           for(int j=st;j<=en;j++)
           {
               if(ar[p][j]>=ar[p][i])
                continue;
               int h=j;
               for(int k=j;k<=en;k++)
               {
                   j=k;
                   if(ar[p][k]>=ar[p][i])
                   {
                       s=s^grund(h,k-1,p);
                       break;
                   }
                   if(k==en)
                   {
                      s=s^grund(h,k,p);
                   }
               }

           }
           vs.insert(s);
          if(en-st==ar[p].size()-1)
          {
              arr[p][0].pb(ar[p][i]);
             // pf("%d ",ar[p][i]);
          }
       }
    }
    for(int i=0;;i++)
        if(vs.count(i)==0)
        return ret=i;
}
bool cmp(T x,T y)
{
    if(x.a==y.a)
        return x.b<y.b;
        return x.a<y.a;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%d",&t);
    memset(vis,0,sizeof(vis));
    d=1;
    while(t--)
    {
        sn("%d",&n);
        memset(dp,-1,sizeof(dp));
        g=0;
        for(i=0;i<n;i++)
        {
            sn("%d",&m);
            ar[i].clear();
            for(j=0;j<m;j++)
            {
                sn("%d",&a);
                ar[i].pb(a);
            }
            dpp[i]=grund(0,ar[i].size()-1,i);
        }
        f=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<arr[i][0].size();j++)
            {
                g=0;
                for(k=0;k<ar[i].size();k++)
                {
                    if(ar[i][k]>=arr[i][0][j])continue;
                    for(c=k;c<ar[i].size();c++)
                    {
                        if(ar[i][c]>=arr[i][0][j])
                        {
                            g=g^grund(k,c-1,i);break;
                        }
                        if(c==ar[i].size()-1)
                        {
                            g=g^grund(k,c,i);
                        }
                    }
                    k=c;
                }
                 for(k=0;k<n;k++)
                 {
                     if(k!=i)g=g^dpp[k];
                 }

                 if(g==0)
                 {
                     ans[f].a=i+1,ans[f++].b=arr[i][0][j];
                 }
                d++;
            }
        }
        sort(ans,ans+f,cmp);
        if(f==0)
            pf("Case %d: Genie\n",cs++);
        else
        {
            pf("Case %d: Aladdin\n",cs++);
            for(i=0;i<f;i++)
            {
                pf("(%d %d)",ans[i].a,ans[i].b);
            }
            pf("\n");
        }
        for(i=0;i<=n;i++)
        {
            ar[i].clear();
            arr[i][0].clear();
            arr[i][1].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/



