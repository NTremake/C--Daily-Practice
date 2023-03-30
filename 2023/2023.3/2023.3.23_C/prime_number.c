int is_prime(int a)//求素数
{
    int b = 0;
    for (b = 2; b <= sqrt(a); b++)
    {
        if ((a % b) == 0)
            return 0;//优化掉break；
    }//优化掉if(sqrt(i)>b)
    return 1;
}
int main()
{
    int i = 0;
    for (i = 101; i <= 200; i += 2)
    {
        if ((is_prime(i)) == 1)
            printf("%d ",i);
    }
    return 0;
}