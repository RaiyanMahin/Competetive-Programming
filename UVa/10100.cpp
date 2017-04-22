//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#define S 1005
char s[S][50],ss[S][50];
int dp[S][S];
int Max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,l,ll,rr=1;
	char stt[10000],*cp,st[1005],sss[1005];
	while(gets(st))
	{
	    gets(sss);
		l=strlen(st);
		ll=strlen(sss);
		if(l==0||ll==0)
        {
            printf("%2d. Blank!\n",rr);
        }
        else
        {
            for(i=0,j=0;i<l;i++)
        {
            if((st[i]>='0'&&st[i]<='9')||(st[i]>='a'&&st[i]<='z')||(st[i]>='A'&&st[i]<='Z'));
                else
              stt[j++]=st[i];
        }
        for(i=0;i<ll;i++)
        {
            if((sss[i]>='0'&&sss[i]<='9')||(sss[i]>='a'&&sss[i]<='z')||(sss[i]>='A'&&sss[i]<='Z'));
            else
              stt[j++]=sss[i];
        }
        stt[j]='\0';
        l=0;
        cp=strtok(st,stt);
        while(cp!=NULL)
        {
            strcpy(s[l],cp);l++;
            cp=strtok(NULL,stt);
        }
        ll=0;
        cp=strtok(sss,stt);
        while(cp!=NULL)
        {
            strcpy(ss[ll],cp);ll++;
            cp=strtok(NULL,stt);
        }
		for(i=1;i<=l||i<=ll;i++)
		dp[i][0]=0,dp[0][i]=0;
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=ll;j++)
			{
				if(strcmp(s[i-1],ss[j-1])==0)
				dp[i][j]=dp[i-1][j-1]+1;
				else
				dp[i][j]=Max(dp[i-1][j],dp[i][j-1]);
			}
		}
		printf("%2d. Length of longest match: %d\n",rr,dp[l][ll]);
        }
      rr++;
	}
	return 0;
}

