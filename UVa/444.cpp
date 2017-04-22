#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,ar[200],a[10000];
    char st[1000];
    memset(ar,-1,sizeof(ar));
    for(i='a',j='A';i<='z';i++,j++)
    {
        ar[i]=ar[j]=1;
    }
    ar[' ']=1;ar['!']=1;ar[',']=1;ar['.']=1;ar[';']=1;ar[':']=1;ar['?']=1;
    while(gets(st))
    {
        l=strlen(st);
        if(st[0]>='0'&&st[0]<='9')
        {
            for(i=l-1;i>=0;i--)
            {
                j=((st[i]-'0')*10)+st[i-1]-'0';
                k=((st[i]-'0')*100)+((st[i-1]-'0')*10)+st[i-2]-'0';
                if(ar[j]==1)
                {
                    printf("%c",j);i--;

                }
                else if(ar[k]==1)
                {
                    printf("%c",k);i-=2;
                }
            }
        }
        else
        {
            for(i=l-1,j=0;i>=0;i--)
                {
                    k=st[i];
                    while(k!=0)
                    {
                        printf("%d",k%10);
                        k/=10;
                    }
                }
        }
        printf("\n");
    }
    return 0;
}
