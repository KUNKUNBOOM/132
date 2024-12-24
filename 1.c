#pragma warning(disable:4996)
#include<stdio.h>
#define N 100
struct Stu
{
	char xh[11];
	char xm[12];
	char xb[11];
	int age;
	int banji;
	double cj[4 + 2];
};

typedef struct Stu S;
S s[N];

int n = 0;

//1�����ѧ����Ϣ
void addStudent()
{
	if (n >= N)
	{
		printf("�������޷����");
		return;
	}
	else
	{
		//����ѧ��
		printf("������ѧ�ţ�");
		scanf("%s", s[n].xh);
		//��������
		printf("������������");
		scanf("%s", s[n].xm);
		//�����Ա�
		printf("�������Ա�");
		scanf("%s", s[n].xb);
		//��������
		printf("���������䣺");
		scanf("%d", &s[n].age);
		//����༶
		printf("������༶��");
		scanf("%d", &s[n].banji);
		//�����ĸ��ɼ�
		printf("���������ĸ��ɼ���");
		scanf("%lf%lf%lf%lf", &s[n].cj[0], &s[n].cj[1], &s[n].cj[2], &s[n].cj[3]);

		s[n].cj[4] = s[n].cj[0] + s[n].cj[1] + s[n].cj[2] + s[n].cj[3];

		s[n].cj[5] = s[n].cj[4] / 4;

		n++;

		printf("���ѧ����Ϣ�ɹ���\n");

	}
	system("pause");
	system("cls");
}


//�˵�
void showMenu()
{
	printf("**********===========********\n");
	printf("*****  1�����ѧ����Ϣ  *****\n");
	printf("*****  2����ʾѧ����Ϣ  *****\n");
	printf("*****  3���޸�ѧ����Ϣ  *****\n");
	printf("*****  4������ѧ����Ϣ  *****\n");
	printf("*****  5����ƽ����      *****\n");
	printf("*****  6������߷���ͷ�*****\n");
	printf("*****  7�����ܳɼ�����  *****\n");
	printf("*****  8��ɾ��ѧ����Ϣ  *****\n");
	printf("*****  9���˳�         *****\n");
	printf("*****  10�����ѧ����Ϣ  *****\n");
	printf("*****************************\n");
}

//���
void output()
{
	int i, j;
	printf("\n   ѧ��       ����    �Ա�    ����    �༶   �ɼ�1     �ɼ�2     �ɼ�3     �ɼ�4     �ܷ�     ƽ����\n");
	for (i = 0; i < n; i++)
	{
		printf("%-11s", s[i].xh);
		printf("%7s", s[i].xm);
		printf("%7s", s[i].xb);
		printf("%8d", s[i].age);
		printf("%7d", s[i].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[i].cj[j]);
		printf("\n");
	}
	system("pause");
	system("cls");
}

