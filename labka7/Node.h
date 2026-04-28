#pragma once
#include <memory>
#include <iostream>
	template<typename T>
	struct Node

	{
		int index;
		T data;
		std::unique_ptr<Node<T>> pnext;
		//std::weak_ptr<Node<T>> pprevent;
		Node<T>* prev;
		Node() :data(), pnext(nullptr) {};
		Node(const T& val) :data(val), pnext(nullptr) { std::cout << "Node constructor" << std::endl; };


	};



