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
char st[55][55];
int dis[55][55],R[]={0,0,1,-1},C[]={-1,1,0,0};
vector<pair<int,int> >ar;
void bfs(int sx,int sy,int n,int m)
{
    int i,j,k,l,xx,yy,x,y;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            dis[i][j]=1000000;
        }
    }
    queue<int>Q;
    Q.push(sx);
    Q.push(sy);
    dis[sx][sy]=0;
    while(!Q.empty())
    {
        x=Q.front();Q.pop();
        y=Q.front();Q.pop();
        k=0;
        if(st[x][y]>='0'&&st[x][y]<='9')
            k=1;
        for(i=0;i<4;i++)
        {
            xx=x+R[i];
            yy=y+C[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m)
            {
                l=abs(st[xx][yy]-st[x][y]);
                if(k==0&&dis[xx][yy]>dis[x][y]+2)
                {
                    dis[xx][yy]=dis[x][y]+2;
                    Q.push(xx);
                    Q.push(yy);
                }
                else if(k==1&&l==0&&dis[xx][yy]>dis[x][y]+1)
                {
                    dis[xx][yy]=dis[x][y]+1;
                    Q.push(xx);
                    Q.push(yy);
                }
                else if(k==1&&l==1&&dis[xx][yy]>dis[x][y]+3)
                {
                    dis[xx][yy]=dis[x][y]+3;
                    Q.push(xx);
                    Q.push(yy);
                }
                else if(k==1&&(st[xx][yy]=='X'||st[xx][yy]=='$')&&dis[xx][yy]>dis[x][y]+2)
                {
                    dis[xx][yy]=dis[x][y]+2;
                    Q.push(xx);
                    Q.push(yy);
                }
            }
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
        sn("%d %d",&n,&m);
        ar.clear();
        for(i=0;i<n;i++)
        {
            sn("%s",&st[i]);
            for(j=0;j<m;j++)
            {
                if(st[i][j]=='X')
                {
                    a=i;b=j;
                }
                else if(st[i][j]=='$')
                {
                    ar.pb(make_pair(i,j));
                }
            }
        }
        h=ar.size();
        s=100000;
        bfs(a,b,n,m);

        g=(1<<h)-1;
        for(i=0;i<=g;i++)
        {
            a=0;b=0;c=0;d=0;
            for(j=0;j<h;j++)
            {
                if(i&(1<<j))
                {
                    a=a+2*dis[ar[j].first][ar[j].second];
                    if(dis[ar[j].first][ar[j].second]>c)
                        c=dis[ar[j].first][ar[j].second];
                }
                else
                {
                     b=b+2*dis[ar[j].first][ar[j].second];
                    if(dis[ar[j].first][ar[j].second]>d)
                        d=dis[ar[j].first][ar[j].second];
                }

            }
             a=a-c;
             b=b-d;
             s=min(s,max(a,b));
        }
        if(s>=100000)
            pf("-1\n");
        else
        pf("%d\n",s);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

