#include<stdio.h>
#include<string.h>
int main()
{
    long long int i,j,k,l,t,a,b,d,m,n,sp,nn,mm;
    char st[10000],num1[1000],num2[1000];
    while(gets(st))
    {
        l=strlen(st);a=1;sp=0;
        for(i=0,j=0,k=0;i<l;i++)
        {
            if(st[i]>='0'&&st[i]<='9'&& a==1)
            {
                num1[j]=st[i];sp=1;j++;
            }
            else if(st[i]=='*')
                {
                    d=2;a==2;

                }
            else if(st[i]=='+')
                {
                    d=1;a==2;

                }
            else if(st[i]==' '&&sp==1)
            {
              a=2;
            }
            else if(st[i]>='0'&&st[i]<='9'&&a==2)
            {
                num2[k]=st[i];
                k++;
            }

        }
        num2[k]='\0';num1[j]='\0';nn=0;mm=0;
        n=strlen(num1);
        m=strlen(num2);
        for(i=0;i<n;i++)
        {
            nn=nn*10+(num1[i]-'0');
            if(i==11)
                break;
        }
        for(i=0;i<m;i++)
        {
            mm=mm*10+(num2[i]-'0');
            if(i==11)
                break;
        }
        puts(st);
        if(nn>=2147483648)
            printf("first number too big\n");
        if(mm>=2147483648)
            printf("second number too big\n");
        if((nn>=2147483648||mm>=2147483648)&&nn!=0&&mm!=0)
            {

                printf("result too big\n");
            }
    else
        {
          if(nn+mm>=2147483648&&d==1)
            printf("result too big\n");
          if(nn*mm>=2147483648&&d==2)
            printf("result too big\n");
        }

    }
    return 0;
}
