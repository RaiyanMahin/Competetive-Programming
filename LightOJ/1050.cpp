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
bool dpp[505][505];
double dp[505][505];


double rec(int r,int b)
{
    double &ret=dp[r][b];
    if(dpp[r][b]==0)
    {
     if(b<=0)
       {
           if(r==0)
              return 1.0;
           else
              return 0.0;
       }
       dpp[r][b]=1;ret=0.0;
       double v=(double)((double)r/(double)(r+b));
        if(r>0)
         ret=ret+(rec(r-1,b-1)*v);
         //pf("%lf\n",v);
        v=(double)((double)b/(double)(r+b));
       if(b>1)
          ret=ret+(rec(r,b-2)*v);
       else if(b==1)
          ret=ret+(rec(r,b-1)*v);
         //  pf("%lf\n",ret);
    }

    return ret;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u;
    scanf("%d",&t); memset(dpp,0,sizeof(dpp));
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&r,&b);
        printf("Case %d: %.10lf\n",i,rec(r,b));
    }
    return 0;
}



