#include <iostream>
#include <ctime> 
using namespace std;

//class IntList
//{
//private:
//	int num;
//	IntList* next;
//public:
//	IntList(): num(0), next(NULL) {}
//	IntList(int n, IntList* link): num(n), next(link) {}
//	int getNum() const { return num; }
//	IntList* getNext() const { return next; }
//	void setNum(int n) { num = n; }
//	void setNext(IntList* link) { next = link; }
//};
//
//void head_insert (IntList* & head, int theData)
//{
//	head = new IntList(theData,head);
//}
//bool isIncr (IntList* head)
//{
//	IntList* iter = head;
//	while (iter->getNext() != NULL)
//	{
//		if (iter->getNum() >= iter->getNext()->getNum())
//			return false;
//		iter = iter->getNext();
//	}
//	return true;
//}
//void print_list(IntList* head)
//{
//	for (IntList* iter = head; iter != NULL; iter = iter->getNext())
//		cout << iter->getNum() << " ";
//	cout << endl;
//}
//bool isPrime(int num)
//{
//	for (int i = 2; i < num; i++)
//	{
//		if (num % i == 0)
//			return false;
//	}
//	return true;
//}
//bool primeInvolve (IntList* head)
//{
//	IntList* iter = head;
//	while (iter != NULL)
//	{
//		if(isPrime(iter->getNum()))
//			return true;
//		iter = iter->getNext();
//	}
//	return false;
//}

struct Node
{
	int num;
	Node* next;
};

void left_shift(Node*& head)
{
	if (head == NULL)
	{
		cout << "Empty! ";
		return;
	}
	else if (head->next == NULL)
		return;
	
	Node* temp = head;
	Node* iter = head;
	head = head->next;
	
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	iter->next = temp;
	iter->next->next = NULL;
	
	

}
void print_list(Node* head) 
{
	while (head != NULL)
	{
		cout << head->num << " ";
		head = head->next;
	}
	cout << endl;
}

void head_insert (Node* & head, int n)
{
	Node* temp = new Node;
	temp->next = head;
	temp->num = n;
	head = temp;
}
int main()
{
	/*srand(time(0));
	IntList* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		head_insert(head,rand()%100+1);
	}
	print_list(head);
	cout << isIncr(head) << endl; 
	cout << primeInvolve(head) <<endl;
	
*/
	Node* temp = NULL;
	for (int i = 1; i < 10; i++)
	{
		head_insert(temp,i);
	}
	print_list(temp);
	left_shift(temp);
	print_list(temp);
	
	
	//delete head;

	system("PAUSE");
	return 0;
}