    #include<stdio.h>
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<math.h>
    long long int dp[11][10];
    long long int data[11];
    void init()
    {
        int i,j,k;
        memset(dp,0,sizeof(dp));
        for(i = 0; i < 10; i++)
            dp[1][i]=1;
        for(i = 2; i < 11; i++)
        {
            for(j = 0; j < 10; j++)
                for(k = 0; k < 10; k++)
                if(abs(j-k)>1)
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
        for(i = 1; i < data[len]; i++)
        {
            ans+=dp[len][i];
        }
        for(i = len-1; i >0; i--)
        {
            for(j = 0; j < data[i]; j++)
            {
                if(abs(j-data[i+1])>1)
                {
                    ans+=dp[i][j];
                }
            }

            if(abs(data[i]-data[i+1])<2)
                break;
        }
        //printf("\n");
        return ans;

    }
    int main()
    {
        long long int a,b;
        init();
        while(~scanf("%lld%lld",&a,&b))
        {
            printf("%lld\n",solve(b+1)-solve(a));
        }
        return 0;
    }
