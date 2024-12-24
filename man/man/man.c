#include "man.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

static Node* CreateNode()
{
	//创建节点
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
	printf("|      牢大幼稚园学生信息管理系统      |\n");
	printf("|=================================           =====|\n");
	printf("|           请选择功能列表             |\n");
	printf("|======================================|\n");
	printf("|          0---------返回              |\n");
	printf("|          1---------输入学生信息      |\n");
	printf("|          2---------显示学生信息      |\n");
	printf("|          3---------保存学生信息      |\n");
	printf("|          4---------读取学生信息      |\n");
	printf("|          5---------添加学生信息      |\n");
	printf("|          6---------删除学生信息      |\n");
	printf("|          7---------计算学生平均成绩  |\n");
	printf("|          8---------显示学生名次      |\n");
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

	//输入学生信息
	printf("输入学生学号>");
	scanf("%llu", &node->stu.number);

	printf("输入学生姓名>");
	scanf("%s", node->stu.name);

	printf("输入学生性别>");
	scanf("%s", node->stu.xibbie);

	printf("输入学生语文成绩>");
	scanf("%f", &node->stu.chinese);

	printf("输入学生数学成绩>");
	scanf("%f", &node->stu.math);

	printf("输入学生英语成绩>");
	scanf("%f", &node->stu.english);

	//插入到链表中
	node->next = list->front;
	list->front = node;
	list->size++;
}

void printStudent(List* list)
{
	printf("=====================================================\n");
	printf("*            欢迎来到牢大幼儿园信息管理系统         |\n");
	printf("----------------------------------------------------|\n");
	printf("         * 学号 *  姓名 * 性别 * 语文 *  数学 * 英语*\n");
	printf("=====================================================\n");

	//遍历链表
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
	//打开文件
	FILE* fp = fopen("students.data", "wb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//写入学生信息
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fwrite(&curNode->stu, sizeof(Student), 1, fp);
		curNode = curNode->next;
	}

	//关闭文件
	fclose(fp);
}

void saveStudentHuman(List* list)
{
	//打开文件
	FILE* fp = fopen("students.txt", "w");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//写入学生信息
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		fprintf(fp, "%llu\t%s\t%s\t%.1f\t%.1f\t%.1f\n", curNode->stu.number, curNode->stu.name,curNode->stu.xibbie,
			curNode->stu.chinese, curNode->stu.math, curNode->stu.english);
		curNode = curNode->next;
	}

	//关闭文件
	fclose(fp);

}

void readStudent(List* list)
{
	//打开文件
	FILE* fp = fopen("students.data", "rb");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//读取学生信息
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

		//插入到链表中
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//关闭文件
	fclose(fp);
}

void readStudentHuman(List* list)
{
	//打开文件
	FILE* fp = fopen("students.txt", "r");
	if (!fp) {
		perror("file open failed");
		return;
	}

	//读取学生信息
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

		//插入链表
		node->next = list->front;
		list->front = node;
		list->size++;
	}

	//关闭文件
	fclose(fp);
}

void statisticsStudentCount(List* list)
{
	//printf("学生总人数为:%d\n", list->size);

	int count = 0;
	Node* curNode = list->front;
	while (curNode != NULL)
	{
		count++;
		curNode = curNode->next;
	}
	printf("学生总人数为:%d\n", count);
}

Node* findStudent(List* list)
{
	if (list->size == 0) {
		return NULL;
	}

	char buffer[32];
	printf("请输入要查找的学生学号或姓名>");
	scanf("%s", buffer);

	//尝试把buffer转成整型
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//按姓名查找
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
		printf("暂无学生~\n");
		return;
	}

	char buffer[32];
	printf("请输入要修改的学生学号或姓名>");
	scanf("%s", buffer);

	//尝试把buffer转成整型
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//按姓名查找
			curNode->stu.number == number) {

			printf("请输入要修改的学生的 语文成绩 数学成绩 英语成绩>");
			scanf("%f %f %f", &curNode->stu.chinese, &curNode->stu.math, &curNode->stu.english);
			printf("修改成功QAQ\n");
			break;
		}
		curNode = curNode->next;
	}

	if (curNode == NULL)
	{
		printf("没有找到该学生,修改失败~\n");
	}

}

void removeStudent(List* list)
{
	if (list->size == 0) {
		printf("暂无学生~\n");
		return;
	}

	char buffer[32];
	printf("请输入要修改的学生学号或姓名>");
	scanf("%s", buffer);

	//尝试把buffer转成整型
	unsigned long long number = -1;
	sscanf(buffer, "%llu", &number);

	Node* curNode = list->front;
	Node* prevNode = NULL;
	while (curNode != NULL)
	{
		if (strcmp(curNode->stu.name, buffer) == 0 ||	//按姓名查找
			curNode->stu.number == number) {
			break;
		}

		prevNode = curNode;
		curNode = curNode->next;
	}

	//是否找到
	if (curNode)
	{
		//要删除的就是第一个节点
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

