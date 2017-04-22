#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[1000000],st[2];
int main()
{
    long long  int i,j,f,k,l,m=0,n,d,r=0;

    while(scanf("%s %c %lld",ch,&st[0],&d)==3)
    {

        m=0;r=0;f=0;
        if(st[0]=='%')
        {
             for(i=0;ch[i]!='\0';i++)
           {
             n=m*10+(ch[i]-48);
              m=n%d;
          }
          printf("%lld\n",m);
        }

       else if(st[0]=='/')
        {
            m=0;
            for(i=0;ch[i]!='\0';i++)
         {
             n=m*10+(ch[i]-48);
             m=n%d;
             r=n/d;
             if(r!=0)
                f=1;
             if(f==1)
           printf("%lld",r);
         }
         if(f==0)
            printf("0");
         printf("\n");
        }
    }
    return 0;
}
