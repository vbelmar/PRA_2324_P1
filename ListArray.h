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
		ListArray(){
			arr = new T[MINSIZE];
			n=0;
			max = MINSIZE;
		}
		
		~ListArray(){
			delete[] arr;
		}
	

		void insert(int pos, T e) override {
			if(pos < 0 || pos > n){
				throw std::out_of_range("Fuera de rango");
			}

			if (n >= max){
				resize(max*2);
			}		

			for(int i = n; i > pos; i--){
				arr[i] = arr[i-1];
			}

			arr[pos] = e;
			
			n++;
		}

		
		void append (T e) override {
			insert(n, e);
		}

		void prepend (T e) override {
			insert(0, e);
		}

		T remove(int pos) override {
			if (pos < 0 || pos >= n) {
     		   throw std::out_of_range("Índice fuera de rango");
    		}
			T x = arr[pos];
			for(int i= pos; i < n-1; i++){
				arr[i] = arr[pos + 1];
			}
			n--;
			return x;
		}

		T get(int pos) override {
			if(pos < 0 || pos >= n ){
				throw std::out_of_range("Fuera de rango");
			}
			return arr[pos];
		}

		int search(T e) override {
			for(int i = 0; i < n; i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

		bool empty() override {
			return n == 0;
		}

		int size() override {
			return n;
		}




		T& operator[] (int pos){
			if(pos < 0 || pos >= n){
				throw std::out_of_range("Índice fuera de rango");
			}
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
        		out << "[";
        		for (int i = 0; i < list.n; i++) {
            			out << list.arr[i];
            			if (i < list.n - 1) {
                			out << ", ";
            			}
        		}
        		out << "]";
        		return out;
    		};
	
		void resize(int new_size){
			T* arr1 = new T[new_size];
			for (int i = 0; i < n; i++) {
            			arr1[i] = arr[i]; 
        		}
			delete[] arr;
			arr = arr1;
			max = new_size;
		}

};
