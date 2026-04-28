#include "DoubleLinkedList.h"
#include "MyException.h"
#include <iostream>
#include <memory>

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
	std::cout << "Default constructor" << std::endl;
	size = 0;
	ptail = nullptr;
	phead = nullptr;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(T data) {
	phead->data = data;
	phead->pnext = nullptr;
	size++;
	std::cout << "DoubleLinkedList with one element" << std::endl;
}

template<typename T>
void DoubleLinkedList<T>::addFront(const T& data) {
	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data);

	if (phead == nullptr) {
		phead = std::move(newNode);
		ptail = phead.get();
	}
	else {
		phead->prev = newNode.get();
		newNode->pnext = std::move(phead);
		phead = std::move(newNode);
	}
	size++;
	std::cout << "DoubleLinkedList addFront element" << std::endl;
}



template<typename T>
void DoubleLinkedList<T>::addBack(const T& data) {
	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data);
	if (phead == nullptr) {
		phead = std::move(newNode);
		ptail = phead.get();


	}
	else {

		newNode->prev = ptail;
		ptail->pnext = std::move(newNode);
		ptail = ptail->pnext.get();

	}
	std::cout << "DoubleLinkedList addBack element" << std::endl;
	size++;
}

template<typename T>
void DoubleLinkedList<T>::deleteFront()
{
	if (phead == nullptr) {
		throw MyException("DoubleLinkedList is already empty");
	}

	phead = std::move(phead->pnext);

	if (phead !== nullptr) {
		phead->prev = nullptr;
	}
	else {
		ptail = nullptr;  
	}

	size--;
	std::cout << "DoubleLinkedList deleteFront element" << std::endl;
}

template<typename T>
void DoubleLinkedList<T>::deleteBack()
{
	if (phead == nullptr) {
		throw MyException("DoubleLinkedList is already empty");
	}
	else if (phead.get() == ptail) {
		ptail = nullptr;
		phead = nullptr;
	}


	else {
		ptail = ptail->prev;
		ptail->pnext.reset();

	}
	


	size--;
	std::cout << "DoubleLinkedList deleteBack element" << std::endl;
}




template<typename T>
void DoubleLinkedList<T>::addByIndex(const T& data, int index)
{
	if (index<0 || index>size) {
		throw MyException("out of range");

	}
	if (index == 0) {
		addFront(data);
		return;
	}
	if (index == size) {
		addBack(data);
		return;
	}

	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data);

	Node<T>* current = phead.get();
	for (int i = 0; i < index - 1; i++) {
		current = current->pnext.get();
	}

	newNode->pnext = std::move(current->pnext);
		current->pnext = std::move(newNode);

	std::cout << "DoubleLinkedList addByIndex element" << std::endl;
	size++;

}


template<typename T>
void DoubleLinkedList<T>::deleteByIndex(int index)
{
	if (index<0 || index>=size) {
		throw MyException("out of range");
	}
	if (phead == nullptr || ptail == nullptr) {
		throw MyException("DoubleLinkedList is already empty");
	}

		if (index == 0) {
			phead = std::move(phead->pnext);
			if (phead == nullptr) {
				ptail = nullptr;
			}

		}

		else {
			Node<T>* current = phead.get();
			for (int i = 0; i < index - 1; ++i) {
				current = current->pnext.get();
			}
			
			if (index == size - 1) { 
				current->pnext.reset();
				ptail = current;
			}
			else {
				current->pnext = std::move(current->pnext->pnext);
			}
		}

		
	
			std::cout << "DoubleLinkedList deleteByIndex element" << std::endl;
			size--;
		
	
}



template<typename T>
const T* DoubleLinkedList<T>::findElement(const T& data) const {
	Node<T>* temp = phead.get();

	while (temp != nullptr)
	{
		if (temp->data == data) {
			std::cout << "findElement " << data << " succesfully" << std::endl;
			return &temp->data;

		}
		temp = temp->pnext.get();

	}
	std::cout << "findElement doest not exist" << std::endl;
	return nullptr;


}

template<typename T>
int DoubleLinkedList<T>::getSize() const
{
	std::cout << "Size: " << size << std::endl;
	return size;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
	if (size == 0) {
		std::cout << "The list is empty" << std::endl;
		return true;

	}
	else {
		std::cout << "The list is not empty" << std::endl;
		return false;
	}
}

template<typename T>
void DoubleLinkedList<T>::printList() const
{
	Node<T>* current = phead.get();

	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->pnext.get();
	}

	std::cout << std::endl;
}

template<typename T>
T& DoubleLinkedList<T>::operator[](int index)
{
	if (index<0 || index>size) {
		throw MyException("out of range");
	}

	std::cout << "access by index operator[]" << std::endl;
	Node<T>* current = phead.get();
	int i = 0;

	while (current != nullptr)
	{
		if (i == index)
		{
			return current->data;
		}
		current = current->pnext.get();
		i++;
	}


}

