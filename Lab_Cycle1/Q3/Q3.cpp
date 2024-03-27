#include "Q3.h"

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

template <class T>
void Array<T> :: insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template <class T>
void Array<T> :: rotateClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }
    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = A[i + LB];
    }

    for (int i = 0; i < n; ++i) {
        A[i + LB] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T> :: rotateAntiClockwise(int k) {
    int n = UB - LB + 1;
    k = k % n;
    if (k < 0) {
        k += n;
    }

    T* temp = new T[n];

    for (int i = 0; i < n; ++i) {
        temp[i] = A[(i + k) % n + LB];
    }

    for (int i = 0; i < n; ++i) {
        A[i + LB] = temp[i];
    }

    delete[] temp;
}

template <class T>
void Array<T> :: printDistinctElements() {
    int n = UB - LB + 1;
    cout << "Distinct Elements: ";
    for (int i = LB; i <= UB; ++i) {
        bool isDistinct = true;
        for (int j = LB; j < i; ++j) {
            if (A[i] == A[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

template <class T>
void Array<T> :: generateFrequencyTable() {
    int n = UB - LB + 1;
    cout << "Frequency Table:\n";
    for (int i = LB; i <= UB; ++i) {
        int frequency = 1;
        for (int j = i + 1; j <= UB; ++j) {
            if (A[i] == A[j]) {
                ++frequency;
                A[j] = A[UB--]; 
            }
        }
        cout << A[i] << ": " << frequency << endl;
    }
}

template<class T>
void Array<T> :: display_array(){
        if ((UB -LB + 1) == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Elements in the array: ";
        for (int i = LB; i <= UB; i++) {
            cout << A[i] << " ";
        }
    cout << endl;
}
