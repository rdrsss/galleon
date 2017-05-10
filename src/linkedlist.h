
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#pragma once

namespace hepp {


template<typename T>
class linked_list {
public:
	struct node {
		node() : next_(nullptr), prev_(nullptr) {}


		T value_;

		node* next_;
		node* prev_;
	};


	struct iterator {
		node* ptr_;
	};

	linked_list() : count_(0) {}
	linked_list(const linked_list& rhs) {}
	linked_list(const linked_list&& rhs) {}

	~linked_list() {}


	void add_front(const T& v);
	void add_front(const node &n);

	void add_back(const T& v);
	void add_back(const node &n);

	int count() const { return count_; }

private:
	node begin_;
	node end_;
	
	int count_;

};



} // namespace
#endif
