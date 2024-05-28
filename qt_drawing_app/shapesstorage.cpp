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

void ShapesStorage::removeShape(MyShape* shape){
    for(ShapesStorage::Iterator it = this->begin(); it != this->end(); it++){
        auto prev = it.current;
        if(*it == shape){
            ++it;
            prev->next = it.current;
        }
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
