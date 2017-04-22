//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
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
int a;
};

int bit[1005][1005],ar[1005][1005],mx=1001,my=1001;


void update(int x,int y)
{
    x++;y++;
    while(x<=mx)
    {
        int y1=y;
        while(y1<=my)
        {
            bit[x][y1]++;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}

int read(int x,int y)
{
    int s=0;x++;y++;
       while(x>0)
    {
        int y1=y;
        while(y1>0)
        {
            s+=bit[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    }
    return s;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%d",&t);
     while(t--)
     {
         int q;
         scanf("%d",&q);
        for(i=0;i<=1004;i++)
        {
            for(j=0;j<=1004;j++)
                bit[i][j]=0,ar[i][j]=0;
        }
        printf("Case %d:\n",cs++);
         while(q--)
         {
             scanf("%d",&f);
             if(f==0)
             {
                 scanf("%d %d",&u,&v);
                 if(ar[u][v]==0)
                 {
                     update(u,v);ar[u][v]=1;
                 }
             }
             else
             {
                 int x1,x2,y1,y2,ans=0;
                 scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                 ans+=read(x2,y2);
                 ans-=read(x1-1,y2);
                 ans-=read(x2,y1-1);
                 ans+=read(x1-1,y1-1);
                 printf("%d\n",ans);
             }
         }

     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

