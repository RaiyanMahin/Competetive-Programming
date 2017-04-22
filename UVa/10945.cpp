//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,j,k,l,m,n;
    char st[1000],s[1000];
    while(gets(st))
    {
        if(strcmp(st,"DONE")==0)
            break;
        l=strlen(st);
        for(i=0,j=0;i<l;i++)
            if((st[i]>='A'&&st[i]<='Z')||(st[i]>='a'&&st[i]<='z'))
              {
                  st[j]=st[i];j++;
              }
        st[j]='\0';
        l=strlen(st);
        for(i=l-1,j=0;i>=0;i--)
            s[j++]=st[i];
        s[j]='\0';
        if(strcasecmp(st,s)==0)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}

