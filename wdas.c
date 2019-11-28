#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void consol(int i);
int paid(int hour, int min);
typedef struct park 
{
	int hour;
	int min;
	int carnum;
	int parknum;
	int cheak;
}park;
int main()
{
	int i;
	int allpark;
	int smallcarpark;
	int bigcarpark;
	int sel;
	int carnum;
	int passward[2];
	park *pp;
	time_t curr=0;
	struct tm d;
	curr=time(NULL);
    d= *localtime(&curr);
	printf("초기 값 설정\n");
	printf("소형차or 중형차가 들어갈수 있는 주차공간의 수를 입력하세요:");
	scanf_s("%d", &smallcarpark);
	pp = (park*)malloc(sizeof(struct park)*smallcarpark);
	if (pp == NULL)
	{
		printf("오류\n");
		return 0;
	}
	allpark = smallcarpark;
	printf("중형차만 들어갈수 있는 주차공간의 수를 입력하세요:");
	scanf_s("%d", &bigcarpark);
	smallcarpark = smallcarpark - bigcarpark;
	printf("관리자 모드 비밀번호 설정 관리자 모드는 (4번)");
	scanf_s("%d",&passward[0]);
	for (i = 0; i < allpark; i++)
	{
		pp[i].cheak = 0;
	}
	for (;;) {
		consol(0);
		printf("터치 하여 실행 하지만 콘솔창으로 구현 불능 택(1.주차 2.퇴차):");
		scanf_s("%d", &sel);
		switch (sel) {
		case 1:
		{
			system("cls");
			consol(1);
			printf("터치 하여 실행 하지만 콘솔창으로 구현 불능 택(1.중형 2.소형):");
			scanf_s("%d", &sel);
			if (sel == 2)
			{
				for (i = smallcarpark; i < allpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("차량 번호를 입력하세요 :");
						scanf_s("%d", &pp[i].carnum);
						printf("당신의 주차 공간은 %d입니다\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
				for (i = 0; i < bigcarpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("차량 번호를 입력하세요 :");
						scanf_s("%d", &pp[i].carnum);
						printf("당신의 주차 공간은 %d입니다\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
					if (i <= bigcarpark)
					{
						printf("죄송합니다 주차 자리가 없습니다\n");
					}
				}
				}
			}
			if (sel == 1)
			{
				for (i = 0; i < bigcarpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("차량 번호를 입력하세요 :");
						scanf_s("%d", &pp[i].carnum);
						printf("당신의 주차 공간은 %d입니다\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
					if (i <= bigcarpark)
					{
						printf("죄송합니다 주차 자리가 없습니다\n");
					}
				}
			}
			printf("이용해주셔서 감사합니다\n");
			Sleep(5000);
			system("cls");
			continue;
		}
		case 2:
		{
			system("cls");
			printf("차량 번호를 입력해수세요");
			scanf_s("%d", &carnum);
			for (i=0; i <= allpark; i++)
			{
				if (pp[i].carnum == carnum)
				{
					printf("이용 요금은 %d 입니다 \n",  paid(pp[i].hour, pp[i].min));
					printf("감사합니다\n");
					Sleep(5000);
				}
			}
			system("cls");
			continue;
		}
		case 4:
			{
				system("cls");
				printf("비밀번호 입력");
				scanf_s("%d",&passward[1]);
				if(passward[0]!=passward[1])
				{
					printf("비밀번호가 틀립니다\n");
					continue;
				}
				printf("초기값을 다시 설정\n");
				free(pp);
				printf("초기 값 설정\n");
				printf("소형차or 중형차가 들어갈수 있는 주차공간의 수를 입력하세요:");
				scanf_s("%d", &smallcarpark);
				pp = (park*)malloc(sizeof(struct park)*smallcarpark);
				if (pp == NULL)
				{
				printf("오류\n");
				return 0;
				}
				allpark = smallcarpark;
				printf("중형차만 들어갈수 있는 주차공간의 수를 입력하세요:");
				scanf_s("%d", &bigcarpark);
				smallcarpark = smallcarpark - bigcarpark;
				system("cls");
			}
		}
	}
}
void consol(int i)
{
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("|                                                |                                                 |\n");
	printf("|                                                |                                                 |\n");
	printf("|                                                |                                                 |\n");
	printf("|                                                |                                                 |\n");
	printf("|               ");
	if (i == 0)
	{
		printf("주차                             |                   퇴차                          | \n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		printf("중형                             |                        소형                     |  \n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("----------------------------------------------------------------------------------------------------\n");
	}


}
int paid(int hour, int min)
{
	time_t curr=0;
	struct tm d;
	curr=time(NULL);
    d= *localtime(&curr);
	hour = d.tm_hour - hour;
	hour *=10000;
	min = d.tm_min - min;
	min = min > 30 ? 5000 : 0;

	return hour + min;
}