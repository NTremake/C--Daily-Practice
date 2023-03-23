void swap(int* pa, int* pb)//void定义的函数不需要返回值，这种需要指针变量来接收和返回值;形参无法直接改变实参，也不能将整个数组传到形参，会浪费很多内存。
{
    int tmp = 0;
    tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}
int main()
{
    int a = 10;
    int b = 20;
    printf("a=%d b=%d\n", a, b);
    swap(&a, &b);//传过去的是变量地址
    printf("a=%d b=%d\n", a,b);
    return 0;
}