#include<stdio.h>
int main()
{
    long long int t,i,hand,j,k[20],l,m,w,num,z,r,n=1;
    while(scanf("%lld",&num)!=EOF)
    {


        if(num<0)
            break;
     i=0;z=num;
     for(r=0;r<20;r++)
         k[r]=0;
        while(num!=0)
        {
            hand=num%10;
            k[i]=hand;

            i++;
            num=num/10;
        }
        printf("%4lld.",n);
        if(z==0)
            printf(" 0");
        for(j=i-1,w=0;j>=0;j--)
        {
             if(j==2||j==9||j==16)
               {
                   m=j;w=1;
               }
            else if(j!=1&&j!=4&&j!=6&&j!=8&&j!=11&&j!=13&&j!=15)
               {
                    m=j+1;w=1;
               }
            else
                w=0;
          if(w==1)
        {
              switch(m)
            {
                case 1:if((k[j+1]*10+k[j])!=0)
                            printf(" %lld",(k[j+1]*10+k[j]));
                       break;
                case 2:if(k[j]!=0){
                    printf(" %lld",k[j]);
                        printf(" shata");}
                         break;

                case 4:if((k[j+1]*10+k[j])!=0){
                        printf(" %lld",((k[j+1]*10+k[j])));
                         printf(" hajar");}
                         break;

                case 6:if((k[j+1]*10+k[j])!=0){
                    printf(" %lld",(k[j+1]*10+k[j]));
                    printf(" lakh");}
                break;
                case 8:if((k[j+1]*10+k[j])!=0){
                    printf(" %lld",(k[j+1]*10+k[j]));
                    printf(" kuti");}
                    else
                        printf(" kuti");

                break;
                case 9:if(k[j]!=0){
                    printf(" %lld",k[j]);
                    printf(" shata ");}
                break;
                case 11:if((k[j+1]*10+k[j])!=0){
                    printf(" %lld",(k[j+1]*10+k[j]));
                    printf(" hajar");}
                break;
                case 13:if((k[j+1]*10+k[j])!=0){
                    printf(" %lld",(k[j+1]*10+k[j]));
                printf(" lakh");}
                break;
                case 15:if((k[j+1]*10+k[j])!=0){
                        printf(" %lld",(k[j+1]*10+k[j]));
                        printf(" kuti");}
                        else
                            printf(" kuti");
                        break;

                case 16:if(k[j]!=0){
                    printf(" %lld",k[j]);
                    printf(" shata");}
                break;
            }
        }


        }
        printf("\n");
        n++;
    }
    return 0;
}




