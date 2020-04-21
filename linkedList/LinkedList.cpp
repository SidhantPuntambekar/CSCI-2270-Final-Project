#include "LinkedList.h"
#include <iostream>
using namespace std;

// Add a new node to the list
void LinkedList::insert(int newKey){

    Node* ptr = head;
    while (ptr != NULL && ptr->key != newKey)
    {
        ptr = ptr -> next;
    }
  //Check if head is Null i.e list is empty
  if(head == NULL)
  {
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(ptr == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = ptr->next;
      ptr->next = newNode;

  }
}

// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }

  // Special case to delete the head
    if (n == 0) 
    {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

  Node *pres = head;
	Node *prev = NULL;

  for (int i = 0; i < n; i++)
  {
    prev = pres;
    pres = pres -> next;
  }
  prev -> next = pres -> next;
  delete pres;
  isDeleted = true;
	return isDeleted;
}

bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    if(head == NULL) {
        cout << "List is empty. Cannot swap" << endl;
        return false;
    }

    Node *prev = head;
    Node *tail = head;

    while (tail->next != NULL)
    {
        prev = tail;
        tail = tail -> next;
    }

    prev -> next = head;
    tail -> next = head -> next;
    head -> next = NULL;
    head = tail;
    isSwapped = true;

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList()
{
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}

// Search for a specified key and return a pointer to that node
Node* LinkedList::searchList(int key) 
{
    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr -> next;
    }
    return ptr;
}