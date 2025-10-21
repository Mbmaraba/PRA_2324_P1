#ifndef LISTLINKED_H
#define LISTLINKED_H


#include <ostream>
#include <stdexcept>  // para std::out_of_range
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;  // puntero al primer nodo
    int n;           // número de elementos en la lista

public:
    ListLinked(){
        first = nullptr;
        n=0;
    }


    ~ListLinked(){
        Node<T>* current=first;
        while (current != nullptr){
            Node<T>* aux = current->next;
            delete current;
            current =aux;
        }
    }

    int size() const override{
        return n;
    }

    void push_front(const T& data){
        first = new Node<T>(data, first);
        n++;

    }

     T operator[](int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current->data;
    }


      template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<U>& list);
};


    template <typename T>
std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
    Node<T>* current = list.first;
    out << "[";
    while (current != nullptr) {
        out << current->data;
        if (current->next != nullptr)
            out << ", ";
        current = current->next;
    }
    out << "]";
    return out;
}

#endif
