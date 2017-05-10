
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#pragma once

namespace hepp {


template<typename T>
class linked_list {
public:
	struct node {
		node() : next_(nullptr), prev_(nullptr) {}
		node(const T& v) : node() { value_ = v; }

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

	void test();


	void add_front(const T& v);
	void add_node_front(node* const n);

	void add_back(const T& v);
	void add_node_back(const node &n);

	int count() const { return count_; }

private:
	node begin_;
	node end_;
	
	int count_;

};


template<typename T>
void linked_list<T>::add_front(const T& v) {
	// Create new node
	auto n = new node(v);
	++count_;
	// Add to front of list
	add_node_front(n);
}
	

template<typename T>
void linked_list<T>::add_node_front(node* const n) {
	// Check if there is an existing front.
	if (!begin_.next_) {
		// Set to next
		begin_.next_ = n;
	} else {
		begin_.next_->prev_ = n;
		begin_.next_ = n;
	}
}


template<typename T>
void linked_list<T>::add_back(const T& v) {
	// Create new node
	auto n = new node { v, nullptr, nullptr };
	++count_;
	// Add to end of list
	add_node_back(n);
}


template<typename T>
void linked_list<T>::add_node_back(const node &n) {
	if(!end_.prev_) {
		end_.prev_ = n;
	} else {
		end_.prev_->next_ = n;
		end_.prev_ = n;
	}
}


} // namespace

#endif
