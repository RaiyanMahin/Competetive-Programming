#include<stdio.h>
#include<math.h>
#define pi 2*acos(0.0)
int main()
{
    double i,j,k,l,m,n,r1,r2,r,x,p,h;
    int ch,t;
    scanf("%d",&t);
    for(ch=1;ch<=t;ch++)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        i=(r1*h)/(r1-r2);
        x=i-h;
        j=((h-p)*(r1-r2))/h;
        r=r1-j;
        k=pi*r*r*(p+x);
        k=k/3;
        l=pi*r2*r2*x;
        l=l/3;
        n=k-l;
        printf("Case %d: %.9lf\n",ch,n);
    }
    return 0;
}
