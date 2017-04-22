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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
struct T{
char st[200];
int a;
}ar[22],tem[22];
int vis[20];
vector<int>Ed[22];
bool cmp(T x,T y)
{
    return strcmp(x.st,y.st)<0;
}
int contain(int a,int b)
{
    int i,j,l=strlen(ar[a].st),m=strlen(ar[b].st);
    if(l<m)return 0;
    for(i=0;i+m<l;i++)
    {
        for(j=0;j<m;j++)
        {
            if(ar[a].st[i+j]!=ar[b].st[j])
                break;
        }
        if(j==m)
            return 1;
    }
    return 0;
}
int mat[20][20],dp[17][(1<<15)+5];
int match(int a,int b)
{
    int i,j,l=strlen(ar[a].st),m=strlen(ar[b].st);
    for(i=0;i<l;i++)
    {
        for(j=0;j<m&&j+i<l;j++)
        {
            if(ar[a].st[i+j]!=ar[b].st[j])
                break;
        }
        if(j+i==l)
            return m-j;
    }
    return m;
}
int rec(int p,int msk,int n)
{
    if(msk==(1<<n)-1)
    {
        dp[p][msk]=0;
         return 0;
    }

    int &ret=dp[p][msk];
    if(ret!=-1)
        return ret;
    ret=100000;
    for(int i=0;i<n;i++)
    {
        if((msk&(1<<i))==0)
        ret=min(ret,mat[p][i]+rec(i,msk|(1<<i),n));
    }
    return ret;
}
void rec2(int p,int msk,int n,int u)
{
    if(msk==(1<<n)-1)
        return;
    for(int i=0;i<Ed[p].size();i++)
    {
        int v=Ed[p][i];
        if(u-mat[p][v]==dp[v][msk|(1<<v)]&&(msk&(1<<v))==0)
        {
            for(int l=strlen(ar[v].st),j=l-mat[p][v];j<l;j++)
                pf("%c",ar[v].st[j]);
            rec2(v,msk|(1<<v),n,u-mat[p][v]);
            break;
        }
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%s",&ar[i].st);
            vis[i]=1;
        }
        memset(mat,0,sizeof(mat));
        for(i=0;i<n;i++)
        {
            if(vis[i])
            for(j=0;j<n;j++)
            {
                if(vis[j]&&i!=j)
                {
                    if(contain(i,j))
                        vis[j]=0;
                }
            }
        }
        for(i=j=0;i<n;i++)
        {
            if(vis[i]==1)
            {
               if(i!=j)
               strcpy(ar[j].st,ar[i].st);
               j++;
            }
        }
        n=j;
        sort(ar,ar+n,cmp);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                    mat[i][j]=match(i,j);
            }
        }
        for(i=0;i<n;i++)
            mat[n][i]=strlen(ar[i].st);
        memset(dp,-1,sizeof(dp));
        u=rec(n,0,n);
      //  pf("%d\n",u);
        for(i=0;i<n;i++)
        {
            h=0;
            for(j=0;j<n;j++)
            {
                 if(i==j)
                    continue;
                l=strlen(ar[j].st);
                f=0;tem[h].a=j;
                for(k=l-mat[i][j];k<=l;k++)
                {
                    tem[h].st[f++]=ar[j].st[k];
                }
                h++;
            }
            sort(tem,tem+h,cmp);
            for(j=0;j<h;j++)
                Ed[i].pb(tem[j].a);
        }
        for(i=0;i<n;i++)
            Ed[n].pb(i);
        pf("Case %d: ",cs++);
        rec2(n,0,n,u);
        pf("\n");
        for(i=0;i<20;i++)
            Ed[i].clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

