int main()
{
  int num1 = 0;
  int num2 = 0;
  int sum = 0;//C语言规定，变量定义必须在代码块最前面
  scanf_s ("%d%d", &num1, &num2);//输出数据-使用输入函数scanf,&是取地址符；scanf是C语言的规则，scanf_s是VS的规则
  sum = num1 + num2;
  printf("sum=%d\n", sum);
  return 0;
  }