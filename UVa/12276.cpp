#include <stdio.h>
#include <string.h>
int dp[201][201][26];
int calc[201][201];
int symb;
char s[201];
int comb[26][26];
char next[26][26];
char v[26];
int min(int a,int b)
{
    return (a<b)?a:b;
}
void go(int l,int r)
{
    if(calc[l][r])return;
    else if(l==r)
    {
        dp[l][r][s[l]]=0;
        calc[l][r]=1;
        return;
    }
    else
    {
        int i,j,k;
        for(i = l;i<r;i++)
        {
            go(l,i);
            go(i+1,r);
            for(j=0;j<symb;j++)
                for(k=0;k<symb;k++)
                    dp[l][r][next[j][k]]=min(dp[l][r][next[j][k]],dp[l][i][v[j]]+dp[i+1][r][v[k]]+comb[j][k]);
        }
        calc[l][r]=1;
        return;
    }
}
int main()
{
    int i,j,k,l,m;
    int cc = 0;
    while(1)
    {
        scanf("%d",&symb);
        if(!symb)break;
        if(cc++)putchar('\n');
        getchar();
        for(i = 0;i<symb;i++)
        {
            v[i]=getchar();
            getchar();
            v[i]-='a';
        }
        for(i = 0;i<symb;i++)
        {
            for(j = 0;j<symb;j++)
            {
                int x;
                char y;
                scanf("%d-%c",&x,&y);
                getchar();
                comb[i][j]=x;
                next[i][j]=y-'a';
            }
        }
        int q;
        scanf("%d",&q);
        getchar();
        for(i = 0;i<q;i++)
        {
            gets(s);
            k=strlen(s);
            for(j=0;j<k;j++)s[j]-='a';
            for(j=0;j<k;j++)
                for(l=0;l<k;l++)
                {
                    calc[j][l]=0;
                    for(m=0;m<26;m++)
                        dp[j][l][m]=(int)1e8;
                }
            go(0,k-1);
            int best = 0;
            for(j =1;j<symb;j++)
                if(dp[0][k-1][v[j]]<dp[0][k-1][v[best]])
                    best = j;
            printf("%d-%c\n",dp[0][k-1][v[best]],(char)(v[best]+'a'));
        }
    }
    return 0;
}
