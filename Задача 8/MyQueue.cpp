#pragma once
#include "MyQueue.h"
#include <string.h>
#include <iostream>
Queue createQueue(int n)          // �������� ������ ��� �������
{
	return *(new Queue(n));
};

Queue createQueue(const Queue& pq)   // ������� ������� �� �������
{
	Queue *rc = new Queue(pq.Size - 1);
	rc->Head = pq.Head;
	rc->Tail = pq.Tail;
	for (int i = 0; i < pq.Size; i++)
		rc->Data[i] = pq.Data[i];
	return *rc;
}


bool  enq(Queue& q, void* x)      // �������� x 
{
	bool rc = true;
	if (rc = !q.isFull())
	{
		q.Data[q.Tail] = x;
		q.Tail = (q.Tail + 1) % q.Size;
	}
	else
		rc = false;
	return rc;
};

void* deq(Queue& q)               // ������� ������� 
{
	void* rc = (void*)MYQUEUE1_EQE;
	if (!q.isEmpty())
	{
		rc = q.Data[q.Head];
		q.Head = (q.Head + 1) % q.Size;
	}
	else
		rc = NULL;
	return rc;
}

void* peek(const Queue& q)
{
	void* rc = (void*)MYQUEUE1_EQE;
	if (!q.isEmpty())
		rc = q.Data[q.Head];
	else
		rc = NULL;
	return rc;
}

int  clearQueue(Queue& q)       // �������� �������
{
	int rc = (q.Tail - q.Head) >= 0 ?
		(q.Tail - q.Head) : (q.Size - q.Head + q.Tail + 1);
	q.Tail = q.Head = 0;
	return rc;     // �����. ��������� �� �������
}

void releaseQueue(Queue& q)     // ���������� ������� �������
{
	delete[] q.Data;
	q.Size = 1;
	q.Head = q.Tail = 0;
}

void appendQueue(Queue& to, const Queue& from) //�������� ���� ������� � ������ 
{
	for (int i = from.Head; i != from.Tail; (++i) % from.Size)
		enq(to, from.Data[i]);
}

void copyQueue(Queue& to, const Queue& from)   // ���������� �������
{
	clearQueue(to);
	appendQueue(to, from);
}

void RemoveQueue(Queue& to, Queue& from)       // ����������� ������� 
{
	copyQueue(to, from);
	clearQueue(from);
}


bool Queue::isFull() const                      // ������� ��������a ?
{
	return (Head % Size == (Tail + 1) % Size);
}

bool Queue::isEmpty()const                       // ������� ����a ?

{
	return (Head % Size == Tail % Size);
}
void printQueue(Queue& s)    // ����� �� �����    
{
	while (!(s.isEmpty()))
	{
		std::cout << ((Struct1*)peek(s))->a << "  " << ((Struct1 *)peek(s))->b << std::endl;
		deq(s);
	}
}