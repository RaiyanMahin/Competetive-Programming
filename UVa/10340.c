#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l,n,m;
    char s[100000],t[100000];
    while(scanf("%s %s",&s,&t)!=EOF)
    {
        l=strlen(s);
        m=strlen(t);
        n=0;
        for(i=0,j=0;i<l;i++)
        {
            for(;j<m;j++)
            {
                if(s[i]==t[j])
                {
                  j++;n++;break;
                }
            }
        }
        if(n==l)
            printf("Yes\n");
        else
            printf("No\n");
    }
return 0;
}
