#include <iostream>
using namespace std;


struct Node
{
	int data;
	Node* link;
};

void head_insert (Node* & head, int num)
{
	Node* iter = new Node;
	iter -> data = num;
	iter -> link = head;
	head = iter;
}

Node* search (Node* head, int target)
{
	for (Node* iter = head; iter != NULL; iter = iter -> link)
	{
		if (iter -> data == target)
			return iter;
	}
	return NULL;
}

void print_list (Node* head)
{
	for (Node* iter = head; iter != NULL; iter = iter -> link)
		cout << iter -> data << " ";
}

void insert (Node* afterMe, int num)
{
	Node* iter = new Node;
	iter -> data = num;
	iter -> link = afterMe ->link;
	afterMe -> link = iter;
}

void remove (Node*& head, int num)
{
	if (head -> data == num)
	{
		Node* temp = new Node;
		temp -> link = head ->link;
		delete head;
		head = temp -> link;
	}

	Node* previous = head;
	Node* iter = head -> link;
	while (iter != NULL)
	{
		if (iter -> data == num)
		{
			Node* temp = new Node;
			temp -> link = iter -> link;
			delete iter;
			previous -> link = temp -> link;
			iter = temp -> link;
		}
		else
		{
			iter = iter -> link;
			previous = previous -> link;
		}
	}	
}

int main ()
{
	Node* head = NULL;
	for (int i=5; i > 0; --i)
	{
		head_insert(head,9);
		head_insert(head,i);
	}

	cout << "1 print: ";
	print_list(head);

	cout << "\n2 print: ";
	cout << search(head,3);
	
	insert (head, 20);
	cout << "\n3 print: ";
	print_list(head);
	
	remove (head,9);
	cout << "\n4 print: ";
	print_list(head);

	remove (head,20);
	cout << "\n5 print: ";
	print_list(head);

	system("PAUSE");
	return 0;
}