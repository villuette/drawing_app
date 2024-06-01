#include "shapesstorage.h"

ShapesStorage::ShapesStorage()
{
    head = tail = nullptr;
}
ShapesStorage::~ShapesStorage(){
    Node* curr = head;
    while(curr != nullptr){
        auto next = curr->next;
        delete curr;
        curr = next;
    }
}
void ShapesStorage::addShape(MyShape* shape){
    Node* newNode = new Node(shape);
    if(!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}
int ShapesStorage::length() {
    int counter = 0;
    for (Iterator it = begin(); it != end(); ++it) {
        counter++;
    }
    return counter;
}

bool ShapesStorage::contains(MyShape *shape){
    bool result = false;
    for (Iterator it = begin(); it != end(); ++it) {
        if(*it == shape){
            result = true;
        }
    }
    return result;
}

void ShapesStorage::removeShape(MyShape* shape) {
        if (head == nullptr) {
            return; // The list is empty, nothing to remove
        }
        // If the shape to remove is the head of the list
        if (head->shape == shape) {
            Node* temp = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr; // The list is now empty
            }
            return;
        }
        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->shape == shape) {
                // Adjust the pointers to bypass the node to remove
                prev->next = current->next;
                if (current->next == nullptr) {
                    tail = prev; // Update the tail if we removed the last node
                }
                return;
            }
            prev = current;
            current = current->next;
        }
    }
ShapesStorage::Iterator::Iterator(Node *node)
    :current(node)
{}

ShapesStorage::Iterator ShapesStorage::begin(){
    return Iterator(head);

}
ShapesStorage::Iterator ShapesStorage::end(){
    return Iterator(nullptr);
}
MyShape* ShapesStorage::Iterator::operator *() const {
    return current->shape;
}
ShapesStorage::Iterator ShapesStorage::Iterator::operator++(){
    if (current) {
        current = current->next;
    }
    return *this;
}
ShapesStorage::Iterator ShapesStorage::Iterator::operator++(int){
    Iterator temp = *this;
    ++(*this);
    return temp;
}
bool ShapesStorage::Iterator::operator==(const ShapesStorage::Iterator& other) const{
    return current == other.current;
}
bool ShapesStorage::Iterator::operator !=(const ShapesStorage::Iterator& other) const{
    return !(*this == other);

}
