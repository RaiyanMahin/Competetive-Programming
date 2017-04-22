#include<stdio.h>
int main()
{
    double anh,anm,an;
    int m,h;
    char ch;
    while(scanf("%d%c%d",&h,&ch,&m)!=EOF)
    {
        if(h==0&&m==0)
              break;
        anh=0.5*(h*60+m);
        anm=6*m;
        an=(anh-anm);
        while(an>360)
        {
            an=an-360;
        }
        if(an<0)
            an=an*-1;
        if(an>180)
            printf("%.3lf\n",360-an);
        else
            printf("%.3lf\n",an);


    }
    return 0;
}
