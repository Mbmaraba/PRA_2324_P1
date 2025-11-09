#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;
    int n;

public:
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n)
            throw std::out_of_range("Posición fuera de rango\n");

        // Caso: insertar al principio
        if (pos == 0) {
            first = new Node<T>(e, first);
        } else {
            // Avanza hasta el nodo anterior a la posición
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            // Inserta el nuevo nodo
            prev->next = new Node<T>(e, prev->next);
        }
        n++;
    }

    void append(T e) override {
        insert(n, e);
    }

    void prepend(T e) override {
        insert(0, e);
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");

        Node<T>* eliminado;
        T valor;

        // Caso: eliminar el primero
        if (pos == 0) {
            eliminado = first;
            first = first->next;
        } else {
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; i++)
                prev = prev->next;

            eliminado = prev->next;
            prev->next = eliminado->next;
        }

        valor = eliminado->data;
        delete eliminado;
        n--;

        return valor;
    }

    // ✅ get debe ser const
    T get(int pos) const override {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango\n");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++)
            current = current->next;

        return current->data;
    }

    // ✅ search sin const
    int search(T e) override {
        Node<T>* current = first;
        for (int i = 0; i < n; i++) {
            if (current->data == e)
                return i;
            current = current->next;
        }
        return -1;
    }

    // ✅ empty const
    bool empty() const override {
        return n == 0;
    }

    // ✅ size const
    int size() const override {
        return n;
    }

    ListLinked() {
        first = nullptr;
        n = 0;
    }

    ~ListLinked() {
        Node<T>* aux = first;
        while (aux != nullptr) {
            Node<T>* temp = aux->next;
            delete aux;
            aux = temp;
        }
        first = nullptr;
        n = 0;
    }

    T operator[](int pos) const {
        if (pos < 0 || pos >= n)
            throw std::out_of_range("Posición fuera de rango");

        Node<T>* current = first;
        for (int i = 0; i < pos; i++)
            current = current->next;

        return current->data;
    }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        out << "List=> [";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr)
                out << ", ";
            current = current->next;
        }
        out << "]";
        return out;
    }
};
