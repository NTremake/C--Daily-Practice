int main()
{
    char arr[] = "hello world!";
    memset(arr, '*', 5);//memset修改字符串，头文件<string.h>；目的地、修改内容、被修改的大小
    printf("%s", arr);
    return 0;
}