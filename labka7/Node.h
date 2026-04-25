#pragma once
#include <memory>
	template<typename T>
	struct Node

	{
		int index;
		T data;
		std::unique_ptr<Node<T>> pnext;
		//std::weak_ptr<Node<T>> pprevent;

	};



