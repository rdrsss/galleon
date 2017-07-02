
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#pragma once

namespace gal {


template<typename T>
class linked_list {
	struct node {
		T value_;

		node* next_;
		node* prev_;
	};

public:
	struct iterator {
		node* ptr_;
	};

	linked_list() : count_(0) {}
	linked_list(const linked_list& rhs) {}
	linked_list(const linked_list&& rhs) {}

	~linked_list();

	void test();


	void add_front(const T& v);
	void add_back(const T& v);

	int count() const { return count_; }

private:
	void add_node_front(node* const n);
	void add_node_back(node* const n);

	node begin_;
	node end_;
	
	int count_;
};

template<typename T>
linked_list<T>::~linked_list() {
	if(begin_.next_) {
		auto current = begin_.next_;
		for(;;) {
			auto p = current;
			if(current->next_){
				current = current->next_;
			}
			if(p) {
				delete p;
				p = nullptr;
			} else {
				break;
			}
		}
	}
}
	
template<typename T>
void linked_list<T>::add_front(const T& v) {
	// Create new node
	const auto n = new node { v, nullptr, nullptr };
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
	const auto n = new node { v, nullptr, nullptr };
	++count_;
	// Add to end of list
	add_node_back(n);
}


template<typename T>
void linked_list<T>::add_node_back(node* const n) {
	if(!end_.prev_) {
		end_.prev_ = n;
	} else {
		end_.prev_->next_ = n;
		end_.prev_ = n;
	}
}

} // namespace
#endif
