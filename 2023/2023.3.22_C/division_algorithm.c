int main()//求最大公约数
{
    int a = 24;
    int b = 18;
    int r = 0;
    scanf_s("%d%d", &a, &b);
    while (r = a % b)//判断余数是否为0；不写！=0也能判断，直接判断真假
    {
        a = b;
        b = r;
    }
    printf("%d\n", b);
    return 0;
}