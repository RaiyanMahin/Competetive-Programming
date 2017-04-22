#include<stdio.h>
#include<string.h>
int main()
{
    double i,j,k,l,m,h,s,ihh=0,hh,d=0,v=0;
    char ch;
    while(scanf("%lf:%lf:%lf%c",&h,&m,&s,&ch)!=EOF)
    {
        hh=h+(m/60)+(s/3600);
        if(ch==' ')
        {
             d=d+((hh-ihh)*v);
            scanf("%lf",&v);

        }
       else if(ch=='\n')
       {

           d=d+((hh-ihh)*v);
           printf("%02d:%02d:%02d %.2lf km\n",(int)h,(int)m,(int)s,d);
       }
        ihh=h+(m/60)+(s/3600);
    }
  return 0;
}

