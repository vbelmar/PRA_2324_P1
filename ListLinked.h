#include <ostream>
#include "list.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
 
        Node<T>* first;
	int n;

    public:

        ListLinked() : first(nullptr), n(0) {}
		
	~ListLinked(){
		while (first != nullptr){
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
	}

	T operator[](int pos){
		if(pos < 0 || pos >= n){
			throw std::out_of_range("Indice fuera de rango");
		}

		Node<T>* current = first; // Comenzar desde el primer nodo
        	for (int i = 0; i < pos; ++i) {
            		current = current->next; // Moverse al siguiente nodo
        	}	

        	return current->data;
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		Node<T>* current = list.first; // Comenzar desde el primer nodo
        	out << "["; // Comenzar con un corchete

        	while (current != nullptr) {
            		out << current->data; // Imprimir el dato del nodo

            		current = current->next; // Moverse al siguiente nodo
            		if (current != nullptr) {
                		out << ", "; // Agregar una coma si no es el último nodo
            		}
        	}
        
        	out << "]"; // Cerrar el corchete
        	return out;
	}
	
};

