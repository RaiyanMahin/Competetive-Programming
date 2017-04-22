#include<stdio.h>
#include<string.h>
int main()
{
   long long int i,j,k,l,n,m,ar[100];
    char st[100],ch[50];

    while(scanf("%s",st)!=EOF)
    {
        for(i=0;i<=9;i++)
        {
            ar[i]=i;ch[i]=48+i;
        }
        ar['A'-48]=10;ar['B'-48]=11;ar['C'-48]=12;ar['D'-48]=13;ar['E'-48]=14;ar['F'-48]=15;
        ch[10]='A';ch[11]='B';ch[12]='C';ch[13]='D';ch[14]='E';ch[15]='F';
        l=strlen(st);
       if(st[0]=='-')
                break;
       if(st[0]=='0'&&st[1]=='x')
       {
           j=1;k=0;
           for(i=l-1;i>1;i--)
           {
               k=k+(ar[st[i]-48]*j);
               j=j*16;
           }
           printf("%lld\n",k);
       }
       else
       {k=0;
           for(i=0;i<l;i++)
           {
              k=k*10+ar[st[i]-48];
           }
          m=k;i=0;
          while(m!=0)
          {
              ar[i]=m%16;
              m=m/16;i++;
          }
          if(k==0)
            printf("0x0");
          else
          printf("0x");
          for(n=i-1;n>=0;n--)
          {
              printf("%c",ch[ar[n]]);
          }
          printf("\n");
       }
    }
return 0;
}
