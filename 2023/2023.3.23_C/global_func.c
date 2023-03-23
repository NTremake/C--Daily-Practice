int get_max(int x, int y)//自定义函数,v
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int main()
{
    int a = 0;
    int b = 0;
    scanf_s("%d%d", &a, &b);
    int max = get_max(a, b);//调用自定义函数
    printf("max=%d\n", max);
    return 0;
}