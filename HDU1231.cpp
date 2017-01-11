#include<stdio.h>
#include<string.h>
int a[10010];
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        if(k == 0)
        {
            break;
        }
        for(int i = 0; i < k; i++)
            scanf("%d",&a[i]);
        int maxs=a[0],sum=0;
        int flag=a[0],left=a[0],right=a[0];
        for(int i = 0; i < k; i++)
        {
            if(sum<0)
            {
                sum=a[i];
                flag=a[i];
            }
            else
            {
                sum+=a[i];
            }
            if(sum>maxs)
            {
                maxs=sum;
                left=flag;
                right=a[i];
            }
        }
        //printf("%d\n",maxs);
        if(maxs<0)printf("0 %d %d\n",a[0],a[k-1]);
        else printf("%d %d %d\n",maxs,left,right);
    }
    return 0;
}
