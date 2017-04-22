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
int a;
};
int dp[101][(1<<8)+1][(1<<8)+1];
int A=7,B=3;

int dpp[(1<<8)+1][(1<<8)+1];
vector<int>rrc,mov[(1<<8)+5];
void rec2(int p,int n)
{
    if(p>=n)
    {
        int i,s=0,a=0,b=0,c=0;
        for(i=0;i<rrc.size();i++)
        {
            if(rrc[i]==0&&s+1<=rrc.size())
            {
                s++;
            }
            if(rrc[i]==1&&s+3<=rrc.size())
            {
                a|=(A<<s);c++;s+=3;
            }
            if(rrc[i]==2&&s+2<=rrc.size())
            {
                a|=(B<<s);
                b|=(B<<s);c++;s+=2;
            }
        }
        dpp[a][b]=max(dpp[a][b],c);
        return;
    }
    for(int i=0;i<3;i++)
    {
        rrc.pb(i);
        rec2(p+1,n);
        rrc.pop_back();
    }
}
int ar[1000];
int rec(int p,int cur,int nxt,int n,int m)
{
    if(p>=n)
        return 0;
    int &ret=dp[p][cur][nxt];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=rec(p+1,nxt,ar[p+2],n,m);
    if(p+1<n)
    {
        for(int i=((1<<m)-1)^cur,j=i;i>0;i=j&(i-1))
        {
            if((nxt&i)==0)
            for(int k=0;k<mov[i].size();k++)
            {
                if((ar[p+2]&mov[i][k])==0)
                {
                    ret=max(ret,dpp[i][mov[i][k]]+rec(p+1,nxt|i,mov[i][k]|ar[p+2],n,m));
                }
            }
        }
    }
    return ret;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    memset(dpp,-1,sizeof(dpp));
    rec2(0,8);
    for(i=0;i<(1<<8);i++)
    {
        for(j=0;j<(1<<8);j++)
        {
            if(dpp[i][j]!=-1)
                mov[i].pb(j);
        }
    }
    while(t--)
    {
        sn("%d %d",&m,&n);
        char st[1000];
        memset(ar,0,sizeof(ar));
        for(i=0;i<m;i++)
        {
            sn("%s",&st);
            for(j=0;j<n;j++)
            {
                if(st[j]=='#')
                ar[j]|=(1<<i);
            }
            ar[j]|=(1<<i);
        }
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,rec(0,ar[0],ar[1],n,m));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

