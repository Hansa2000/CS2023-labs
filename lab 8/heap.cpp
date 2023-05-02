#include <iostream>
using namespace std;

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// function to heapify the tree
void swap(int arr[],int a,int b){
   int temp = arr[a];
   arr[a] = arr[b];
   arr[b] = temp;
}
void heapify(int arr[], int n, int root)
{
   int l= 2*root+1;
   int r= 2*root+2;

   int largest = root;

   if(l < n && arr[largest] < arr[l]){largest = l;}
   if(r < n && arr[largest] < arr[r]){largest = r;}
   if(largest!=root){
      swap(arr,root,largest);
      heapify(arr, n,largest);
   }  
}


// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   
   for(int i = n-1; i >= 0; i--){
      heapify(arr,n,i);
   }
  
   int sortarr[n];
   int tempn = n;
   // extracting elements from heap one by one
   for(int i=0; i<n;i++){
      heapify(arr,tempn,0);
      sortarr[i]=arr[0];
      arr[0]= arr[tempn-1];
      tempn--;
   }

   for(int i=0; i<n; i++){arr[i] = sortarr[i];}
   
}
  

  
// main program
int main()
{
   int heap_arr[5];
   cout << "Enter 5 integers : " << endl;
   for(int i=0;i<5;i++){
      cin >> heap_arr[i]; 
   }
   cout<<"You have entered five integers."<<endl;
   cout<<"\n";
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
   cout<<"\n";
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}