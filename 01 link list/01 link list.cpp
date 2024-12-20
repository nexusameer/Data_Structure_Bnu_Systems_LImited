// 01 link list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"StringLinkedList.h"
#include <iostream>
using namespace std;
int main()
{
    StringLinkedList list;

    list.addFront("Hello");
    list.addFront("mine");
    list.addFront("World");

    cout << list.front() << endl;

    list.removeFront();

    cout << list.front() << endl;

    list.addFront("Nine");
    list.removeFront();
}

