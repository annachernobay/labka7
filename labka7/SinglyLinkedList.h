#pragma once
#include "Node.h"
#include <memory>
template<typename T>


class SinglyLinkedList
{
private:
	int size = 0;
	std::unique_ptr<Node<T>> phead =  std::make_unique<Node<T>>() ;

public:

	SinglyLinkedList();
	SinglyLinkedList(T data);
	~SinglyLinkedList()=default;

	void addFront(const T& data);
	void addBack(const T& data);

    void deleteFront();
	void deleteBack();

	T& operator[](int index);
	void deleteByIndex(int index);
	void addByIndex(const T& data, int index);

	int getSize() const;
	bool isEmpty() const;
	const T* findElement(const T& data) const;
	void printList() const;



};

