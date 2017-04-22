#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
struct T{
  char wd[200];

}a[50003];
bool cmp(T x,T y)
{
    return strcasecmp(x.wd,y.wd)<0;
}

int main()
{
    int i=0,k,r=0,l,m,n;
    char *ch,st[3000],s[3000],sr[3000];
    scanf(" %[^ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]",st);
    while(scanf(" %[ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]",st)!=EOF)
        {

            strcpy(s,st);
           for(k=0;k<=strlen(s);k++)
           {
               sr[k]=tolower(s[k]);
           }
           strcpy(a[i].wd,sr);
           i++;

         scanf(" %[^ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz]",st);
      }
            sort(a,a+i,cmp);
        for(k=0;k<i;k++)
            {
                if(strcmp(a[k].wd,a[k-1].wd)!=0||k==0)
                    puts(a[k].wd);
            }
    return 0;
}
