#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int i,t,r,j,k,l,m,ar[200];
    char st[1000];
    scanf("%d",&t);
    getchar();
    for(r=0;r<t;r++)
    {
          gets(st);
        l=strlen(st);
        memset(ar,0,sizeof(ar));
        k=0;
        for(i=0;i<l;i++)
        {
          st[i]=tolower(st[i]);
          if(st[i]>='a'&&st[i]<='z')
            ar[st[i]]++;
            if(ar[st[i]]>k)
                 k=ar[st[i]];
        }
        for(i='a';i<='z';i++)
            {
                if(ar[i]==k)
                  printf("%c",i);
            }
        printf("\n");
    }
    return 0;
}

