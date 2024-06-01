#ifndef SHAPESSTORAGE_H
#define SHAPESSTORAGE_H

#include <myshape.h>
struct Node {
    MyShape* shape;
    Node* next;

    Node(MyShape* shape) : shape(shape), next(nullptr) {}
    ~Node() {
        delete shape; // honorable mention
    }
};

class ShapesStorage //singleton class to access shapes
{
    Node* head; // Головной узел списка
    Node* tail; // Хвостовой узел списка

public:
    ShapesStorage();
    ~ShapesStorage();

    void addShape(MyShape* shape);
    void removeShape(MyShape* shape);
    bool contains(MyShape* shape);
    int length();
    class Iterator{
    public:
        Iterator(Node* node);
        Node* current;
        MyShape* operator *() const;
        Iterator operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator !=(const Iterator& other) const;
    };
    Iterator begin();
    Iterator end();
};


#endif // SHAPESSTORAGE_H
