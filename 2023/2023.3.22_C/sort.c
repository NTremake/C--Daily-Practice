int main()
{
    int a, b, c;
    scanf_s("%d%d%d", &a, &b, &c);
    if (a < b)
    {
        int tmp = a;//先把a暂存在tmp变量中
        a = b;//再把大的值赋给a
        b = tmp;//再把暂存在tmp中的a赋给b，相当于ab做一个交换
    }
    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("%d>%d>%d\n", a, b, c);//打印出从大到小排序完的数字
    return 0;
}