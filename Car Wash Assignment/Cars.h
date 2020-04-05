#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

class Cars
{
private:
	Node* _head, * _tail;

public:
	Cars()
	{
		_head = _tail = NULL;
	}
	virtual ~Cars();

	void QueueItem(int);
	int DequeueItem();
	void DisplayList();

};

