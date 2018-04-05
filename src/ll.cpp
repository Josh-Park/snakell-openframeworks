#include "ll.h"

namespace snakelinkedlist {
    
    LinkedList::LinkedList() {
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    LinkedList::LinkedList(const std::vector<SnakeBodySegment>& values) {
        head_ = nullptr;
        tail_ = nullptr;
        
        for (auto snake_body_segment : values) {
            push_back(snake_body_segment);
        }
    }
    
    LinkedList::LinkedList(const LinkedList& source) {
        head_ = nullptr;
        tail_ = nullptr;
        
        if (!source.empty()) { // checks if source List is empty
            std::vector<SnakeBodySegment> source_values = source.GetVector();
            
            for (auto snake_body_segment : source_values) {
                push_back(snake_body_segment);
            }
        }
    }
    
    LinkedList::LinkedList(LinkedList&& source) noexcept {
        if (source.empty()) {
            return;
        }
        
        head_ = source.head_;
        tail_ = source.tail_;
        snake_size_ = source.snake_size_;
        source.head_ = nullptr;
        source.tail_ = nullptr;
        source.snake_size_ = 0;
    }
    
    LinkedList::~LinkedList() {
        while (head_) {
            ListNode* temp_node = head_;
            head_ = head_->next_;
            delete temp_node;
            temp_node = nullptr;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    LinkedList& LinkedList::operator=(const LinkedList& source) {
        if (this == &source) { // check for self assignment
            return *this;
        }
        
        head_ = nullptr;
        tail_ = nullptr;
        clear();
        
        if (!source.empty()) { // checks if source List is empty
            std::vector<SnakeBodySegment> source_values = source.GetVector();
            
            for (auto snake_body_segment : source_values) {
                push_back(snake_body_segment);
            }
        }
        
        return *this;
    }
    
    LinkedList& LinkedList::operator=(LinkedList&& source) noexcept {
        if (this == &source) { // check for self-assignment
            return *this;
        }
        
        clear();
        head_ = source.head_;
        tail_ = source.tail_;
        snake_size_ = source.snake_size_;
        source.head_ = nullptr;
        source.tail_ = nullptr;
        source.snake_size_ = 0;
        
        return *this;
    }
    
    void LinkedList::push_front(SnakeBodySegment value) {
        ListNode* new_node = new ListNode(value);
        new_node->next_ = head_;
        head_ = new_node;
        snake_size_ += 1;
        
        if (!tail_) {   // check if this node is first assigned to list, then assign tail_ pointer
            tail_ = new_node;
        }
    }
    
    void LinkedList::push_back(SnakeBodySegment value) {
        ListNode* new_node = new ListNode(value);
        new_node->next_ = nullptr;
        
        if (tail_) { // check if tail_ points to a node
            tail_->next_ = new_node; // point current tail to new node
        }
        tail_ = new_node;
        snake_size_ += 1;
        
        if (!head_) {   // check if this node is first assigned to list, then assign to head_ pointer
            head_ = new_node;
        }
    }
    
    void LinkedList::pop_front() {
        ListNode* temp_node = head_;
        head_ = head_->next_;
        
        delete temp_node;
        temp_node = nullptr; // prevent memoery leaks
        
        snake_size_ -= 1;
    }
    
    void LinkedList::pop_back() {
        ListNode* second_to_last = head_;
        
        while (true) {
            if (!second_to_last->next_->next_) { // if next node points to null
                break;
            }
            second_to_last = second_to_last->next_; // iterate through list
        }
        
        tail_ = second_to_last; // assign tail_ to second_to_last
        delete second_to_last->next_;
        snake_size_ -= 1;

        second_to_last->next_ = nullptr; // prevent memory leaks
        second_to_last = nullptr;
    }
    
    void LinkedList::RemoveNth(int n) {                   // remove the Nth emement from the front
        int num_iterations = 0;
        ListNode* curr_node = head_;
        
        while (num_iterations < n - 2) { // iterates to node before the one to be removed
            curr_node = curr_node->next_;
            num_iterations++;
        }
        
        ListNode* removal_node = curr_node->next_;
        ListNode* past_removal_node = removal_node->next_; // points to the node after the one to be removed
        
        curr_node->next_ = past_removal_node;
        delete removal_node;
        removal_node = nullptr;
        snake_size_ -= 1;
    }
    
    void LinkedList::clear() {
        while (head_) {
            ListNode* temp_node = head_;
            head_ = head_->next_;
            delete temp_node;
            temp_node = nullptr;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }
    
    SnakeBodySegment LinkedList::front() const {
        return head_->data_;
    }
    
    SnakeBodySegment LinkedList::back() const {
        return tail_->data_;
    }
    
    int LinkedList::size() const {
        return snake_size_;
    }
    
    std::vector<SnakeBodySegment> LinkedList::GetVector() const {
        std::vector<SnakeBodySegment> values;
        
        for (ListNode current = *head_; current.next_; current = *current.next_) {
            values.push_back(current.data_);
        }
        values.push_back(tail_->data_);
        
        return values;
    }
    
    bool LinkedList::empty() const {
        return !(head_ || tail_);
    }
    
    std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        std::vector<SnakeBodySegment> values = list.GetVector();
        
        for (int i = 0; i < values.size() - 1; i++) { // iterate through entire vector except for last element
            os << values[i] << ", ";
        }
        os << values[values.size() - 1]; // append the last element value to exclude final comma
        
        return os;
    }
    
    bool LinkedList::operator==(const LinkedList& rhs) const {
        std::vector<SnakeBodySegment> this_values = GetVector();
        std::vector<SnakeBodySegment> rhs_values = rhs.GetVector();
        
        return this_values == rhs_values;
    }
    
    bool operator!=(const LinkedList& lhs, const LinkedList& rhs) {
        std::vector<SnakeBodySegment> lhs_values = lhs.GetVector();
        std::vector<SnakeBodySegment> rhs_values = rhs.GetVector();
        
        return !(lhs_values == rhs_values);
    }

} // namespace snakelinkedlist
