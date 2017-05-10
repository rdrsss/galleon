
#include "linkedlist.h"

namespace hepp {

// TODO :: create allocators

template<typename T>
void linked_list<T>::add_front(const T& v) {
	// Create new node
	auto n = new node { v, nullptr, nullptr };
	++count_;
	// Add to front of list
	add_front(n);
}
	

template<typename T>
void linked_list<T>::add_front(const node &n) {
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
	add_back(n);
}


template<typename T>
void linked_list<T>::add_back(const node &n) {
	if(!end_.prev_) {
		end_.prev_ = n;
	} else {
		end_.prev_->next_ = n;
		end_.prev_ = n;
	}
}

} // namespace
