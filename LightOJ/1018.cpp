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
int x,y;
}ar[17];
int dp[1<<17];
int check(int a,int b,int c)
{
    int u,v;
    u=(ar[c].x-ar[a].x)*(ar[a].y-ar[b].y);
    v=(ar[c].y-ar[a].y)*(ar[a].x-ar[b].x);
    if(u==v)
        return 1;
    return 0;
}

int rec(int mask,int n)
{
    int i,j,k=0;
    int &ret=dp[mask];
    if(ret!=-1)
        return ret;
    ret=10000;
    for(i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))k++;
    }
    if(k==1)
        return 1;
    for(i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
        {
            int temp=mask|(1<<i);

            for(j=i+1;j<n;j++)
            {
                int use=mask|(1<<i);
                if(!(temp&(1<<j)))
                {
                     temp=temp|(1<<j);
                     use=use|(1<<j);

                     for(k=0;k<n;k++)
                     {
                         if((temp&(1<<k))==0&&check(i,j,k)==1)
                         {
                            temp=temp|(1<<k);
                             use=use|(1<<k);
                         }
                     }
                     ret=min(ret,1+rec(use,n));
                }
            }
           break;
        }

    }
    return ret;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].x,&ar[i].y);
        }
        memset(dp,-1,sizeof(dp));
        dp[(1<<n)-1]=0;
      //  printf("%d\n",(1<<n));
        printf("Case %d: %d\n",r,rec(0,n));
    }
    return 0;
}


