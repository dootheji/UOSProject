#include <stdio.h>
void main()
{
	printf("======code 002=====\n");
	int iValue;
	float fValue;
	char strValue[20];
	char cValue1, cvalue2;
	printf("\n ���� Ȥ�� �Ǽ��� 2�� �Է��Ͻÿ�");
	scanf_s("%d %f", &iValue, &fValue);

	printf("\n ���ڿ��� �Է��Ͻʽÿ� : ");
	scanf_s("%s", strValue);

	printf("\n iValue = %d", iValue);
	printf("\n fValue = %f", fValue);
	printf("\n strValue = %s", strValue);

	//char c;
	//while ((c == getchar()) != '\n' && c != EOF);

	printf("\n ���� 1�� �Է��Ͻʽÿ� : ");
	scanf_s("%c", &cValue1);
	printf("\n strvalue = %s, %c ", strValue, cValue1);
}