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
	printf("�ʱ� �� ����\n");
	printf("������or �������� ���� �ִ� ���������� ���� �Է��ϼ���:");
	scanf_s("%d", &smallcarpark);
	pp = (park*)malloc(sizeof(struct park)*smallcarpark);
	if (pp == NULL)
	{
		printf("����\n");
		return 0;
	}
	allpark = smallcarpark;
	printf("�������� ���� �ִ� ���������� ���� �Է��ϼ���:");
	scanf_s("%d", &bigcarpark);
	smallcarpark = smallcarpark - bigcarpark;
	printf("������ ��� ��й�ȣ ���� ������ ���� (4��)");
	scanf_s("%d",&passward[0]);
	for (i = 0; i < allpark; i++)
	{
		pp[i].cheak = 0;
	}
	for (;;) {
		consol(0);
		printf("��ġ �Ͽ� ���� ������ �ܼ�â���� ���� �Ҵ� ��(1.���� 2.����):");
		scanf_s("%d", &sel);
		switch (sel) {
		case 1:
		{
			system("cls");
			consol(1);
			printf("��ġ �Ͽ� ���� ������ �ܼ�â���� ���� �Ҵ� ��(1.���� 2.����):");
			scanf_s("%d", &sel);
			if (sel == 2)
			{
				for (i = smallcarpark; i < allpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("���� ��ȣ�� �Է��ϼ��� :");
						scanf_s("%d", &pp[i].carnum);
						printf("����� ���� ������ %d�Դϴ�\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
				for (i = 0; i < bigcarpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("���� ��ȣ�� �Է��ϼ��� :");
						scanf_s("%d", &pp[i].carnum);
						printf("����� ���� ������ %d�Դϴ�\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
					if (i <= bigcarpark)
					{
						printf("�˼��մϴ� ���� �ڸ��� �����ϴ�\n");
					}
				}
				}
			}
			if (sel == 1)
			{
				for (i = 0; i < bigcarpark; i++)
				{
					if (pp[i].cheak == 0) {
						printf("���� ��ȣ�� �Է��ϼ��� :");
						scanf_s("%d", &pp[i].carnum);
						printf("����� ���� ������ %d�Դϴ�\n", i);
						pp[i].cheak = 1;
						pp[i].hour = d.tm_hour;
						pp[i].min = d.tm_min;
						break;
					}
					if (i <= bigcarpark)
					{
						printf("�˼��մϴ� ���� �ڸ��� �����ϴ�\n");
					}
				}
			}
			printf("�̿����ּż� �����մϴ�\n");
			Sleep(5000);
			system("cls");
			continue;
		}
		case 2:
		{
			system("cls");
			printf("���� ��ȣ�� �Է��ؼ�����");
			scanf_s("%d", &carnum);
			for (i=0; i <= allpark; i++)
			{
				if (pp[i].carnum == carnum)
				{
					printf("�̿� ����� %d �Դϴ� \n",  paid(pp[i].hour, pp[i].min));
					printf("�����մϴ�\n");
					Sleep(5000);
				}
			}
			system("cls");
			continue;
		}
		case 4:
			{
				system("cls");
				printf("��й�ȣ �Է�");
				scanf_s("%d",&passward[1]);
				if(passward[0]!=passward[1])
				{
					printf("��й�ȣ�� Ʋ���ϴ�\n");
					continue;
				}
				printf("�ʱⰪ�� �ٽ� ����\n");
				free(pp);
				printf("�ʱ� �� ����\n");
				printf("������or �������� ���� �ִ� ���������� ���� �Է��ϼ���:");
				scanf_s("%d", &smallcarpark);
				pp = (park*)malloc(sizeof(struct park)*smallcarpark);
				if (pp == NULL)
				{
				printf("����\n");
				return 0;
				}
				allpark = smallcarpark;
				printf("�������� ���� �ִ� ���������� ���� �Է��ϼ���:");
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
		printf("����                             |                   ����                          | \n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("|                                                |                                                 |\n");
		printf("----------------------------------------------------------------------------------------------------\n");
	}
	else
	{
		printf("����                             |                        ����                     |  \n");
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