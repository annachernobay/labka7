#pragma once
#include <memory>
	template<typename T>
	struct Node

	{
		T data;
		std::unique_ptr<Node<T>> pnext;
		srd::unique_ptr<Node<T>> pprevent;

	};