//3���޸�ѧ����Ϣ
void modify()
{
	int flag, age, num, i;
	char number[100], sex[10];
	float score1, score2, score3, score4;
	char s1[100];
	int banji;
	printf("��������Ҫ�޸ĵ�ѧ��������\n");
	getchar();
	gets(s1);
	while (1)
	{
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(s1, s[i].xm) == 0)
			{
				flag = 1;
				printf("***************************************************\n");
				printf("*----1.�޸�ѧ��--------  -  -----2.�޸��Ա�-------*\n");
				printf("*----3.�޸�����--------  -  -----4.�޸İ༶-------*\n");
				printf("*----5.�޸ĳɼ�1-------  -  -----6.�޸ĳɼ�2------*\n");
				printf("*----7.�޸ĳɼ�3-------  -  -----8.�޸ĳɼ�4------*\n");
				printf("*-------------------9.�˳����˵�------------------*\n");
				printf("***************************************************\n\n");
				printf("������˵���ţ�\n");
				scanf("%d", &num);
				switch (num)
				{
				case 1:
					printf("��������ѧ�ţ�\n");
					getchar();
					gets(number);
					strcpy(s[i].xh, number);
					break;
				case 2:
					printf("�������Ա�\n");
					getchar();
					gets(sex);
					strcpy(s[i].xb, sex);
					break;
				case 3:
					printf("���������䣺\n");
					scanf("%d", &age);
					s[i].age = age;
					break;
				case 4:
					printf("������༶��\n");
					scanf("%d", &banji);
					s[i].banji = banji;
					break;
				case 5:
					printf("������ɼ�1��\n");
					scanf("%f", &score1);
					s[i].cj[0] = score1;
					break;
				case 6:
					printf("������ɼ�2��\n");
					scanf("%f", &score2);
					s[i].cj[1] = score2;
					break;
				case 7:
					printf("������ɼ�3��\n");
					scanf("%f", &score3);
					s[i].cj[2] = score3;
					break;
				case 8:
					printf("������ɼ�4��\n");
					scanf("%f", &score4);
					s[i].cj[3] = score4;
					break;
				case 9:return;
				default:printf("������1--8֮������֣�\n");
				}
				if (num > 0 && num < 8)
					printf("�޸ĳɹ���\n");
				break;
			}
		}
		if (flag == 0)
		{
			printf("δ�ҵ���ѧ��������������ѧ��������\n");
			gets(s1);
		}
		s[i].cj[4] = s[i].cj[0] + s[i].cj[1] + s[i].cj[2] + s[i].cj[3];

		s[i].cj[5] = s[i].cj[4] / 4;
	}
	system("pause");
	system("cls");
}

//4������ѧ����Ϣ
void search()
{
	int number, flag, i;
	char s1[100];
	printf("*****************************\n");
	printf("**-------1.��ѧ�Ų�ѯ------**\n");
	printf("**-------2.��������ѯ------**\n");
	printf("**-------3.�˳����˵�------**\n");
	printf("*****************************\n");
	while (1)
	{
		flag = 0;
		printf("������Ҫִ�еĲ�����ţ�\n");
		scanf("%d", &number);
		switch (number)
		{
		case 1:
			printf("��������Ҫ����ѧ����ѧ�ţ�\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(s[i].xh, s1) == 0)
				{
					flag = 1;
					printf("\n   ѧ��       ����    �Ա�    ����    �༶   �ɼ�1     �ɼ�2     �ɼ�3     �ɼ�4     �ܷ�     ƽ����\n");
					printf("%-11s%7s%7s%8d%7d%10.2lf%10.2lf%10.2lf%10.2lf\n", s[i].xh, s[i].xm, s[i].xb, s[i].age, s[i].banji, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].cj[3], s[i].cj[4], s[i].cj[5]);
				}
			}break;
		case 2:
			printf("��������Ҫ����ѧ����������\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(s[i].xm, s1) == 0)
				{
					flag = 1;
					printf("\n   ѧ��       ����    �Ա�    ����    �༶   �ɼ�1     �ɼ�2     �ɼ�3     �ɼ�4     �ܷ�     ƽ����\n");
					printf("%-11s%7s%7s%8d%7d%10.2lf%10.2lf%10.2lf%10.2lf\n", s[i].xh, s[i].xm, s[i].xb, s[i].age, s[i].banji, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].cj[3], s[i].cj[4], s[i].cj[5]);
				}
			}break;
		case 3:return;
		default:printf("����1--3֮�����룡\n");
		}
		if (flag == 0)
			printf("�Ҳ�����ѧ�������������룡\n");
	}
}
//5��ƽ����
void pinjun()
{
	int i, j;
	double one=0, two=0, three=0, four=0, five=0;
	for (i = 0; i < n; i++)
	{
		one = one + s[i].cj[0];
		two=two+ s[i].cj[1];
		three=three+s[i].cj[2];
		four=four+ s[i].cj[3];
		five=five+ s[i].cj[4];
	}
	printf("\n     �ɼ�1ƽ����     �ɼ�2ƽ����     �ɼ�3ƽ����     �ɼ�4ƽ����     �ܷ�ƽ����");
	printf("\n%10.2lf     %10.2lf      %10.2lf      %10.2lf      %10.2lf",one/n,two/n,three/n,four/n,five/n);

}



