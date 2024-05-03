#include "Q11.h"
#include <stack>
template<typename T>
void MergeSort<T>::mergeSort(T* arr, int size) {
    if (size <= 1) return;
    std::stack<std::pair<int, int>> stack;
    stack.push({0, size - 1});

    while (!stack.empty()) {
        int start = stack.top().first;
        int end = stack.top().second;
        stack.pop();
        if (start < end) {
            int mid = start + (end - start) / 2;
            stack.push({start, mid});
            stack.push({mid + 1, end});
        }

        merge(arr, start, (start + end) / 2, end);
    }
}

template<typename T>
void MergeSort<T>::merge(T* arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    T* leftArr = new T[n1];
    T* rightArr = new T[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}
