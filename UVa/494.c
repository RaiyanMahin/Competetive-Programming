#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000000],ch[10000];
    int i,l,p=0;
    while(scanf("%s",ch)!=EOF)
{
    gets(str);
    strcat(str,ch);
    l=strlen(str);p=0;
    for(i=1;i<=l;i++)
    {
        if(((str[i-1]>=65&&str[i-1]<=90)||(str[i-1]>=97&&str[i-1]<=122))&&((str[i]>=0&&str[i]<=64)||(str[i]<97&&str[i]>90)||(str[i]>122&&str[i]<=200)))
           p++;
    }
    printf("%d\n",p);
    }
    return 0;
}


