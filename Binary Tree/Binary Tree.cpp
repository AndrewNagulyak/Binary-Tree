// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Tree.cpp"
using namespace std;

int main()
{
	
	Tree<int> t2;
	Tree<int> t1;
	t1.Add(10);
	t1.Add(6);
	t1.Add(30);
	t1.Add(4);
	t1.Add(8);
	t1.Add(28);
	t1.Add(42);
	/*t1.Add(7);
	t1.Add(10);
	t1.Add(3);
	t1.Add(5);
	t1.Add(29);
	t1.Add(41);
	t1.Add(49);
	t1.Add(27);*/







	t1.print();
	cout << endl;
	cout <<"Nodes :"<< t1.GetNodes(2)<<endl;
	cout << "Leaves : "<<t1.GetLeaves() << endl;
	
	cout << "Height : " << t1.GetHeight() << endl;
	cout << endl;
	t2.AddF(10);
	t2.AddF(30);
	t2.AddF(6);
	t2.AddF(4);
	t2.AddF(8);
	t2.AddF(28);
	t2.AddF(42);
	//t2.Add(7);
	//t2.Add(10);
	//t2.Add(3);
	//t2.Add(5);
	//t2.Add(29);
	//t2.Add(41);
	//t2.Add(49);
	//t2.Add(27);







	t2.print();

	cout << "Nodes :" << t2.GetNodes(2) << endl;
	cout << "Leaves : " << t2.GetLeaves() << endl;

	cout << "Height : " << t2.GetHeight() << endl;


	cout << "Isomorfic - 1 ; Not - 0 : " << t1.IsIsomorf(t2)<<endl;
	t1.IsSame(t2);
	

}


