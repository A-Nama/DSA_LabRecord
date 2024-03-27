#include"Q2.h"
#include <climits>

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
void Array<T> :: display_array(){
    if ((UB - LB + 1) == 0) {
        cout << "Array is empty.\n";
        return;
    }
    
    for (int i = LB; i <= UB; i++) { 
        cout << A[i] << " ";
    }
    cout << endl;
}


template <class T>
void Array<T> :: insert_at_end(T key){
	UB=UB+1;
	A[UB]=key;
}

template <class T>
int Array<T> :: partition( int LB,int UB){
	int j=LB-1;
	int pivot=A[UB];
	int i=LB;
	while(i<UB){
		if(A[i]>pivot){
			j=j+1;
			swap(A[i],A[j]);
		}
		i+=1;
	}
	swap(A[j+1],A[UB]);
	return j+1;
}

template <class T>
void Array<T> :: quicksort(int LB,int UB){
	if (LB<=UB){
		int p=partition(LB, UB);
			quicksort(LB,p-1);
			quicksort(p+1,UB);

		}
}

template<class T>
void Array<T> :: bubble_sort(){
	for( int i = LB; i<UB;i++){
		for(int j=LB;j<UB+LB-i-1;j++){
			if (A[j]>A[j+1]){
				swap(j,j+1);
			}
		}
	}
}

template<class T>
void Array<T> :: insertion_sort(){
    int n = UB - LB; 
    for (int i = 1; i <= n; i++) { 
        T key = A[i]; 
        int j = i - 1; 

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key; 
    }
}


template <class T>
void Array<T> :: merge(int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1] = {};
    int R[n2 + 1] = {};
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) { 
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

template <class T>
void Array<T> :: mergesort(int LB, int UB) {
    if (LB < UB) {
        int M = (LB + UB) / 2;
        mergesort(LB, M);
        mergesort(M + 1, UB);
        merge(LB, M, UB);
    }
}

template<class T>
void Array<T> :: swap(int p, int q){
	T temp = A[p];
	A[p] = A[q];
	A[q] = temp;
}

template<class T>
void Array<T> :: selection_sort(){
    int i, j;
    for(i = LB; i <= UB; ++i){ 
        int min = i;
        for(j = i + 1; j <= UB; j++){ 
            if (A[j] < A[min]){
                min = j; 
            }
        }
        if (min != i){
            swap(i, min); 
        }
    }
}

template<class T>
int Array<T> :: linearsearch(T target){
	for (int k = 0; k<UB;++k){
		if(A[k] ==target){
			return k;
		}
	}
	return -1;
}

template<class T>
int Array<T> :: binarysearch(T key) {
    int p = LB;
    int q = UB;
    while (p <= q) {
        int mid = p + (q - p) / 2; 
        if (A[mid] == key) {
            return mid;
        } else if (A[mid] < key) {
            p = mid + 1;
        } else {
            q = mid - 1;
        }
    }
    return -1; 
}
