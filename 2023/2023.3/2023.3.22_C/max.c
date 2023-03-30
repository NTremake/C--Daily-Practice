int main()
{
    int arr[] = { 1,2,3,4,5,-1,-2,-3,-4,-5 };
    int i = 0;
    int sz = sizeof arr / sizeof arr[0];
    int max = arr[0];//直接假设数组中的一个数为最大值
    for (i = 1; i <sz; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];//把较大的数给max
        }
    }
    printf("%d\n", max);
    return 0;
}