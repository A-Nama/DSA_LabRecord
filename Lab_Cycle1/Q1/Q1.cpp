#include "Q1.h"

template <class T>
Array<T> :: Array(){
	LB=1;
	UB=0;
	mid = 0;
}

template <class T>
Array<T> :: Array(int LB,int UB,T x[]){
 int i = LB;
 while(i<=UB){
	A[i]=x[i];
	i++;
 }
}

template<class T>
void Array<T> :: insert_at_begin(T key){
	UB = UB+1;
	int k = UB - 1;
	while (k>=LB){
		A[k+1] = A[k];
		k = k-1;
	}
	A[LB] = key;
}

template <class T>
void Array<T> :: insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template <class T>
void Array<T> :: insert_at_pos(T key, int pos){
	UB = UB + 1;
	int k = UB - 1;
	while(k>=pos){
		A[k+1] = A[k];
		k = k-1;
	}
	A[pos]=key;
}

template<class T>
void Array<T> :: delete_at_begin(){
	if(UB>=LB){
		for(int k = LB + 1; k<= UB; ++k){
			A[k-1] = A[k];
		}
		UB = UB - 1;
	}
	else{
		cout<<"Array is empty."<<endl;
	}
}

template<class T>
void Array<T> :: delete_at_end(){
	if(UB>=LB){
		UB = UB - 1;
	}
	else{
		cout<<"Array is empty."<<endl;
	}
}

template<class T>
void Array<T> :: delete_at_pos(int pos){
	if(pos<LB || pos>UB){
		cout<<"Invalid position"<<endl;
	}

	for(int k = pos;k<UB;++k){
		A[k] = A[k+1];
	}
	UB = UB - 1;
}

template<class T>
int Array<T> :: findIndex(T element){
    for (int i = 0; i < (UB - LB + 1); i++) {
            if (A[i] == element) {
                return i;
            }
        }
        return -1;
    }

template<class T>
void Array<T> :: display_array(){
        if ((UB - LB + 1) == 0) {
            cout << "Array is empty.\n";
            return;
            }
       cout << "Elements in the array: ";
       for (int i = LB; i <= (UB - LB + 1); i++) {
          cout << A[i] << " ";
        }
       cout << endl;

}