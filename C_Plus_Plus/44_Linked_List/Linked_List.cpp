/*
Linked list: It is linear data structure which collection of node
Node: it contain data and address of next node
Need: dynamic data structure you can grow and shrink in run time
Advatages: Insertion and delation is easy in ll
not store in contineous memrory location
Storing data in heap
Types of linked list
1)Singly LL
2)Doublly LL
3)Circular LL
4)Circular DLL

Implementaion of node

*/
// A simple C++ program for
// traversal of a linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n)
{
	while (n != NULL) {
		cout << n->data << " ";
		n = n->next;
	}
}

// Driver's code
int main()
{
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	// allocate 3 nodes in the heap
	head = new Node();
	second = new Node();
	third = new Node();

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with second

	second->data = 2; // assign data to second node
	second->next = third;
	cout<<"third="<<second<<endl;
    cout<<"thirdda="<<third<<endl;
	third->data = 3; // assign data to third node
	third->next = NULL;

	// Function call
	printList(head);

	return 0;
}

// This is code is contributed by rathbhupendra
