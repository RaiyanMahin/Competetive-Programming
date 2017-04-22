
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
#define esp 10e-9
typedef long long int ll;
using namespace std;


int main()
{
    int i,j,k,t,r,m,n;
    double a,b,c,s,l,d,e,f,g,h,u,v,md;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lf %lf %lf %lf",&c,&b,&a,&d);
         s=(a+b+c)/2;
         s=(s-a)*(s-b)*(s-c)*s;
         s=sqrt(s);
         l=0;
         h=c;
         u=((b*b)+(c*c)-(a*a))/(2*b*c);
         u=acos(u);
         u=sin(u);
         v=((b*b)+(a*a)-(c*c))/(2*b*a);
         v=acos(v);
         v=sin(v);
         while(fabs(l-h)>esp)
         {
              md=(l+h)/2;
             e=(b/c)*md;
             g=(u*md)/v;
             f=(md+e+g)/2;
             f=(f-md)*(f-e)*(f-g)*f;
             f=sqrt(f);
             if(f/(s-f)<d)
                l=md;
             else
                h=md;
         }
         printf("Case %d: %.10lf\n",r,l);
     }

    return 0;
}
