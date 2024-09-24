#include <ostream>
#include "list.h"

template <typename T> 
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;

	public:
		ListArray(){};
		
		~ListArray(){
			delete[] arr;
		}
		
		T operator[] (int pos){
			if(pos < 0 || pos >= n){
				throw std::out_of_range("Índice fuera de rango");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list);

		void resize(int new_size){
			T* arr1 = new T[new_size];
			for (int i = 0; i < n && i < new_size; ++i) {
            			arr1[i] = arr[i]; // Copy existing elements
        		}
			delete[] arr;
			this->arr = arr1;
			this->max = new_size;
		}


};

