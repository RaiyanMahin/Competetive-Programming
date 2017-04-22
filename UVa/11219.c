#include<stdio.h>
int main()
{
int j=0,n,m1,d1,y1,m2,d2,y2,a,b,c;
scanf("%d",&n);
while(n>0)
{
j++;
scanf("%d/%d/%d%d/%d/%d",&d1,&m1,&y1,&d2,&m2,&y2);
a=y1-y2;
b=m1-m2;
c=d1-d2;
if(a>130&&b>=0&&c>=0)
printf("Case #%d: Check birth date\n",j);
else if(a==130&&b>=0&&c>=0||a==130&&b>0)
printf("Case #%d: %d\n",j,a);
else if(a>=130&&b<=0&&c<=0)
printf("Case #%d: %d\n",j,a-1);
else if(a<=0&&b<0&&c<0||a<=0&&b<=0&&c<0||a<=0&&b<0)
printf("Case #%d: Invalid birth date\n",j);
else
{
if(a>=0&&b>=0&&c>=0)
printf("Case #%d: %d\n",j,a);
if(a>=0&&b>0&&c<0)
printf("Case #%d: %d\n",j,a);
else if(a>=0&&b>=0&&c<0)
printf("Case #%d: %d\n",j,a-1);
else if(a>=0&&b<0)
printf("Case #%d: %d\n",j,a-1);
}
n--;
}
return 0;
}
