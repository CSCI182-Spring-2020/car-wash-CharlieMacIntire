#include <iostream>

#include "Cars.h"
#include "Node.h"
using namespace std;


	// Process a car into the queue
	void Cars::QueueItem(int newValue)
	{
		Node* temp = new Node;
		temp->value = newValue;
		temp->next = NULL;

		if (_head == NULL)	// Empty List
		{
			_head = _tail = temp;
		}
		else
		{
			_tail->next = temp;
			_tail = temp;
		}
		cout << "Queued Item" << endl;
	}


/// <summary>
/// Dequeues the next item in the queue
/// </summary>
/// <returns>The value of the next node</returns>
int Cars::DequeueItem()
{
	try {
		// Is empty?
		if (_head == NULL)
			throw exception("Cannot dequeue because the queue is empty");

	}
	catch (exception & ex)
	{
		cout << "Error Found: " << ex.what() << endl;
	}
	Node* temp = _head;
	_head = temp->next;

	// Set the new head to maintain the list
	// even if the next it is NULL (empty)
	if (_head == NULL)
		_tail = NULL;

	int nReturn = temp->value;
	delete temp;

	cout << "Dequeued Node" << endl;
	return nReturn;
}

/// <summary>
/// Display the entire list as it exists currently
/// </summary>
void Cars::DisplayList()
{
	cout << "Cars Values" << endl;
	// If empty, just return nothing
	if (_head == NULL)
		return;

	Node* temp = _head;

	// Loop through until all item have been printed
	while (1)
	{
		cout << temp->value << endl;

		// If at end, exit
		if (temp == _tail)
			return;

		temp = temp->next;
	}
}

/// <summary>
/// Destructor
/// </summary>
Cars::~Cars()
{
	Node* temp;
	while (_head != NULL)
	{
		temp = _head;
		_head = temp->next;
		delete temp;
	}
}
