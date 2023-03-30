int main()//九九乘法表
{
    int i = 0;
    for (i = 1; i <= 9; i++)
    {
        int j = 0;
        for (j=1;j<=i;j++)
        {
            printf("%d*%d=%-2d ", i, j, i * j);//%-2d是左对齐，%2d是右对齐
        }
        printf("\n");
    }
    return 0;
}