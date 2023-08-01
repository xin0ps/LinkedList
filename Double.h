#pragma once
#include <iostream>
using namespace std;

/*
	LinkedList
		1. SingleLinkedList
		2. DoubleLinkedList

*/

class Node
{
public:
	string data;
	Node* next;
	Node* prev;
	Node() :data(), next(), prev() {}
	Node(const string _data) :data(_data), next(), prev() {}
};

class DoubleLinkedList
{
private:
	Node* _head;
	Node* _end;
public:
	DoubleLinkedList() : _head(), _end() {}
	void AddBegin(const string data)
	{
		AddBegin(new Node(data));
	}
	void AddEnd(const string data)
	{
		AddEnd(new Node(data));
	}

	void AddBegin(Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			_end = item;
			return;
		}

		Node* temp = _head;
		_head = item;
		_head->next = temp;
		temp->prev = _head;
	}
	void AddEnd(Node* item)
	{
		if (_head == NULL)
		{
			_head = item;
			_end = item;
			return;
		}

		_end->next = item;
		item->prev = _end;
		_end = item;
	}

	void AddBefore(const string beforeItem, const string newItem)
	{
		Node* newNode = new Node(newItem);
		if (_head == NULL)
		{
			_head = newNode;
			_end = newNode;
			return;
		}

		Node* temp = _head;
		while (temp != NULL)
		{
			if (temp->data == beforeItem)
			{
				Node* save = temp->prev;
				temp->prev = newNode;
				newNode->prev = save;
				save->next = newNode;
				newNode->next = temp;
				return;

			}
			temp = temp->next;
		}


	}
	void AddAfter(const string afterItem, const string newItem)
	{
		Node* newNode = new Node(newItem);
		if (_head == NULL)
		{
			_head = newNode;
			_end = newNode;
			return;
		}

		Node* temp = _head;
		while (temp != NULL)
		{
			if (temp->data == afterItem)
			{
				Node* save = temp->next;
				temp->next = newNode;
				newNode->prev = temp;
				newNode->next = save;
				if (save != NULL)
					save->prev = newNode;
				if (temp == _end)
					_end = newNode;
				return;
			}
			temp = temp->next;
		}
	}


	void DeleteBegin()
	{
		if (_head == NULL) return;

		Node* temp = _head;
		_head = _head->next;

		delete temp;
		_head->prev = NULL;
	}
	void DeleteEnd()
	{
		if (_head == NULL) return;
		_end = _end->prev;
		delete _end->next;
		_end->next = NULL;
	}

	void DeleteVByValue(const string item)
	{
		if (_head == NULL)
			return;

		Node* temp = _head;
		while (temp != NULL)
		{
			if (temp->data == item)
			{
				Node* prevNode = temp->prev;
				Node* nextNode = temp->next;
				if (prevNode != NULL)
					prevNode->next = nextNode;
				else
					_head = nextNode;
				if (nextNode != NULL)
					nextNode->prev = prevNode;
				else
					_end = prevNode;
				delete temp;
				return;
			}
			temp = temp->next;
		}
	}

	void DisplayFront()
	{
		Node* temp = _head;
		cout << "[";
		while (temp->next != NULL)
		{
			cout << temp->data << ",";
			temp = temp->next;
		}
		cout << temp->data << "]";

	}
	void DisplayEnd()
	{
		Node* temp = _end;
		cout << "[";
		while (temp->prev != NULL)
		{
			cout << temp->data << ",";
			temp = temp->prev;
		}
		cout << temp->data << "]";
	}





};



