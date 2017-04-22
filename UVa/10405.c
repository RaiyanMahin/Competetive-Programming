//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#define S 1005
char s[S],ss[S];
int dp[S][S];
int Max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,l,ll;
	while(gets(s))
	{
	    gets(ss);
		l=strlen(s);
		ll=strlen(ss);
		for(i=1;i<=l||i<=ll;i++)
		dp[i][0]=0,dp[0][i]=0;
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=ll;j++)
			{
				if(s[i-1]==ss[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
				else
				dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%d\n",dp[l][ll]);

	}
	return 0;
}
