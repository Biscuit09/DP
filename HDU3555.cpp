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
            dp[1][i]=1;
        for(i = 2; i < 20; i++)
        {
            for(j = 0; j < 10; j++)
                for(k = 0; k < 10; k++)
                if(j*10+k!=49)
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
        for(i = 1; i < len;i++)
            for(j = 1; j < 10; j++)
            ans+=dp[i][j];
       // printf("****%d\n",ans);
        for(i = 1; i < data[len]; i++)
        {
            ans+=dp[len][i];
        }
       // printf("******%d\n",ans);
        for(i = len-1; i >0; i--)
        {
            //printf("***i%d***%d\n",i,data[i]);
            for(j = 0; j < data[i]; j++)
            {
                if(j+data[i+1]*10!=49)
                {
                    ans+=dp[i][j];
                }
                //printf("********%d\n",ans);
            }

            if(data[i]+data[i+1]*10==49)
                break;
        }
        //printf("\n");
        return ans;

    }
    int main()
    {
        long long int a,b;
        int t;
        init();
        /*for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 10; j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }

        for(int i = 1; i < 100; i++)
            if(i-solve(i+1)>0)
            printf("***i %d %d\n",i,i-solve(i+1));*/
        scanf("%d",&t);
        while(t--)
        {
            scanf("%I64d",&a);
            printf("%I64d\n",(a-solve(a+1)));
        }
        return 0;
    }
