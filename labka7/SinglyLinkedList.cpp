#include "SinglyLinkedList.h"
#include "MyException.h"
#include <exception>
#include <iostream>
#include <memory>

template<typename T> 
SinglyLinkedList<T>::SinglyLinkedList() {
	std::cout << "Default constructor" << std::endl;
	size = 0;
	phead = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T data) {
	phead->data = data;
	phead->pnext = nullptr;
	size++;
	std::cout << "SinglyLinkedList with one element" << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::addFront(const T& data) {
	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data);

	if (phead == nullptr) {
		phead = std::move(newNode);
	}
	else {
		newNode->pnext = std::move(phead);
		phead = std::move(newNode);
	}
	size++;
	std::cout << "SinglyLinkedList addFront element" << std::endl;
}



template<typename T>
void SinglyLinkedList<T>::addBack(const T& data) {
	std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(data);
	if (phead == nullptr) {
		phead = std::move(newNode);
	}
	else {
		Node<T>* temp = phead.get();

		while (temp->pnext) {
			temp = temp->pnext.get();
		}

		temp->pnext = std::move(newNode);
	}
	std::cout<< "SinglyLinkedList addBack element" << std::endl;
	size++;
}

template<typename T>
void SinglyLinkedList<T>::deleteFront()
{
	if (phead == nullptr) {
		throw MyException("SinglyLinkedList is already empty");
	}

	phead = std::move(phead->pnext);
	size--;
	std::cout << "SinglyLinkedList deleteFront element" << std::endl;
}

template<typename T>
void SinglyLinkedList<T>::deleteBack()
{
	if (phead == nullptr) {
		throw MyException("SinglyLinkedList is already empty");
	}

	if (!phead->pnext) {
	 phead = nullptr;
		
	
	}

	Node<T>* prev = phead.get();
	while (prev->pnext->pnext) {
		prev = prev->pnext.get();
	}

	prev->pnext.reset();
	size--;
	std::cout << "SinglyLinkedList deleteBack element" << std::endl;
}




template<typename T>
void SinglyLinkedList<T>::addByIndex(const T& data, int index)
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

		Node<T>* prev = phead.get();
		for (int i = 0; i < index - 1; ++i) {
			prev = prev->pnext.get();
		}

		newNode->pnext = std::move(prev->pnext);
		prev->pnext = std::move(newNode);
		std::cout << "SinglyLinkedList addByIndex element" << std::endl;
		size++;
	
}


template<typename T>
void SinglyLinkedList<T>::deleteByIndex(int index)
{
	if (index<0 || index>size) {
		throw MyException("out of range");
	}
	if (phead == nullptr) {
		throw MyException("SinglyLinkedList is already empty");
	}
	else {

		if (index == 0) {
			phead = std::move(phead->pnext);

		}

		else {
			Node<T>* prev = phead.get();
			for (int i = 0; i < index - 1; ++i) {
				prev = prev->pnext.get();
			}
			prev->pnext = std::move(prev->pnext->pnext);


			std::cout << "SinglyLinkedList deleteByIndex element" << std::endl;
			size--;
		}
	}
}



template<typename T>
const T* SinglyLinkedList<T>::findElement(const T& data) const {
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
int SinglyLinkedList<T>::getSize() const
{
std::cout << "Size: " << size << std::endl;
	return size;
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() const
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
void SinglyLinkedList<T>::printList() const
{
	Node<T>* current = phead.get();

	while (current != nullptr) {
		std::cout << current->data << " ";
		current = current->pnext.get();
	}

	std::cout << std::endl;
}

template<typename T>
T& SinglyLinkedList<T>::operator[](int index)
{
	if (index<0 || index>size) {
		throw MyException("out of range");
	}

	std::cout << "access by index operator[]" << std::endl;
	Node<T>* current = phead.get();
	int i = 0;

	while (current != nullptr)
	{
		if(i == index)
		{ return current->data; }
		current = current->pnext.get();
		i++;
		}

	
}

