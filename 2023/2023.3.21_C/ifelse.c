int main()
{
	int age = 60;
	if (age < 18)
		printf("未成年\n");
	else if (age >= 18 && age < 30)//&&是“并且”的意思
		printf("青壮年\n");
	else if (age >= 30 && age < 50)//else和最近的未匹配的if组成一块
		printf("中年\n");
	else if (age >= 50 && age < 90)
		printf("老年\n");
	else 
		printf("长生\n");
	return 0;
}