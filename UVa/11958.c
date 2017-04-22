#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,T,minx,minn,bus,b[1001],ch,cm,th[1001],tm[1001],tn[1001];
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d:%d",&bus,&ch,&cm);
        for(j=0;j<bus;j++)
        {
            scanf("%d:%d %d",&th[j],&tm[j],&tn[j]);
        }
        minx=100000000;
        for(j=0;j<bus;j++)
        {
            if(ch>th[j])
            {
                minn=24-ch+th[j];
                minn=minn*60;
                minn=minn+(tm[j]-cm)+tn[j];
            }
            else if(ch==th[j]&&tm[j]<cm)
                {
                    minn=24;
                    minn=minn*60;
                    minn=minn+(tm[j]-cm)+tn[j];
                }
            else
            {
                minn=th[j]-ch;
                minn=minn*60;
                minn=minn+(tm[j]-cm)+tn[j];
            }
            if(minn<minx)
                minx=minn;
        }
        printf("Case %d: %d\n",i,minx);
    }
return 0;
}
