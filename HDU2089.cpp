    #include<stdio.h>
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<math.h>
    long long int dp[20][10];
    long long int data[20];
    void init()
    {
        int i,j,k;
        memset(dp,0,sizeof(dp));
        for(i = 0; i < 10; i++)
            if(i!=4)dp[1][i]=1;
        for(i = 2; i < 20; i++)
        {
            for(j = 0; j < 10; j++)
                for(k = 0; k < 10; k++)
                if((j*10+k!=62)&&j!=4&&k!=4)
                    dp[i][j]+=dp[i-1][k];
        }
        return;
    }
    long long int solve(long long int n)
    {
        int len=0;
        memset(data,0,sizeof(data));
        while(n)
        {
            data[++len]+=n%10;
            n/=10;
        }

        int i,j,k;
        long long int ans=0;
        for(i = 1; i < len;i++)//len-1
            for(j = 1; j < 10; j++)
            ans+=dp[i][j];
            //printf("****%d\n",ans);
        for(i = 1; i < data[len]; i++)//len
        {
            ans+=dp[len][i];
        }
            //printf("******%d\n",ans);
        for(i = len-1; i >0; i--)
        {
            //printf("***i%d***%d\n",i,data[i]);
            for(j = 0; j < data[i]; j++)
            {
                if(j!=4&&data[i+1]!=4&&(data[i+1]*10+j!=62))
                {
                    ans+=dp[i][j];
                }
                //printf("********%d\n",ans);
            }

            if(((data[i+1]*10+data[i])==62)||data[i+1]==4||data[i]==4)
                break;
        }
        return ans;

    }
    int main()
    {
        long long int a,b;
        init();
       /* for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 10; j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }
        for(int i = 1; i < 200; i++)
            printf("\n***i %d %d\n",i,solve(i));*/
        while(~scanf("%lld%lld",&a,&b))
        {
            if(a==0&&b==0)break;
            printf("%lld\n",solve(b+1)-solve(a));
        }
        return 0;
    }
