// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

// non-recursive quick sort
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
  

int partition_non_rec(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
  

void quickSort_non_rec(int A[], int l, int h)
{
    if (l < h) {
        /* Partitioning index */
        int p =  partition_non_rec(A, l, h);
        quickSort_non_rec(A, l, p - 1);
        quickSort_non_rec(A, p + 1, h);
    }
}
  


int main()
{
    int data[] = {500,1000,2000,5000,10000,15000,20000};
    for(int b=0 ; b<7 ; b++){
     int length = data[b];
     int arr[length];
     for (int j = 0; j < length; j++) {
            arr[j] = rand() % 100;
        }
        
    auto arr_size = sizeof(arr) / sizeof(arr[0]);  
    
    int arr_rec[length];
    int arr_it[length];
    // Copy the source array to the destination array
        for (int i = 0; i < length; i++) {
            arr_rec[i] = arr[i];
        }
        for (int i = 0; i < length; i++) {
            arr_it[i] = arr[i];
        }
        
    
    //cout << "Given array is \n";
    auto start_time_rec = high_resolution_clock::now();
    quickSort(arr_rec,0, length-1);
    auto end_time_rec = high_resolution_clock::now();
    auto duration_rec = duration_cast<nanoseconds>(end_time_rec - start_time_rec);
    cout<<"Total elements in array: "<<length<<endl;
    cout << "Time taken by recursive approach: " << duration_rec.count() << " nanoseconds" << endl;
    
    //printArray(arr_rec, arr_size);
    
    auto start_time_it = high_resolution_clock::now();
    quickSort_non_rec(arr_it, 0,length-1);
    auto end_time_it = high_resolution_clock::now();
    auto duration_it = duration_cast<nanoseconds>(end_time_it - start_time_it);
    
    cout << "Time taken by iterative approach: " << duration_it.count() << " nanoseconds" << endl;
    }
  
	
	return 0;
}
