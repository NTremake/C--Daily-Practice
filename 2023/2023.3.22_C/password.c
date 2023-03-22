int main()
{
	char password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：");
		scanf_s("%s", password, 20);
		if (strcmp(password, "123456") == 0)//strcmp用于比较字符串，相同字符串ASII值的差为0
		{
			printf("登录成功！\n");
			break;
		}
		else
		{
			printf("密码错误！\n");
		}
	}
	if (i == 3)//超过三次登录失败
		printf("登录失败！\n");

	return 0;
}