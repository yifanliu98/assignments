#include <iostream>
using namespace std;

class Node
{
private: 
	int data;
	Node* link;
public: 
	Node ();
	Node (int value, Node* next);
	int getData () const { return data;}
	Node* getLink () const { return link;}
	void setData (int value) { data = value;}
	void setLink (Node* next) { link = next;}
	
	friend void head_insert (Node* &head, int num);
	friend void Print_List (Node* head);
	friend void insert (Node* afterMe, int num);
	friend void remove (Node*& head, int num);
	friend Node* search (Node* head, int target);

};
Node::Node()
{
	data = 0;
	link = NULL;
}
Node::Node(int value, Node* next)
{
	data = value;
	link = next;
}
void head_insert (Node* &head, int num)
{
	head = new Node (num,head);
}
void print_list (Node* head)
{
	for (Node* iter = head; iter != NULL; iter = iter -> getLink())
		cout << iter -> getData() << " ";
}
void insert (Node* afterMe, int num)
{
	Node* iter = new Node(num,afterMe -> getLink());
	afterMe -> setLink(iter);
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
			previous = previous  -> link;
		}
	}	
}




Node* mergeLists (Node* & list1, Node* & list2)
{
	Node* head = new Node;
	if (list1 -> getData() > list2 -> getData())
	{
		


	}
	while (list1 != '\0' && list2 != '\0')
	{
		if (list1 == NULL)
		{
			head -> setLink(list2);
			list2 = list2 -> getLink();
		}
		if (list2 == NULL)
		{
			head -> setLink(list1);
			list1 = list1 -> getLink();
		}
		if (list1 -> getData() <= list2 -> getData())
		{
			head -> setLink(list1);
			list1 = list1 -> getLink();
		}
		else
		{
			head -> setLink(list2);
			list2 = list2 -> getLink();
		}
	}
	return head;
}






int main ()
{
	Node* head = NULL;
	for (int i=5; i > 0; --i)
	{
		head_insert(head,9);
		head_insert(head,i);
	}

	Node* h = NULL;
	for (int i=5; i > 0; --i)
	{
		head_insert(head,9);
		head_insert(head,i-1);
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

	print_list(mergeLists(head,h));


	system("PAUSE");
	return 0;
}