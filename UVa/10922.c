
#include<stdio.h>
#include<string.h>
int main()
{
    int i,s,j,k,n,l,m;
    char st[2000];
    while(scanf("%s",st)!=EOF)
    {

        l=strlen(st);s=0;
        for(i=0;i<l;i++)
            s+=st[i]-48;
            n=1;
        if(s==0)
            break;
        while(s>9)
        {
            k=s;m=0;
            while(k!=0)
            {
                m=m+(k%10);
                k/=10;
            }
            s=m;n++;
        }
        if(s%9==0)
            printf("%s is a multiple of 9 and has 9-degree %d.\n",st,n);
        else
            printf("%s is not a multiple of 9.\n",st);
    }
    return 0;
}
