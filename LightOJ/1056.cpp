
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
         scanf("%lf : %lf",&x,&y);
          l=0;
          h=400;
         while(fabs(l-h)>esp)
         {
              md=(l+h)/2;

             v=b=(y/x)*md;
             b=((b)*(b))+((md)*(md));
             b=sqrt(b);
             b=b/2;
             a=2*asin(v/(2*b));
             u=2*a*b;

             if(u+md+md<400)
                l=md;
             else
                h=md;
         }
         printf("Case %d: %.8lf %.8lf\n",r,l,(y/x)*l);
     }

    return 0;
}

