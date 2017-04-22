//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
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
int X[402],Y[402],sx,sy,a,dp[20][1<<16];
int rec(int p,int mask,int x,int y,int pos)
{
    if(p==a)
    {
        return max(abs(sx-x),abs(sy-y));
    }
    int &ret=dp[pos][mask];
    if(ret!=-1)
        return ret;
    ret=N;
    for(int i=0;i<a;i++)
    {
        if((mask&(1<<i))==0)
        {
            int v=max(abs(X[i]-x),abs(Y[i]-y));
            ret=min(ret,rec(p+1,mask|(1<<i),X[i],Y[i],i)+v);
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,b,c,d,e,f,g,h,u,v;
    char st[25];
      scanf("%d",&t);
      for(r=1;r<=t;r++)
      {
          scanf("%d %d",&n,&m);
          a=0;
          for(i=0;i<n;i++)
          {
              scanf("%s",&st);
              for(j=0;j<m;j++)
              {
                  if(st[j]=='g')
                  {
                     X[a]=i;Y[a++]=j;
                  }
                  if(st[j]=='x')
                    sx=i,sy=j;
              }
          }
          memset(dp,-1,sizeof(dp));
          printf("Case %d: %d\n",r,rec(0,0,sx,sy,19));
      }
    return 0;
}


