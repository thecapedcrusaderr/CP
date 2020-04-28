#include <bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *next;
};

struct node *head = NULL;

void insert(int value)
{
  node *newNode = new node();
  newNode->data = value;
  newNode->next = head;
  head= newNode;
}

void display()
{
  node *temp = head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}

int main()
{
  // Here we would try to insert different values inside the linked list

  insert(1);
  insert(4);
  insert(5);
  display();
}
