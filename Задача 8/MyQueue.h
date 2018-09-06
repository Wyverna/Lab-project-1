#pragma once
#define MYQUEUE1_EQE  0x0000  // ������� � ������ ������� ������� 
struct Queue               // ���� ���������� �������� 
{
	int Head;           // ������ �������
	int Tail;           // ����� �������
	int Size;           // ������ ������� (����. �����.+1)
	void** Data;        // ��������� ������ ������� 
	Queue(int size)     // ���������� ������ �������  
	{
		Head = Tail = 0;
		Data = new void*[Size = size + 1];
	}
	bool isFull() const;       // ������� ��������a ?
	bool isEmpty()const;       // ������� ����a ? 
};
struct Struct1
{
	int a;
	char b;
};
struct Struct2
{
	char b;
	long a;
};
Queue createQueue(int n);            // n � ����. ���������� 
Queue createQueue(const Queue& pq);  // ������� ������� �� ������� 
bool  enq(Queue& q, void* x);        // �������� x 
void* deq(Queue& q);                 // ������� ������� 
void* peek(const Queue& q);          // �������� ������ �������
int  clearQueue(Queue& q);           // �������� �������
void releaseQueue(Queue& q);         // ���������� ������� 
void appendQueue(Queue& to, const Queue& from);  //�������� ���� ������� � ������ 
void copyQueue(Queue& to, const Queue& from);    // ���������� �������
void RemoveQueue(Queue& to, Queue& from);        //����������� �������
void printQueue(Queue& s);    // ����� �� �����    

