#include<iostream>

using namespace std;
template <class T>
    class Array{
	int LB,UB,mid;
	T A[100];
	
	public:
  	Array();
  	Array(int,int,T[]);
  	void insert_at_end(T);
	void insert_at_begin(T);
	void insert_at_pos(T,int);
    void delete_at_begin();
	void delete_at_end();
	void delete_at_pos(int);
    int  findIndex(T);
    void display_array();

    };
