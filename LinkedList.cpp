#include <iostream>
using namespace std;
//#include"Double.h"
#include"Single.h"



int main() //single
{
	Node a("resul");
	Node b("ali");
	Node c("filankes");
	a.next = &b;
	SingleLinkedList s;
	s.AddBegin(&a);
	//s.display();
	//s.AddBefore(&b, &c);
	//s.display();
	s.AddBefore(&b, "salam");
	//s.display();
	s.AddAfter(&a, &c);
	//s.display();
	s.AddAfter(&a, "test");
	//s.display();
	//s.DeleteBegin();
	//s.display();
	//s.DeleteEnd();
	//s.display();
	//s.DeleteEnd();
	s.display();
	s.DeleteByValue("test");
	s.display();
}