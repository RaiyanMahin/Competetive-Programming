#include<stdio.h>
#include<string.h>
int stor[1000006];

int Mult(char ch[],char c[],int lll,char st[])
{
     int i,j,a,b,k,l,n,m,hand=0,u,v,put,t;
     l=strlen(ch);
     k=strlen(c);
     j=(l>k)?(l-1):(k-1);

     n=l-1;k=strlen(c);
     m=k-1;hand=0;v=0;u=0;
    for(i=j;i>=0;i--)
    {
            put=0;
        for(a=i,b=m-u;a<=j&&b>=0;b--,a++)
        {
            put+=((ch[a]-'0')*(c[b]-'0'));
        }
        put+=hand;
        hand=put/10;
         stor[v++]=put%10;
        if(i==0&&u<k-1)
        {
            u++;i=1;
        }
        if(v>lll)
            break;
    }
   if(v<lll)
    return -1;
   for(i=0,j=lll-1;i<lll;i++,j--)
   {
     // printf("%d %d\n",stor[i],st[j]-'0');
       if(stor[i]!=st[j]-'0')
        return -1;
   }
   return 1;

}

int main()
{
    int i,j,k,y,len,n,w,r,m,hand=0,put,l,q,p,z,chek;
    char c[20001],s[20001];
   while(scanf("%s",c)!=EOF)
{

    l=strlen(c);
   for(i=0,k=0;i<l;i++)
   {
       if(c[i]!='0'||k>0)
       {
           s[k++]=c[i];
       }
   }
   s[k]='\0';
    len=strlen(c);
    int vvv=Mult(s,s,len,c);
   // if(c[0]=='0')
        // printf("Not an Automorphic number.\n");
   if(vvv==1)
        printf("Automorphic number of %d-digit.\n",len);
    else
        printf("Not an Automorphic number.\n");
}
    return 0;
}


