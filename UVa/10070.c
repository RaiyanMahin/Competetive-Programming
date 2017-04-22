#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,cot=0,lp,m[5],n,d[5]={4,100,400,15,55};
    char st[100001];
    while(scanf("%s",st)!=EOF)
    {
        if(cot!=0)
            printf("\n");
        cot=1;
        for(j=0;j<5;j++)
        for(i=0,m[j]=0;st[i];i++)
    {
        n=m[j]*10+(st[i]-48);
        m[j]=n%d[j];
    }
       k=0;lp=0;
     if((m[0]==0&&m[1]!=0)||m[2]==0)
        {
            printf("This is leap year.\n");k=1;lp=1;
        }
     if(m[3]==0)
       {
            printf("This is huluculu festival year.\n");k=1;
       }
     if(m[4]==0&&lp==1)
        {
             printf("This is bulukulu festival year.\n");k=1;
        }
     if(k!=1)
         printf("This is an ordinary year.\n");


    }
  return 0;
}
