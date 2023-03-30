int main()//求素数
{
    int i = 0;
    int count = 0;
    for (i = 101; i <= 200; i+=2)//优化，跳过偶数
    {
        int j = 0;
        for (j = 2; j <= sqrt(i); j++)//sqrt是开平方，需要<math.h>库函数，优化
        {
            if (i % j == 0)//能被整除就跳过
            {
                break;
            }
        }
        if (sqrt(i) < j)//除数和被除数相等时
        {
            count++;
            printf("%d ", i);
        }
    }
    printf("\n%d个\n", count);
    return 0;
}