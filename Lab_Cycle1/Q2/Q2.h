#include<iostream>
#include<ostream>

using namespace std;
template <class T>
  class Array {
	int LB, UB, mid;
	T A[100];
	public:
  	Array();
  	Array(int,int,T[]);
    void display_array();
    void insert_at_end(T);
    void merge(int,int,int);
    void mergesort(int, int);
    int partition(int, int);
    void quicksort(int,int);
    void bubble_sort();
	  void insertion_sort();
    void selection_sort();
    int linearsearch(T);
	  int binarysearch(T);
    void swap(int,int);

    };