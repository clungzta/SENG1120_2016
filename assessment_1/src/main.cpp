/*
Assignment 1 - Created by Alex McClung for SENG1120
Semester 2 2016
*/

#include <iostream>
#include <cstdlib>
#include "Node.h"

using namespace std;

int main()
{

  string hello = "hello";

  Node* n1 = new Node();
  Node* n2 = new Node(hello, n1);

  cout << "n1 next " << n1->get_next_link() << " n2 data " << n2->get_data() << endl;

  cout << "zesty dek ov cardz" << endl;
}