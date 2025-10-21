#ifndef NODE_H
#define NODE_H
#include <ostream>

template <typename T>
class Node {
    public:
        T data;//elemento amacenado
        Node<T> * next; //puntero al siguiente nodo

        //constructor
        Node(T data, Node<T>*next=nullptr){
            this->data = data;
            this-> next = next;
        }

      //de(T data){
           //his->data = data;
           //his->next = nullptr;

        //
      // Sobrecarga global del operador << (plantilla amiga)
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Node<U>& node);
};

// Implementación del operador <<
// Imprime solo el atributo 'data'
template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    out << node.data;
    return out;
}

#endif // NODE_H
