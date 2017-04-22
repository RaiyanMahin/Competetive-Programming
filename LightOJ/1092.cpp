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
const int inf=100000000;
int ar[11],dpp[(1<<8)+5];
char st[33];
int rec(int p,int pmsk,int cmsk,int n,int m)
{
    if(p>=n)
    {
        if(pmsk==(1<<m)-1)
            return 0;
        return inf;
    }
     int ret=inf;
    int u=(1<<m)-1;
    u=u^pmsk;
    ret=min(ret,dpp[u]+rec(p+1,cmsk^u,ar[p+1]^u,n,m));
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            sn("%s",&st);
            ar[i]=0;
            for(j=0;j<m;j++)
                if(st[j]=='*')
                ar[i]|=(1<<j);
        }
        for(i=0;i<(1<<m);i++)
            dpp[i]=inf;
        for(i=0;i<(1<<m);i++)
        {
            v=0;c=0;
            for(j=0;j<m;j++)
            {
                if(i&(1<<j))
                {
                    u=0;c++;
                    for(k=-1;k<=1;k++)
                    {
                        if(j+k>=0&&j+k<m)
                        {
                            u=u|(1<<(j+k));
                        }
                    }
                    v=v^u;
                }
            }
            dpp[v]=min(dpp[v],c);
        }
        int ans=inf;
        for(i=0;i<(1<<m);i++)
        {
            ans=min(ans,dpp[i]+rec(1,ar[0]^i,ar[1]^i,n,m));
        }
        if(ans>100000)
            pf("Case %d: impossible\n",cs++);
        else
            pf("Case %d: %d\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
