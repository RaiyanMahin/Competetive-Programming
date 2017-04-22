#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,l;
    char ch[100];
    while(scanf("%c",&ch[0])!=EOF)
    {
        for(i=1;;i++)
        {
            scanf("%c",&ch[i]);
            if(ch[i]=='\n')
                break;
        }
        for(j=0;j<=i;j++)
            printf("%c",ch[j]);
    }
    return 0;
}
