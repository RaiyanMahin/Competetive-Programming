#include<stdio.h>
int  main()
{
    int i,w,r;
    int j,k=0,l[50000],n,u[50000],t=1,a;
    while(scanf("%d %d",&i,&w)!=EOF)
    {
    k=0;t=1;
    printf("%d/%d = %d.",i,w,i/w);
    i=i%w;
    while(k<=50000)
    {

        i=i*10;
        u[k]=i;
    for(n=0;n<k;n++)
        if(i==u[n])
           {
               t=0;
               a=n;
           }
    if(t==0)
        break;
        j=i/w;
        l[k]=j;
        i=i%w;
        k++;

    }
   t=1;
    for(j=0,r=0;j<k;j++)
    {
        if(a==j)
            {
                printf("(");t=0;
            }
        if(t==0)
            r++;
        if(r<=50)
            printf("%d",l[j]);

        if(j==k-1&&k<51)
        printf(")");
        if(r==50)
            {
                printf("...)");
            }

    }
    printf("\n   %d = number of digits in repeating cycle\n\n",r);
    }
    return 0;
}

