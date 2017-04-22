#include<stdio.h>
#include<string.h>
#include<ctype.h>
char ch[10009][200];
int main()
{
    int  i=0,j,k,l,m,n;
    char st,s[200],wd[200];m=0;
    while(scanf("%s",ch[i])!=EOF)
    {
        if(!strcmp(ch[i],"E-N-D"))
            break;

        for(j=0,l=0;j<strlen(ch[i]);j++)
        {
              st=tolower(ch[i][j]);
            if((st>='a'&&st<='z')||st=='-')
               {
                   s[l]=st;
                    l++;
               }
        }
         s[l]='\0';
         if(l>m)
            {
               m=l;
               strcpy(wd,s);
            }
            i++;
    }
    puts(wd);
    return 0;
}