//6����߷���ͷ�

void zuizhi()
{
	int i, j;
	S p = { "0","0","0",0,0,0,0,0,0,0,0, };
	double temp;
	for (i = 0; i < n - 1; i++)
	{

		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].cj[4] < s[j + 1].cj[4])
			{

				p = s[j];
				s[j] = s[j + 1];
				s[j + 1] = p;
			}
		}
	}
	j = 0;
	printf("\n   ѧ��       ����    �Ա�    ����    �༶   �ɼ�1     �ɼ�2     �ɼ�3     �ɼ�4     �ܷ�     ƽ����\n");
	
		printf("%-11s", s[0].xh);
		printf("%7s", s[0].xm);
		printf("%7s", s[0].xb);
		printf("%8d", s[0].age);
		printf("%7d", s[0].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[0].cj[j]);
		printf("\n");
		printf("%-11s", s[n-1].xh);
		printf("%7s", s[n - 1].xm);
		printf("%7s", s[n - 1].xb);
		printf("%8d", s[n - 1].age);
		printf("%7d", s[n - 1].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[n - 1].cj[j]);
		printf("\n");
	
	system("pause");
	system("cls");
	printf("\n");
	return 0;
}

//7���ܳɼ�����
void paixu()
{
	int i, j ;
	S p = { "0","0","0",0,0,0,0,0,0,0,0, };
	double temp;
	for (i = 0; i < n - 1; i++)
	{
	
		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].cj[4] < s[j + 1].cj[4])
			{

				p = s[j];
				s[j] = s[j + 1];
				s[j + 1] = p;
			}
		}
	}
	j = 0;
	printf("\n   ѧ��       ����    �Ա�    ����    �༶   �ɼ�1     �ɼ�2     �ɼ�3     �ɼ�4     �ܷ�     ƽ����\n");
	for (i = 0; i < n; i++)
	{
		printf("%-11s", s[i].xh);
		printf("%7s", s[i].xm);
		printf("%7s", s[i].xb);
		printf("%8d", s[i].age);
		printf("%7d", s[i].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[i].cj[j]);
		printf("\n");
	}
	system("pause");
	system("cls");
	printf("\n");
	return 0;
}

//8��ɾ��ѧ����Ϣ
void dlt()
{
	int flag, i, j;
	char s1[100];
	printf("������Ҫɾ��ѧ����������\n");
	getchar();
	gets(s1);
	flag = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(s[i].xm, s1) == 0)
		{
			flag = 1;
			for (j = i; j < n - 1; j++)
			{
				s[j] = s[j + 1];
			}
		}
		if (flag == 1) break;
	}
	if (flag == 0) printf("δ�ҵ���ѧ����\n");
	if (flag == 1)
	{
		printf("ɾ���ɹ���\n");
		n--;
	}
	system("pause");
	system("cls");
}
//10���ѧ����Ϣ
void cleanstudent()
{
	n = 0;
	printf("�������ͨѶ¼\n");
	system("pause");
	system("cls");
}

int main()
{
	S abs;
	int select = 0;

	while (1)
	{
		showMenu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			addStudent();
			break;
		case 2:
			output();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
			break;
		case 5:
			pinjun();
			break;
		case 6:
			zuizhi();
			break;
		case 7:
			paixu();
			break;
		case 8:
			dlt();
			break;
		case 9:
			printf("��ӭ�ٴ�ʹ�ã�\n");
			break;
		case 10:
			cleanstudent();
			break;
		dafault:
			break;
		}
	}

	return 0;
}