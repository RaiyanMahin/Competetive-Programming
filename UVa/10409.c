#include<string.h>
#include<stdio.h>
int main ()
{
    int  i,j,k,l,na,m,n,s,t,b,w,e;
    char st[1025][7];
    while(scanf("%d",&na)!=EOF)
    {
        if(na==0)
            break;
        getchar();
        t=1;n=2;w=3;e=4;s=5;b=6;
        for(i=0;i<na;i++)
        {
            scanf("%s",st[i]);
            getchar();
        }
        for(i=0;i<na;i++)
        {
            if(!strcmp(st[i],"north"))
            {
                m=t;
                t=s;
                l=n;
                n=m;
                m=b;
                b=l;
                s=m;
            }
           else if(!strcmp(st[i],"south"))
            {
                m=t;
                t=n;
                l=s;
                s=m;
                m=b;
                b=l;
                n=m;
            }
           else if(!strcmp(st[i],"east"))
            {
                m=t;
                t=w;
                l=e;
                e=m;
                m=b;
                b=l;
                w=m;
            }
            else if(!strcmp(st[i],"west"))
            {
                m=t;
                t=e;
                l=w;
                w=m;
                m=b;
                b=l;
                e=m;
            }
        }

        printf("%d\n",t);
    }
    return 0;
}
