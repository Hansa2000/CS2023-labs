#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << " array length is " << n << endl;
    int arr[n];
    int pointer = -1;

    while(pointer < n-1){
        if(pointer==-1){
            pointer++;
            cin >> arr[pointer];
        }
        else{
            pointer++;
            int current;
            cin >> current;
            int temp_pointer = pointer-1;
            while(temp_pointer>=0){
                if(arr[temp_pointer]>= current){
                    arr[temp_pointer+1]=arr[temp_pointer];
                    temp_pointer = temp_pointer-1;
                }
                else{
                    break;
                }
            }
            arr[temp_pointer+1]=current;
        }

        cout << "sorted array : ";
        for(int i=0;i<=pointer;i++){
            cout << arr[i];
            if(i==pointer) break;
            cout << ",";
        }
        
        double median;
        if(pointer%2==0) median = (double) arr[pointer/2]/(double) 1;
        else median = (double)(arr[pointer/2]+arr[pointer/2 + 1])/(double)2;

        cout << "  ||  The median is : " << median ;
        cout << endl;

    }
}