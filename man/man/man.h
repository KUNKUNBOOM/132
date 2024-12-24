#pragma once

/**
* ѧ���ṹ
*/
typedef struct Student
{
	unsigned long long number;	//ѧ��
	char name[32];				//����
	char xibbie[32];            //�Ա�
	float chinese;				//����
	float math;					//��ѧ
	float english;				//Ӣ��
}Student;

/*
* �ڵ� Node
*/
typedef struct Node
{
	Student stu;		//ѧ��
	struct Node* next;	//ָ����һ���ڵ��ָ��
}Node;

/**
 * ����.
 */
typedef struct List
{
	Node* front;		//ָ���һ���ڵ�
	int size;			//��ǰ�ڵ�����
}List;


/**
 * �˵�����.
 */
typedef enum MenuOptions
{
	Quit,			//�˳�ϵͳ
	Entry,			//����ѧ��
	Print,			//��ʾѧ��
	Save,			//����ѧ��
	Read,			//��ȡѧ��
	Statistics,		//ͳ������
	Find,			//����ѧ��
	Alter,			//�޸�ѧ��
	Remove,			//ɾ��ѧ��
}MenuOptions;


/**
 * ��ӡ�˵�������ʾ�û�ѡ����.
 */
int menu();

/**
* ѧ��¼�� Alt + Enter
*/
void entryStudent(List* list);

/**
 * ��ӡѧ��.
 */
void printStudent(List* list);

/*
* ����ѧ��,�Զ����Ƶķ�ʽ����(���ļ����������������)
*/
void saveStudent(List* list);

/*
* ����ѧ�����������ܿ����ķ�ʽ����
*/
void saveStudentHuman(List* list);

/**
 * ��ȡѧ��,������.
 */
void readStudent(List* list);

/**
 * ��ȡѧ���������ܶ�����.
 */
void readStudentHuman(List* list);

/**
 * ͳ��ѧ������.
 */
void statisticsStudentCount(List* list);

/**
* ����ѧ��
*/
Node* findStudent(List* list);

/**
 * �޸�ѧ��.
 */
void alterStudent(List* list);

/**
 * ɾ��ѧ��.
 */
void removeStudent(List* list);





#pragma once
