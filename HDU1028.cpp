#include<stdio.h>
#include<string.h>
long long int dp[121][121];
void cal()
{
    for(int i = 1; i < 121; i++)
    {
        dp[i][1]=1;
        dp[1][i]=1;
    }
    for(int i = 2; i < 121; i++)
        for(int j = 2; j < 121; j++)
    {
        if(i < j)dp[i][j]=dp[i][i];
        else if(i == j)dp[i][j]=dp[i][j-1]+1;
        else if(i > j)dp[i][j]=dp[i-j][j]+dp[i][j-1];
    }

}
int main()
{
    int n;
    cal();
    while(~scanf("%I64d",&n))
    {

        printf("%I64d\n",dp[n][n]);
    }
    return 0;
}
