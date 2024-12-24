#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "man.h"

int main(int argc, char* argv[])
{
	//创建链表
	List list = { 0 };
	//内存设置
	memset(&list, 0, sizeof(List));

	bool isRunning = true;
	while (isRunning)
	{
		switch (menu())
		{
		case Quit:
			isRunning = false;
			break;
		case Entry:
			entryStudent(&list);
			break;
		case Print:
			printStudent(&list);
			break;
		case Save:
			//saveStudent(&list);
			saveStudentHuman(&list);
			break;
		case Read:
			//readStudent(&list);
			readStudentHuman(&list);
			break;
		case Statistics:
			statisticsStudentCount(&list);
			break;
		case Find:
		{
			Node* node = findStudent(&list);
			if (!node) {
				printf("没有找到查询的学生\n");
			}
			else {
				printf("%llu\t%s\t%.1f\t%.1f\t%.1f\n",
					node->stu.number, node->stu.name, node->stu.chinese,
					node->stu.math, node->stu.english);
			}
			break;
		}
		case Alter:
			alterStudent(&list);
			break;
		case Remove:
			removeStudent(&list);
			break;
		default:
			break;
		}

		if (isRunning)
		{
			//让程序暂停一下
			system("pause");
			//清屏
			system("cls");
		}
	}

	//自动保存数据
	saveStudent(&list);
	saveStudentHuman(&list);
	return 0;
}
