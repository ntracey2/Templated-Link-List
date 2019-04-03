#include <utility>
#include <cassert>
#include "src/ll.h"

using namespace cs126linkedlist;

template<typename ElementType>
LinkedList<ElementType>::LinkedListNode::LinkedListNode(ElementType d) {
	data = d;
	next = NULL;
}

template<typename ElementType>
LinkedList<ElementType>::LinkedList() {
	head = NULL;
}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) {
	head = NULL;
	for (int i = 0; i < values.size(); i++) {
		this->push_back(values.at(i));
	}
}

// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
	this->head = NULL;
	if (!source.empty()) {
		for (auto itr = source.begin(); itr != source.end(); ++itr) {
			this->push_back(*itr);
		}
	}
}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
	this->head = source.head;
	source.head = NULL;
}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {
	this->clear();
	delete head;
}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {
	this->clear();
	if (!source.empty()) {
		for (auto itr = source.begin(); itr != source.end(); ++itr) {
			this->push_back(*itr);
		}
	}
	return *this;
}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {
	this->head = source.head;
	source.head = NULL;
	return *this;
}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
	LinkedListNode *to_add = new LinkedListNode(value);

	if (head == NULL) {
		head = to_add;
	} else {
		to_add->next = head;
		head = to_add;
	}
	
}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {
	LinkedListNode *n = new LinkedListNode(value);

	if (head == NULL) {
		head = n;
	} else {
		LinkedListNode *temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{
	return head->data;
}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {
	LinkedListNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	return temp->data;
}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {
	if (!this->empty()) {
		LinkedListNode *temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {
	if (!this->empty()) {
		if (this->size() == 1) {
			head = NULL;
			return;
		}

		LinkedListNode *temp = head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = NULL;
	}
}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
	if (this->empty()) {
		return 0;
	}

	int s = 0;
	//LinkedList<ElementType>::const_iterator itr = this->begin();
	for (auto itr = this->begin(); itr != this->end(); ++itr) {
		s++;
	}

	return s;
}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

template<typename ElementType>
bool LinkedList<ElementType>::clear_helper(LinkedListNode *n) {
	if (n == NULL) {
		return true;
	}
	if (n->next == NULL) {
		return true;
	}
	if (clear_helper(n->next)) {
		delete n;
		return false;
	}
}

template<typename ElementType>
void LinkedList<ElementType>::clear() {
	if (this->size() == 1) {
		head = NULL;
	} else {
		clear_helper(head);
	}
	head = NULL;
}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {
	if (!list.empty()) {
		for (auto itr = list.begin(); itr != list.end(); ++itr) {
			os << (*itr) << " -> ";
		}
	}
	os << "NULL";
	return os;
}

template<typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
	if (head == NULL || head->next == NULL) {
		return;
	}

	LinkedListNode *previous = head;
	LinkedListNode *current = head->next;

	while (previous != NULL && current != NULL) {
		previous->next = current->next;
		
		delete current;

		previous = previous->next;
		if (previous != NULL) {
			current = previous->next;
		}
	}
}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {
	
	if (size() != rhs.size()) {
		return false;
	}
	if (empty() && rhs.empty()) {
		return true;
	}

	auto itr1 = rhs.begin();
	for (auto itr2 = begin(); itr2 != end(); ++itr2) {
		if (*itr1 != *itr2) {
			return false;
		}
		++itr1;
	}

	return true;
}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType>& rhs) {
	if (lhs == rhs) {
		return false;
	} else {
		return true;
	}
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::operator++() {
	this->current_ = this->current_->next;
	return *this;	
}

template<typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
	return this->current_->data;
}

template<typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(const LinkedList<ElementType>::iterator& other) const {
	if (this->current_ != other.current_) {
		return true;
	} else {
		return false;
	}
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
	iterator i(head);
	return i;
}

template<typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
	LinkedListNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	iterator i(temp);
	return ++i;
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator& LinkedList<ElementType>::const_iterator::operator++() {
	this->current_ = this->current_->next;
	return *this;
}

template<typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
	return this->current_->data;
}

template<typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(const LinkedList<ElementType>::const_iterator& other) const {
	if (this->current_ != other.current_) {
		return true;
	} else {
		return false;
	}
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::begin() const {
	const_iterator i(head);
	return i;
}

template<typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end() const {
	LinkedListNode *temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	const_iterator i(temp);
	return ++i;
}
