#include <utility>
#include <cassert>
#include "ll.h"

using cs126linkedlist::LinkedList;

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

}

// Copy constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {

}

// Move constructor
template<typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template<typename ElementType>
LinkedList<ElementType>::~LinkedList() {

}

// Copy assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (const LinkedList<ElementType>& source) {

}

// Move assignment operator
template<typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator= (LinkedList<ElementType>&& source) noexcept {

}

template<typename ElementType>
void LinkedList<ElementType>::push_front(ElementType value) {
	LinkedListNode *to_add = new LinkedListNode(value);

	if (head == NULL) {
		head = to_add;
	}
	else {
		to_add->next = head;
		head = to_add;
	}
	
}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {

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

}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {

}

template<typename ElementType>
int LinkedList<ElementType>::size() const {
	int s = 1;
	LinkedList<int>::const_iterator itr = this->begin();
	for (; itr != this->end(); ++itr) {
		s++;
	}

	return s;
}

template<typename ElementType>
bool LinkedList<ElementType>::empty() const {

}

template<typename ElementType>
void LinkedList<ElementType>::clear() {

}

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list) {

}

template<typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {

}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {

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
	if (this->current_->next != other.current_->next) {
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
	return i;
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
	if (this->current_->next != other.current_->next) {
		return true;
	}
	else {
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
	return i;
}
