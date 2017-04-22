//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
char  s[5000][1065],st[10005];
void add(int n)
{
    int i,h=0,k,j,l,m;char c[10],ar[10000];
    l=strlen(s[n-1]);
    m=strlen(s[n-2]);
    for(i=l-1,j=m-1;i>=0;i--,j--)
    {
        if(j<0)
        {
            k=s[n-1][i]-'0'+h;
        }
        else
        {
            k=s[n-1][i]+s[n-2][j]-'0'-'0'+h;
        }
        h=k/10;ar[i]=k%10;

    }
    if(h==1)
        strcpy(s[n],"1");
    else
        strcpy(s[n],"");
    for(i=0;i<l;i++)
    {
        sprintf(c,"%d",ar[i]);
        strcat(s[n],c);
    }
}
int main()
{
        int i,j,k,l,h,n,m;
        memset(s,NULL,sizeof(s));
        strcpy(s[0],"1");
        strcpy(s[1],"1");
        for(i=2;i<=5000;i++)
        {
            add(i);
        }
        while(scanf("%d",&n)==1)
        {
          puts(s[n+1]);

        }
        return 0;
}
