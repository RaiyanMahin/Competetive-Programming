#include<stdio.h>
#include<math.h>
#define PI (2*acos(0.0))
double angl(double a,double b,double c)
{
    return acos((a*a+b*b-c*c)/(2*a*b));
}
double area(double a,double b,double c)
{
    double ans=(a+b+c)/2;
    return sqrt(ans*(ans-a)*(ans-b)*(ans-c));
}
int main()
{
    int t;
    double r1,r2,r3,a,b,c,ans;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {

        scanf("%lf%lf%lf",&r1,&r2,&r3);
         a=r1+r2;
         b=r2+r3;
        c=r3+r1;
         ans=area(a,b,c);
        ans-=angl(a,c,b)/2*r1*r1;
        ans-=angl(a,b,c)/2*r2*r2;
        ans-=angl(c,b,a)/2*r3*r3;
        printf("Case %d: %.8lf\n",ii,ans);
    }
    return 0;
}
