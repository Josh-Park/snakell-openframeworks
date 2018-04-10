#include <utility>
#include "ll.h"

template<typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {

}

template<typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType> &values) : head_(nullptr), tail_(nullptr), size_(0) {

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

}

template<typename ElementType>
void LinkedList<ElementType>::push_back(ElementType value) {

}

template<typename ElementType>
ElementType LinkedList<ElementType>::front() const{

}

template<typename ElementType>
ElementType LinkedList<ElementType>::back() const {

}

template<typename ElementType>
void LinkedList<ElementType>::pop_front() {

}

template<typename ElementType>
void LinkedList<ElementType>::pop_back() {

}

template<typename ElementType>
int LinkedList<ElementType>::size() const {

 }

template<typename ElementType>
std::vector<ElementType> LinkedList<ElementType>::GetVector() const {

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
void LinkedList<ElementType>::RemoveNth(int n) {

}

template<typename ElementType>
bool LinkedList<ElementType>::operator==(const LinkedList<ElementType> &rhs) const {

}

template<typename ElementType>
bool operator!=(const LinkedList<ElementType>& lhs, const LinkedList<ElementType> &rhs) {

}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator& LinkedList<ElementType>::Iterator::operator++() {

}

template<typename ElementType>
ElementType& LinkedList<ElementType>::Iterator::operator*() {

}

template<typename ElementType>
bool LinkedList<ElementType>::Iterator::operator!=(const LinkedList<ElementType>::Iterator& other) {

}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::begin() {

}

template<typename ElementType>
typename LinkedList<ElementType>::Iterator LinkedList<ElementType>::end() {

}