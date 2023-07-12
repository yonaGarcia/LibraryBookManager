#pragma once
#include "Queue.h"

class QueueVector : public Queue
{
public:
	QueueVector(int max);
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
private:
	int* data;
	int capacity;
	int nextSlot;
	int firstUse;
};
QueueVector::QueueVector(int size) {
	capacity = size + 1;
	data = new int[capacity];
	clear();
}
void QueueVector::clear() {
	nextSlot = 0;
	firstUse = 0;
}

int QueueVector::dequeue()
{
	if (isEmpty()) throw "Queue is empty\n";
	int dataloc = firstUse;
	++firstUse %= capacity;
	return data[dataloc];
}
void QueueVector::enqueue(int val) {
	if ((nextSlot + 1) % capacity == firstUse)
		throw "the Queue is full\n";
	data[nextSlot] = val;
	++nextSlot %= capacity;
}
int QueueVector::front() {
	if (isEmpty())
		throw "Queue is empty\n";
	return data[firstUse];
}
bool QueueVector::isEmpty() const {
	return nextSlot == firstUse;
}
