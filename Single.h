#pragma once
#include <iostream>
using namespace std;



class Node
{
public:
	string data;
	Node* next;
	Node() :data(), next() {}
	Node(const string _data) :data(_data), next() {}
};


class SingleLinkedList
{
private:
	Node* _head;
public:
	SingleLinkedList() :_head() {}



	// AddBegin(Node* item)
	void AddBegin(Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}

		Node* temp = _head;
		_head = item;
		_head->next = temp;
		temp = NULL;
	}

	// AddBegin(string item)
	void AddBegin(string item)
	{
		AddBegin(new Node(item));
	}

	// AddEnd(Node* item)
	// 
	void AddEnd(Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}
		Node* temp = _head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = item;
	}

	// AddEnd(string item)
	void AddEnd(string item)
	{
		Node* newNode = new Node(item);

		if (_head == NULL)
		{
			_head = newNode;
			return;
		}


		Node* temp = _head;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}


	// AddBefore(const Node* _item, string item)
	void AddBefore(const Node* beforeitem, string item)
	{
		AddBefore(beforeitem, new Node(item));
	}
	void AddBefore(const Node* beforeitem, Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}
		Node* temp = _head;
		while (temp != NULL)
		{
			if (temp->next == beforeitem) {
				Node* save = temp->next;
				temp->next = item;
				item->next = save;
			}
			temp = temp->next;
		}
	}


	// AddAfter(const Node* _item, string item)
	void AddAfter(const Node* Afteritem, string item)
	{
		AddAfter(Afteritem, new Node(item));
	}
	void AddAfter(const Node* Afteritem, Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			return;
		}
		Node* temp = _head;
		while (temp != NULL)
		{
			if (temp == Afteritem) {
				Node* save = temp->next;
				temp->next = item;
				item->next = save;
			}
			temp = temp->next;
		}

	}


	// DeleteBegin()
	void DeleteBegin()
	{
		if (_head != NULL)
		{
			
			_head = _head->next;
			
		}
		
	}


	// DeleteEnd()
	void DeleteEnd()
	{
		if (_head != NULL)
		{
			Node* save = _head;
			while (_head->next->next != NULL)
			{
				_head = _head->next;
			}
			
			_head->next = NULL;
			_head = save;
		}
	}

	// DeleteByValue(const string item)
	void DeleteByValue(const string item)
	{
		if (_head != NULL)
		{
			Node* tmp = _head;
			while (_head->next->data != item)
			{
				_head = _head->next;
			
			}
			if (_head->next->data == item)
			{
				_head->next = _head->next->next;
				_head = tmp;
			}
			


		}

	}

	Node* SearchValue(const string item)
	{
		{
			if (_head != NULL)
			{
				Node* tmp = _head;
				while (_head->next->data != item)
				{
					_head = _head->next;

				}
				if (_head->next->data == item)
				{
					return _head->next;

				}
				else {
					_head = tmp;
				}



			}

		}
	}

	// display()  => cout overloading
	void display()
	{
		Node* temp = _head;
		cout << "[";
		while (temp->next != NULL)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << "]"<<endl;
	}



};



