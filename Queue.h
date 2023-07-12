#pragma once
#include <iostream>

//Abstract class
using namespace std;
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(int value) = 0;
	virtual int dequeue() = 0;
	virtual int front() = 0;
	virtual bool isEmpty() const = 0;
};

