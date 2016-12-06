
#include<stdio.h>

int main()
{
    int r,t;
    double tm1,tm2,tm,s,a1,a2,v3,v1,v2,d,d1,d2;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        d1=(v1*v1)/(2*a1);
        d2=(v2*v2)/(2*a2);
        s=d1+d2;
        tm1=(v2/a2);
        tm2=(v1/a1);
        tm=(tm1>tm2)?tm1:tm2;
        d=v3*tm;
        printf("Case %d: %lf %lf\n",r,s,d);
    }
    return 0;
}
