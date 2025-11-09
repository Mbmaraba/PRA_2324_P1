#include <iostream>
#include "ListLinked.h"

int main() {
    std::cout << std::boolalpha; // mostrar true/false en lugar de 0/1

    ListLinked<int> lista;

    std::cout << lista << std::endl;
    std::cout << "size(): " << lista.size() << std::endl;
    std::cout << "empty(): " << lista.empty() << std::endl;
    std::cout << std::endl;

    lista.insert(0, 0);
    lista.insert(1, 10);
    lista.insert(0, -5);
    lista.insert(2, 5);
    std::cout << lista << std::endl;
    std::cout << "size(): " << lista.size() << std::endl;
    std::cout << "empty(): " << lista.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "lista.get(0) => " << lista.get(0) << "; lista[0] => " << lista[0] << std::endl;
    std::cout << "lista.get(3) => " << lista.get(3) << "; lista[3] => " << lista[3] << std::endl;
    std::cout << std::endl;

    int r;
    r = lista.remove(3);
    std::cout << "lista.remove(3) => " << r << std::endl;
    r = lista.remove(1);
    std::cout << "lista.remove(1) => " << r << std::endl;
    r = lista.remove(0);
    std::cout << "lista.remove(0) => " << r << std::endl;
    std::cout << std::endl;

    std::cout << lista << std::endl;
    std::cout << "size(): " << lista.size() << std::endl;
    std::cout << "empty(): " << lista.empty() << std::endl;
    std::cout << std::endl;

    lista.append(14);
    lista.prepend(33);
    std::cout << lista << std::endl;
    std::cout << "size(): " << lista.size() << std::endl;
    std::cout << "empty(): " << lista.empty() << std::endl;
    std::cout << std::endl;

    std::cout << "lista.search(14) => " << lista.search(14) << std::endl;
    std::cout << "lista.search(55) => " << lista.search(55) << std::endl;
    std::cout << std::endl;

    try {
        lista.insert(-1, -99);
    } catch (std::out_of_range &e) {
        std::cout << "lista.insert(-1, -99) => std::out_of_range: " << e.what() << std::endl;
    }

    try {
        lista.insert(4, -99);
    } catch (std::out_of_range &e) {
        std::cout << "lista.insert(4, -99) => std::out_of_range: " << e.what() << std::endl;
    }

    try {
        lista.get(-1);
    } catch (std::out_of_range &e) {
        std::cout << "lista.get(-1) => std::out_of_range: " << e.what() << std::endl;
    }

    try {
        lista.get(3);
    } catch (std::out_of_range &e) {
        std::cout << "lista.get(3) => std::out_of_range: " << e.what() << std::endl;
    }

    try {
        lista.remove(-1);
    } catch (std::out_of_range &e) {
        std::cout << "lista.remove(-1) => std::out_of_range: " << e.what() << std::endl;
    }

    try {
        lista.remove(3);
    } catch (std::out_of_range &e) {
        std::cout << "lista.remove(3) => std::out_of_range: " << e.what() << std::endl;
    }

    return 0;
}
