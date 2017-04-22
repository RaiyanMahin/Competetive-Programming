#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,m,t,n=0,a,b,c,lin=0;
    char ch[101][100];
    while(gets(ch[lin]))
    {
        lin++;
    }
    for(t=0;t<lin;t++)
    {
        m=0;a=0;b=0;c=0;
        l=strlen(ch[t]);
        for(i=0;i<l;i++)
        {
            if(ch[t][i]>=48&&ch[t][i]<=57&&m==0)
            {
                a=a*10+(ch[t][i]-48);
            }
            else if(ch[t][i]=='+'||ch[t][i]=='-'||ch[t][i]=='=')
            {
                if(ch[t][i]=='+')
                {
                    k=1;m=1;
                }
                if(ch[t][i]=='-')
                {
                    k=2;m=1;
                }
                if(ch[t][i]=='=')
                {
                    m=2;
                }

            }
            else if(ch[t][i]>=48&&ch[t][i]<=57&&m==1)
            {
                b=b*10+(ch[t][i]-48);
            }
             else if(ch[t][i]>=48&&ch[t][i]<=57&&m==2)
            {
                c=c*10+(ch[t][i]-48);
            }
            else if(ch[t][i]=='?')
                k=0;
        }

            if(k==1)
            {
                j=a+b;
                if(j==c)
                    n++;
            }
           else if(k==2)
            {
                j=a-b;
                if(j==c)
                   n++;
            }


    }
    printf("%d\n",n);
    return 0;
}
