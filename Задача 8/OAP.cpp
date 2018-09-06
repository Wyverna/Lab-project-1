#include "MyQueue.h"
#include<iostream>
using namespace std;
void createnew_queue(Queue main, int n)
{
	Queue Queue1 = createQueue(5);
	Queue Queue2 = createQueue(5);
	for (int i = 0;i < (main.Size-1);i++)
	{
		if (i > (n-1))
		{
			enq(Queue1, main.Data[i]);
		}
		else
		{
			enq(Queue2, main.Data[i]);
		}
	}
	printQueue(Queue1);
	std::cout << "------------------------------------" << std::endl;
	printQueue(Queue2);
}
int main()
{
	Struct1 a1 = { 1, 'q' };
	Struct1 a2 = { 2, 'w' };
	Struct1 a3 = { 3, 'e' };
	Struct2 b1 = { 'a', 1 };
	Struct2 b2 = { 's', 2 };
	Struct2 b3 = { 'd', 3 };
	Struct2* b4 = new Struct2;
	b4->a = 4;
	b4->b = 'f';
	Struct1* a4 = new Struct1;
	a4->a = 4;
	a4->b = 'r';
	Queue q1 = createQueue(3);
	enq(q1, &a1);
	enq(q1, &a3);
	printQueue(q1);
	//. . . . . . . . . . . . . . . . . . .
	Struct1* x = (Struct1*)peek(q1);
	x = (Struct1*)deq(q1);
	//. . . . . . . . . . . . . . . . . . .
	Queue q2 = createQueue(q1);
	enq(q1, a4);
	clearQueue(q1);
	copyQueue(q1, q2);
	Queue q3 = createQueue(5);
	enq(q3, &a3);
	enq(q3, &a2);
	enq(q3, &a3);
	enq(q3, &a2);
	enq(q3, &a2);
	cout << "----------------------"<<endl;
	createnew_queue(q3, 3);
	system("pause");
	return 0;
}


