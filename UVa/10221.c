#include<string.h>
#include<stdio.h>
#include<math.h>
#define pi 2*acos(0)
#define r 6440
int main()
{
    double s,ang,deg,mi,arc ,chor;
    int i,j,k;
    char st[50];
    while(scanf("%lf %lf %s",&s,&ang,st)!=EOF)
    {
        if(strcmp(st,"deg")==0)
        {
            deg=ang;
        }
        if(strcmp(st,"min")==0)
        {
            deg=ang/60;
        }
        if(deg>180)
            deg=360-deg;
        mi=(pi*deg)/180;
        chor=(2*(r+s))*sin(mi/2);
        arc=2*pi*(r+s)*(deg/360);
        printf("%.6lf %.6lf\n",arc,chor);

    }
  return 0;
}
