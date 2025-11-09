#include <ostream>
#include "List.h"


using namespace std;

template <typename T>
class ListArray : public List<T> {

    private:
    	T* arr;
	int max;
	int n;
	static const int MINSIZE[];

    public:
        void insert(int pos, T e) override{

		if(pos<0 || pos> n){
			throw out_of_range("Posicion no posible\n");
		}else{

		//array temporal
		T* temp = new T[n + 1];//n +1 es más grande q el orginal


		//Se copian los elemento de antes de pos, sin pos incluido
		for(int i = 0; i< pos; i++){

			temp[i] = arr[i];

		}

		temp[pos]= e;

		//Copiamos los elementos que estaban después de la posición pos, pero desplazándolos una posición a la derecha (i+1)
		for (int i = pos; i < n; i++){
			temp[i + 1]= arr[i];
		}


		delete[] arr;
		arr = temp;// arr es el nuevo arreglo q inlcluye lo anteriormentre insertado
		n++;
		}
	}

        void append(T e) override{
		//T[max]= e;
			T* temp = new T[n + 1];//n +1 es más grande q el orginal


			//Se copian los element, sin n incluido
			for(int i = 0; i< n; i++){//ojo menor n NO IGUAL

				temp[i] = arr[i];
			}

			temp[n]= e;

			delete [] arr;
			arr = temp;
			n++;
	}

        void prepend(T e) override{
		//T[0] = e;
			T* temp = new T[n + 1];//n +1 es más grande q el orginal

			for(int i = 0; i< n; i++){//ojo menor n NO IGUAL

				temp[i+1] = arr[i];
			}

			temp[0]=e;

			delete [] arr;
			arr = temp;
			n++;

	}

	T remove(int pos) override{
			// Validar posición
		if (pos < 0 || pos >= n) {
        throw std::out_of_range("Posición fuera de rango");
		}

    // Guardar el elemento a eliminar
		T removed = arr[pos];

    // Crear un nuevo arreglo de tamaño n-1
		T* temp = new T[n - 1];

    // Copiar elementos antes de la posición pos
		for (int i = 0; i < pos; i++) {
        temp[i] = arr[i];
    }

    // Copiar elementos después de la posición pos
		for (int i = pos + 1; i < n; i++) {
        temp[i - 1] = arr[i];//Los desplazamos una posición a la izquierda (i-1) para llenar el hueco dejado por el elemento eliminado.
    }

    // Liberar el arreglo antiguo y reasignar
		delete[] arr;
		arr = temp;

    // Reducir el tamaño
		n--;

    // Devolver el elemento eliminado
		return removed;
}



	T get(int pos) const override{
		if(pos<0 || pos>= n){
                        throw out_of_range("Posicion no posible\n");
                }else{
			return arr[pos];

		}


	}

	int search(T e) override{
		 for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            return i; // Encontramos la primera ocurrencia
        }
    }
    return -1; // No se encontró
	}


        bool empty() const override{
		 return n == 0;
	}

        int size() const override{
		return n;
	}


	 ListArray() {
        n = 0;                 // Lista inicialmente vacía
        max = MINSIZE[0];      // Capacidad mínima
        arr = new T[max];      // Reservar memoria dinámica
    }

    ~ListArray(){
		delete [] arr;
	}

	//En lugar de tener que llamar a lista.get(0), el operador [] se comporta como un array normal.
	T operator[](int pos)const{
		 if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }



    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		//Permite que esta función global pueda acceder a los atributos privados
		 out << "List => [";
    if (list.n > 0) {
        out << "\n";
        for (int i = 0; i < list.n; i++) {
            out << "  " << list.arr[i];
            if (i != list.n - 1) out << "\n";
        }
        out << "\n";
    }
    out << "]";
    return out;
	}


	void resize(int new_size) {
        // Nunca reducimos la capacidad por debajo del número de elementos actuales
        if (new_size < n) {
            new_size = n;
        }

        // Crear un nuevo arreglo de tamaño new_size
        T* temp = new T[new_size];

        // Copiar todos los elementos actuales al nuevo arreglo
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }

        // Liberar el arreglo antiguo y asignar el nuevo
        delete[] arr;
        arr = temp;

        // Actualizar la capacidad máxima
        max = new_size;
    }

};


	template <typename T>
const int ListArray<T>::MINSIZE[] = {10};
