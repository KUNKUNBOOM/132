#pragma once

/**
* 学生结构
*/
typedef struct Student
{
	unsigned long long number;	//学号
	char name[32];				//姓名
	char xibbie[32];            //性别
	float chinese;				//语文
	float math;					//数学
	float english;				//英语
}Student;

/*
* 节点 Node
*/
typedef struct Node
{
	Student stu;		//学生
	struct Node* next;	//指向下一个节点的指针
}Node;

/**
 * 链表.
 */
typedef struct List
{
	Node* front;		//指向第一个节点
	int size;			//当前节点数量
}List;


/**
 * 菜单功能.
 */
typedef enum MenuOptions
{
	Quit,			//退出系统
	Entry,			//输入学生
	Print,			//显示学生
	Save,			//更新学生
	Read,			//读取学生
	Statistics,		//统计人数
	Find,			//查找学生
	Alter,			//修改学生
	Remove,			//删除学生
}MenuOptions;


/**
 * 打印菜单，并提示用户选择功能.
 */
int menu();

/**
* 学生录入 Alt + Enter
*/
void entryStudent(List* list);

/**
 * 打印学生.
 */
void printStudent(List* list);

/*
* 保存学生,以二进制的方式保存(打开文件看不懂保存的数据)
*/
void saveStudent(List* list);

/*
* 保存学生，以我们能看懂的方式保存
*/
void saveStudentHuman(List* list);

/**
 * 读取学生,二进制.
 */
void readStudent(List* list);

/**
 * 读取学生，我们能读懂的.
 */
void readStudentHuman(List* list);

/**
 * 统计学生人数.
 */
void statisticsStudentCount(List* list);

/**
* 查找学生
*/
Node* findStudent(List* list);

/**
 * 修改学生.
 */
void alterStudent(List* list);

/**
 * 删除学生.
 */
void removeStudent(List* list);





#pragma once
