
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
#define esp 10e-10
typedef long long int ll;
using namespace std;


int main()
{
    int i,j,k,t,r,m,n;
    double a,x,y,b,c,s,l,d,e,f,g,h,u,v,md;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lf%lf%lf",&x,&y,&c);
          l=0;
          h=x;
         while(fabs(l-h)>esp)
         {
              md=(l+h)/2;
             a=acos(md/x);
             b=acos(md/y);
             u=c/tan(a);
             v=c/(tan(b));
             if(u+v<md)
                l=md;
             else
                h=md;
         }
         printf("Case %d: %.9lf\n",r,l);
     }

    return 0;
}

