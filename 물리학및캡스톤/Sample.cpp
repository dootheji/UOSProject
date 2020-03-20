#define _CRT_SECURE_NO_WARNINGS
#define CPLUSPLUS
//#undef CPLUSPLUS

#ifndef CPLUSPLUS	
	#include <stdio.h>	// printf
	#include <stdlib.h> // malloc, free
	#include <conio.h>	//_getche();	
	void main()
	{
		// ������ ���� �Ҵ�, �⺻ void* ���� int*�� ����ȯ				//malloc : �����޸� �Ҵ� - �޸� ��𼱰� malloc(n) n��ŭ�� �޸𸮰� �������� �����Ѵٸ� �ش� ���� �޸𸮸� pointer�� ����
		printf("\n=====================\n");
		int *pPoint = (int*)malloc(sizeof(int));						//pointer �ٸ� �ּҰ��� �����ϱ⺸�ٴ�, "
		*pPoint = 100;
		printf("%0x���� : %d\n", pPoint + 0, *(pPoint + 0));
		free(pPoint);
		// ������ ���� �迭 �Ҵ�
		printf("\n=====================\n");
		int *pPointArray = (int*)malloc(sizeof(int) * 10);
		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			pPointArray[iCnt] = iCnt * 10;
			printf("\n0x%08x���� : %d", &pPointArray[iCnt], *(pPointArray + iCnt));
		}
		free(pPointArray);
		// ������ ������ ���� �迭 �Ҵ�
		printf("\n=====================\n");
		char* pCharPoint = 0;
		int iCount = 0;
		pCharPoint = (char*)malloc(sizeof(char) * 100);
		// ��Ƽ����Ʈ���� _getche()==0�̶�� ���� Ȯ��Ű�� �ԷµǾ��ٴ� ���̴�. 
		// ����Ű �Ǵ� home, end,insert���� 0x00E0�� ��ȯ�Ѵ�.
		do {
			int ivalue = _getch(); //_getche();
			if (ivalue != 0 && ivalue != 0x00E0)
			{
				pCharPoint[iCount++] = ivalue;
				printf("*"); // password
			}

		} while (pCharPoint[iCount - 1] != '\r');

		// ���ĺ� �Ǵ� ����Ű�� �Է½� Ȯ��Ű�ڵ�(�ι��� �߰�)�� ��ȯ�ϴ� 
		// ������ �ý��ۿ� ���� �߻��Ѵ�.
		/*do {
				pCharPoint[iCount++] = _getche();
		} while (pCharPoint[iCount - 1] != '\r');*/

		// \n, \r  
		pCharPoint[iCount - 1] = 0;
		printf("\n0x%08x���� : %s", pCharPoint, pCharPoint);
		for (int iCnt = 0; iCnt < iCount; iCnt++)
		{
			printf("\n0x%08X���� : %c", pCharPoint + iCnt, *(pCharPoint + iCnt));
		}
		free(pCharPoint);


		// ������ �迭 ���� �Ҵ�
		printf("\n=====================\n");
		int *lpPoint[10];
		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			lpPoint[iCnt] = (int*)malloc(sizeof(int));
			*lpPoint[iCnt] = iCnt * 10;
			printf("\n0x%08X���� : %d", lpPoint + iCnt, *lpPoint[iCnt]);
		}
		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			free(lpPoint[iCnt]);
		}
		printf("\n=====================\n");

		// 2���� �迭 �ʱ�ȭ �� ����
		int iValue[3][2] = { { 10,20 },{ 30,40 },{ 50,60 } };
		for (int iCnt = 0; iCnt < 3; iCnt++)
		{
			printf("\n*(iValue+%d): %p", iCnt, *(iValue + iCnt));
			printf("\t\tiValue[%d]: %p", iCnt, iValue[iCnt]);
		}
		printf("\n");
		for (int iCnt = 0; iCnt < 3; iCnt++)
		{
			for (int jCnt = 0; jCnt < 2; jCnt++)
			{
				printf("\n*(*(iValue+%d)+%d)  : %d", iCnt, jCnt, *(*(iValue + iCnt) + jCnt));
				printf("\t\t *(iValue[%d]+%d) : %d", iCnt, jCnt, *(iValue[iCnt] + jCnt));
			}
		}


		// ���� ������ �Ҵ� 
		printf("\n=====================\n");
		printf("\n====== ���������� =========\n");
		system("cls");				// cls : ������ɾ� (Clear Screen)
		int *pPtr;
		int **ppPtr;
		int num = 10;
		pPtr = &num;
		//�������� �޸� �ּҴ� �Ϲ�����Ʈ�� ���� �Ұ��ϸ� 
		//�ݵ�� ���������Ϳ� �����ؾ� �Ѵ�.
		ppPtr = &pPtr;//pPtr�� �ּ� ����
		printf("%d\n", **ppPtr);//ppPtr�� �޸� �ּҿ� ����

		/////////////////////////////////////////////////////
		// ��������Ʈ�� �Ҵ��� �ý��� ��Ʈ�� ����ؾ� �Ѵ�.
		unsigned char *array[50];
		unsigned char size = sizeof(array);
		//32 - bit  : sizeof(array) = 200
		//64 - bit  : sizeof(array) = 400
#ifdef _WIN64		
		printf("\n64 - bit Size=%d", sizeof(array));
#else
		printf("\n32 - bit Size=%d", sizeof(array));
