#include<stdio.h>
#include<string.h>
int main()
{
    int i,t,j,k,m,ar[100];
    char st[15][200];
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%s %d",st[j],&ar[j]);
        }
       m=0;
        for(j=0;j<10;j++)
       {
        if(ar[j]>m)
          {

                m=ar[j];
          }
       }
       printf("Case #%d:\n",i);
       for(k=0;k<10;k++)
       {
           if(ar[k]==m)
           {
               printf("%s\n",st[k]);
           }
       }
    }
    return 0;
}
