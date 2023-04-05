#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std::chrono;
using namespace std;

#define Max 1000  // maximum elements in stack_arr

class stack_arr {
    int top;

    public:
        int a[Max];

        stack_arr(){top = -1;}
        bool push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
        int stack_arrTop();
        void display();


};

bool stack_arr::push(int x){
    if(!isFull()){
        top++;
        a[top]=x;
        cout << x << " pushed into stack_arr " << endl;
        return true;
    }
    else{
        cout << "stack_arr overflow" << endl;
        return false;
    }
}

int stack_arr::pop(){
    if(!isEmpty()){
        top--;
        return a[top+1];
    }
    else{
        cout << "stack_arr underfow" << endl;
        return 0;
    }
}

bool stack_arr::isEmpty(){
    if (top < 0) return true;
    else return false;
}

bool stack_arr::isFull(){
    if (top == Max - 1) return true;
    else return false;
}

int stack_arr::stack_arrTop(){
    return a[top];
}

void stack_arr::display(){
    int temp = top;
    while(!(temp<0)){
        cout << a[temp] << " ";
        temp--;
    }
    cout << endl;
}


//Implementing stack using singly linked list

class StackNode{
    public:
        int data;
        StackNode* next;
};

int isEmpty(StackNode* root){
    return !root;
}

StackNode* newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode -> data = data;
    stackNode -> next = NULL;
    return stackNode;

}

void push(StackNode** root, int x){
    StackNode* stackNode = newNode(x);
    stackNode -> next = *root;
    *root = stackNode;
}

int pop(StackNode** root){
    int temp = (*root)-> data;
    *root = (*root)-> next;
    return temp;
}

int stackTop(StackNode* root){
    return root->data;
}

void display_ll_stack(StackNode** root){
    StackNode* temp = *root;
    while((temp->next)){
        cout << temp->data << " " ;
        temp = temp->next;
    }
    cout << endl;
}

void driver_code_stack_arr(stack_arr stack){
    for(int i=0; i<10; i++){
        stack.push(rand() % 100);
    }

    stack.display();

    for(int i=0; i<5; i++){
        stack.pop();
    }

    stack.display();

     for(int i=0; i<4; i++){
        stack.push(rand() % 100);
    }
    
    stack.display();
}

void driver_code_stack_ll(StackNode* root){
    for(int i=0; i<10; i++){
        push(&root, (rand() % 100));
    }

    display_ll_stack(&root);

    for(int i=0; i<5; i++){
        pop(&root);
    }

    display_ll_stack(&root);

     for(int i=0; i<4; i++){
        push(&root, (rand() % 100));
    }
    
    display_ll_stack(&root);
}
 
int main(){

    class stack_arr s;
    auto start_time_it = high_resolution_clock::now();
    driver_code_stack_arr(s);
    auto end_time_it = high_resolution_clock::now();
    auto duration_it = duration_cast<nanoseconds>(end_time_it - start_time_it);
    cout << "Time taken by array approach: " << duration_it.count() << " nanoseconds" << endl;
    cout << "________________________________________________________________________________"<< endl;
    
    
    StackNode* root = NULL;
    auto start_time_it2 = high_resolution_clock::now();
    driver_code_stack_ll(root);
    auto end_time_it2 = high_resolution_clock::now();
    auto duration_it2 = duration_cast<nanoseconds>(end_time_it2 - start_time_it2);
    cout << "Time taken by array approach: " << duration_it2.count() << " nanoseconds" << endl;
    

    return 0;
}