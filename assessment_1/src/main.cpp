/*
Assignment 1 - Created by Alex McClung for SENG1120
Semester 2 2016
*/

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main()
{

  string hello = "hello";

  Node* n1 = new Node();
  Node* n2 = new Node(hello, n1, NULL);

  LinkedList* l1 = new LinkedList();

  for (int i=0;i<100;i++)
  {
  	l1->list_insert("abc123");
  	cout << l1->list_length() << endl;
  }

  cout << "zesty dek ov cardz" << endl;
}