
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#pragma once

namespace hepp {


template<typename T>
class linked_list {
public:
	template<typename T>
	struct node {
		T value_;

		node* next_;
		node* prev_;
	};


	void add_front(const T& v);
	void add_front(const node<T> &node);

	void add_back(const T& v);
	void add_back(const node<T> &node);

};



} // namespace
#endif
