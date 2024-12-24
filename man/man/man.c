#include "man.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

static Node* CreateNode()
{
	//�����ڵ�
	Node* node = malloc(sizeof(Node));
	if (!node) {
		printf("malloc failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}

int menu()
{
	printf("========================================\n");
	printf("|      �δ�����԰ѧ����Ϣ����ϵͳ      |\n");
	printf("|=================================           =====|\n");
	printf("|           ��ѡ�����б�             |\n");
	printf("|======================================|\n");
	printf("|          0---------����              |\n");
	printf("|          1---------����ѧ����Ϣ      |\n");
	printf("|          2---------��ʾѧ����Ϣ      |\n");
	printf("|          3---------����ѧ����Ϣ      |\n");
	printf("|          4---------��ȡѧ����Ϣ      |\n");
	printf("|          5---------���ѧ����Ϣ      |\n");
	printf("|          6---------ɾ��ѧ����Ϣ      |\n");
	printf("|          7---------����ѧ��ƽ���ɼ�  |\n");
	printf("|          8---------��ʾѧ������      |\n");
	printf("========================================\n");
	printf("select>");
	int select = -1;
	//error C4996: 'scanf': This function or variable may be unsafe.
	//Consider using scanf_s instead. To disable deprecation, 
	//use _CRT_SECURE_NO_WARNINGS. See online help for details
	scanf("%d", &select);
	return select;
}

void entryStudent(List* list)
{
	Node* node = CreateNode();

	//����ѧ����Ϣ
	printf("����ѧ��ѧ��>");
	scanf("%llu", &node->stu.number);

	printf("����ѧ������>");
	scanf("%s", node->stu.name);

	printf("����ѧ���Ա�>");
	scanf("%s", node->stu.xibbie);

	printf("����ѧ�����ĳɼ�>");
	scanf("%f", &node->stu.chinese);

	printf("����ѧ����ѧ�ɼ�>");
	scanf("%f", &node->stu.math);

	printf("����ѧ��Ӣ��ɼ�>");
	scanf("%f", &node->stu.english);

	//���뵽������
	node->next = list->front;
	list->front = node;
	list->size++;
}

void printStudent(List* list)
{
	printf("=====================================================\n");
	printf("*            ��ӭ�����δ��׶�԰��Ϣ����ϵͳ         |\n");
	printf("----------------------------------------------------|\n");
	printf("         * ѧ�� *  ���� * �Ա� * ���� *  ��ѧ * Ӣ��*\n");
	printf("=====================================================\n");

	//��������
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		printf("*%11u*%s*%s*%f*%f*%f*\n", curNode->stu.number, curNode->stu.name,curNode->stu.xibbie,
			curNode->stu.chinese, curNode->stu.math, curNode->stu.english);
		curNode = curNode->next;
	}
}

void saveStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.data", "wb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(Student), 1, fp);
		curNode = curNode->next;
	}

	//�ر��ļ�
	fclose(fp);
}

void saveStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//д��ѧ����Ϣ
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fprintf(fp, "%llu\t%s\t%s\t%.1f\t%.1f\t%.1f\n", curNode->stu.number, curNode->stu.name,curNode->stu.xibbie,
			curNode->stu.chinese, curNode->stu.math, curNode->stu.english);
		curNode = curNode->next;
	}

	//�ر��ļ�
	fclose(fp);

}

void readStudent(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//��ȡѧ����Ϣ
	while (!feof(fp))
	{
		Node* node = CreateNode();
		if (!node)
			break;

		size_t len = fread(&node->stu, sizeof(Student), 1, fp);
		if (len == 0) {
			free(node);
			break;
		}

		//���뵽������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//�ر��ļ�
	fclose(fp);
}

void readStudentHuman(List* list)
{
	//���ļ�
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//��ȡѧ����Ϣ
	while (!feof(fp))
	{
		Node* node = CreateNode();
		if (!node)
			break;
		if (5 != fscanf(fp, "%llu\t%s\t%s\t%f\t%f\t%f\n", &node->stu.number, node->stu.name,node->stu.xibbie,
			&node->stu.chinese, &node->stu.math, &node->stu.english))
		{
			free(node);
			break;
		}

		//��������
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//�ر��ļ�
	fclose(fp);
}

void statisticsStudentCount(List* list)
{
	//printf("ѧ��������Ϊ:%d\n", list->size);

	int count = 0;
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		count++;
		curNode = curNode->next;
	}
	printf("ѧ��������Ϊ:%d\n", count);
}

Node* findStudent(List* list)
{
	if (list->size == 0) {
		return NULL;
	}

	char buffer[32];
	printf("������Ҫ���ҵ�ѧ��ѧ�Ż�����>");
	scanf("%s", buffer);

	//���԰�bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//����������
			curNode->stu.number == number) {
			return curNode;
		}
		curNode = curNode->next;
	}

	return NULL;
}

void alterStudent(List* list)
{
	if (list->size == 0) {
		printf("����ѧ��~\n");
		return;
	}

	char buffer[32];
	printf("������Ҫ�޸ĵ�ѧ��ѧ�Ż�����>");
	scanf("%s", buffer);

	//���԰�bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//����������
			curNode->stu.number == number) {

			printf("������Ҫ�޸ĵ�ѧ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�>");
			scanf("%f %f %f", &curNode->stu.chinese, &curNode->stu.math, &curNode->stu.english);
			printf("�޸ĳɹ�QAQ\n");
			break;
		}
		curNode = curNode->next;
	}

	if (curNode == NULL)
	{
		printf("û���ҵ���ѧ��,�޸�ʧ��~\n");
	}

}

void removeStudent(List* list)
{
	if (list->size == 0) {
		printf("����ѧ��~\n");
		return;
	}

	char buffer[32];
	printf("������Ҫ�޸ĵ�ѧ��ѧ�Ż�����>");
	scanf("%s", buffer);

	//���԰�bufferת������
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	Node* prevNode = NULL;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//����������
			curNode->stu.number == number) {
			break;
		}

		prevNode = curNode;
		curNode = curNode->next;
	}

	//�Ƿ��ҵ�
	if (curNode)
	{
		//Ҫɾ���ľ��ǵ�һ���ڵ�
		if (prevNode == NULL) {
			list->front = curNode->next;
		}
		else {
			prevNode->next = curNode->next;
		}
		free(curNode);
		list->size--;
	}
}

