
#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,l,m,n,y[3],d[3],t,r,month;
    char mon[3][50],ch[21];
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        for(i=0;i<2;i++)
        scanf("%s %d%s %d",&mon[i],&d[i],&ch,&y[i]);

        if((strcmp(mon[0],"January")==0));
        else if(strcmp(mon[0],"February")==0);
        else
            y[0]+=1;
        if((strcmp(mon[1],"January")==0))
            y[1]-=1;
        else if(strcmp(mon[1],"February")==0&&d[1]<29)
            y[1]-=1;
         n=0;
         if((y[1]-y[0])>=0)
        {
             n=((y[1]-y[0])/400)*97;
            y[0]%=400;
            y[1]%=400;
            y[0]+=400;
            y[1]+=400;
            if(y[0]>y[1])
                y[1]+=400;
                j=1;
            for(i=y[0];i<=y[1];i+=j)
            {
                if((i%4==0&&i%100!=0)||i%400==0)
                {
                    n++;j=4;
                }
            }
        }
        printf("Case %d: %d\n",r,n);
    }
    return 0;
}


