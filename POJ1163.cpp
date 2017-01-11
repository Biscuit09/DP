#include<stdio.h>
#include<string.h>
#include<math.h>
int a[105][105];
int f[105][105];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        for(int i = 1; i < n+1; i++)
            for(int j = 1; j <i+1;j++)
            scanf("%d",&a[i][j]);
        int m=0;
        f[1][1]=a[1][1];
        f[2][1]=a[1][1]+a[2][1];f[2][2]=a[1][1]+a[2][2];
        for(int i = 2; i < n+1; i++)
            for(int j = 1; j <i+1;j++)
            {
                if(f[i-1][j]>f[i-1][j-1])
                    f[i][j]=f[i-1][j]+a[i][j];
                else f[i][j]=f[i-1][j-1]+a[i][j];
                if(m<f[i][j])m=f[i][j];
            }
        printf("%d\n",m);

    }
    return 0;
}
