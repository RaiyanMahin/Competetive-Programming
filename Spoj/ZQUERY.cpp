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
int a,b,bl,p,ans;
}qry[100000];
int ar[100000],maxx[100000];
bool cmp(T x,T y)
{
    if(x.bl==y.bl)
    return x.b<y.b;
    return x.bl<y.bl;
}
bool cmpp(T x,T y)
{
     return x.p<y.p;
}
vector<int>arr[100005];
int dp[100000],pos[100000],low[100000],hi[100000];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        sn("%d",&ar[i+1]);
    }
    ar[0]=0;
    dp[i]=0;
    for(i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+ar[i];
    }
    map<int,int>vis;
    f=1;
    for(i=0;i<=n;i++)
    {
        if(vis[dp[i]]==0)
        {
            vis[dp[i]]=f;f++;
            dp[i]=f-1;
        }
        else
        {
            dp[i]=vis[dp[i]];
        }
        pos[i]=arr[dp[i]].size();
        arr[dp[i]].pb(i);
    }
    h=sqrt(m+1);
    for(i=0;i<m;i++)
    {
        sn("%d %d",&qry[i].a,&qry[i].b);
        qry[i].a--;
        qry[i].b;
        qry[i].p=i;
        qry[i].ans=0;
        qry[i].bl=qry[i].a/h;
    }
    sort(qry,qry+m,cmp);
    int mxCnt=0,Lh=0,Rh=0;
    int ansx[100000];
    for(i=0;i<m;i++)
    {
        if(i==0||qry[i-1].bl!=qry[i].bl)
        {
            mxCnt=0;
            Lh=0;
            Rh=0;
            for(j=0;j<f;j++)
            {
                low[j]=10000000;
                hi[j]=0;
            }
            memset(ansx,0,sizeof(ansx));
        }
        while(Rh<=qry[i].b)
        {
            a=dp[Rh];
            low[a]=min(low[a],pos[Rh]);
            hi[a]=max(hi[a],pos[Rh]);

            Rh++;
        }
        while(Lh<qry[i].a)
        {
            if(ar[Lh]==1)
                a--;
            else b--;
            while(mxCnt>0&&maxx[mxCnt-1]>2*min(a,b))
                mxCnt--;
            if(a==b&&(mxCnt==0||maxx[mxCnt-1]<a+b))
                maxx[mxCnt++]=a+b;
            Lh++;
        }
        while(Lh>qry[i].a)
        {
            if(ar[Lh-1]==1)
                a++;
            else b++;
            if(a==b)
                maxx[mxCnt++]=a+b;
            Rh++;
            Lh--;
        }
        if(mxCnt>0)
            qry[i].ans=maxx[mxCnt-1];
    }
    sort(qry,qry+m,cmpp);
    for(i=0;i<m;i++)
    {
        pf("%d\n",qry[i].ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
