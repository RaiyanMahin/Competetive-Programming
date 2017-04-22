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
         scanf("%lf%lf%lf",&a,&b,&c);
          l=0.0000000001;
          h=4;
          s=(1+(b*c))*a;
         while(fabs(l-h)>esp)
         {
             md=(l+h)/2;
             x=a/(2*sin(md/2));
             y=x*md;
             if(y<s)
                l=md;
             else
                h=md;
         }
         b=0.5*sqrt((4*x*x)-(a*a));
         printf("Case %d: %.9lf\n",r,x-b);
     }

    return 0;
}