#endif	
		// 8����Ʈ ������ �迭 ? 4����Ʈ ������ �迭 ?
		// intptr_t ����ϸ� �ý��� ��Ʈ���� ���� ��ȯ��.
		/*
		intptr_t : �������� �ּҸ� �����ϴµ� ���. 
		�ٸ� ȯ������ �̽��� �����ϰ� ������ ������ ���� ����� �����Ѵ�.
		�ý��� ���ο��� ����ϴ� �����Ϳ� ���� ũ��
		�����͸� ���� ǥ������ ��ȯ�� �� �����ϰ� ����� �� �ִ�.

		uinptr_t :��ȣ ���� ����. type casting(uintprt_t) ��� �ʼ���
		*/


		int  **ppPoint = 0;
		ppPoint = (int **)malloc(sizeof(intptr_t) * 10);
		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			ppPoint[iCnt] = (int *)malloc(sizeof(intptr_t) * 10);
		}

		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			for (int jCnt = 0; jCnt < 10; jCnt++)
			{
				ppPoint[iCnt][jCnt] = iCnt * 10 + jCnt;
			}
		}

		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			printf("\n");
			for (int jCnt = 0; jCnt < 10; jCnt++)
			{
				printf("[%d,%d]=%d", iCnt, jCnt, ppPoint[iCnt][jCnt]);
				printf("[%d,%d]=%d", iCnt, jCnt, *(ppPoint[iCnt] + jCnt));
			}
		}

		for (int iCnt = 0; iCnt < 10; iCnt++)
		{
			free(ppPoint[iCnt]);
		}

		free(ppPoint);

		printf("\n====== ������ �迭=========\n");
		system("cls");

		char *pArray[6];
		for (int iCnt = 0; iCnt < 6; iCnt++)
		{
			pArray[iCnt] = (char*)malloc(sizeof(char) * 4);
		}

		for (int iCnt = 0; iCnt < 6; iCnt++)
		{
			for (int jCnt = 0; jCnt < 3; jCnt++)
			{
				pArray[iCnt][jCnt] = 65 + iCnt * 3 + jCnt;
			}
			pArray[iCnt][3] = 0;
		}

		for (int iCnt = 0; iCnt < 6; iCnt++)
		{
			printf("\n");
			printf("[%d]=%s", iCnt, pArray[iCnt]);
		}

		for (int iCnt = 0; iCnt < 6; iCnt++)
		{
			free(pArray[iCnt]);
		}
		_getch();
	}	
#else
	#include <cstdio>
	#include <cstdlib>
	#include <conio.h>
	#include <iostream>

	void main()
	{													//���� �Ҵ��ϱ�
		// �⺻ void* ���� int*�� ����ȯ
		printf("\n=====================\n");	
		int *pPoint = new int;			// new �ߴµ� �޸� ������ ������ null��ȯ�ϹǷ� �׻� üũ
		*pPoint = 100;
		printf("%0x���� : %d\n", pPoint+0, *(pPoint+0) );
		delete( pPoint );							//		

		printf("\n=====================\n");		
		int *pPointArray = new int[10];
		for( int iCnt = 0; iCnt < 10; iCnt++ )
		{		
			pPointArray[iCnt] = iCnt*10;
			//printf("%d:%d\n", 
			//	pPointArray[iCnt],
			//	*(pPointArray + iCnt));
			std::cout << pPointArray[iCnt] <<"   "<< *(pPointArray+iCnt) <<std::endl;
		}

		delete [] pPointArray;

		std::cout << "\n=====================\n";
		char* pCharPoint = 0;
		int iCount = 0;
		pCharPoint = new char[100];
		do{
			pCharPoint[iCount++] = _getche();						
		}while(pCharPoint[iCount-1] != '\r');
	
		pCharPoint[iCount+1] = 0;
		printf("\n0x%08x���� : %s", pCharPoint, pCharPoint );	
		for( int iCnt = 0; iCnt < iCount; iCnt++ )
		{
			printf("\n0x%08X���� : %c", pCharPoint+iCnt, *(pCharPoint+iCnt) );	
		}
		delete[] pCharPoint;
		//////////////////////////////////////////////////
		printf("\n=====================\n");	
		int *lpPoint[10];
		for( int iCnt = 0; iCnt < 10; iCnt++ )
		{
			lpPoint[iCnt] = new int;
			*lpPoint[iCnt] = iCnt*10;
			printf("\n0x%08X���� : %d", lpPoint+iCnt, *lpPoint[iCnt] );	
		}
		for( int iCnt = 0; iCnt < 10; iCnt++ )
		{
			delete lpPoint[iCnt];
		}
		printf("\n=====================\n");	
		int iValue[3][2] = {{10,20}, {30,40}, {50,60}};
		for( int iCnt = 0; iCnt < 3; iCnt++ )
		{
			printf("\n*(iValue+%d): %p", iCnt, *(iValue+iCnt));
			printf("\t\tiValue[%d]: %p", iCnt, iValue[iCnt]);
		}
		printf("\n");
		for( int iCnt = 0; iCnt < 3; iCnt++ )
		{
			for( int jCnt = 0; jCnt < 2; jCnt++ )
			{
				printf("\n*(*(iValue+%d)+%d)  : %d", iCnt,jCnt, *(*(iValue+iCnt)+jCnt) );
				printf("\t\t *(iValue[%d]+%d) : %d", iCnt,jCnt, *(iValue[iCnt]+jCnt ) );
			}
		}
		printf("\n=====================\n");
		_getch();	
	}
#endif

