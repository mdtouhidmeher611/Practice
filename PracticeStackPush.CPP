#include<bits/stdc++.h>
using namespace std;
#define max 10

int stack_arr[max];
int top  = -1;

void push(){
	if (top == max-1 ){
		cout <<"overflow"<<endl;
		return;
	}
	int item;
	cout<<"enter item to be pushed : ";
	cin >> item;
	top++;
	stack_arr[top]= item;
	cout<< "pushed successfully";
}
void pop(){
	if(top==-1){
		cout<< "underflow"<<endl;
		return;
	}
	int item = stack_arr[top];
	top--;
	cout << "successfully poped item :"<< item <<endl;
}

void display(){
	if(top-1){
		cout <<"stack is emty"<<endl;
		return;
	}
	cout << "stack elements:  ";
	for (int i=0 ; i<=top; i++){
		cout<< stack_arr[i];
	}
	cout<<endl;
}

void peek(){
    if(top== -1){
        cout<<"Stack Underflow!\n";
        return;
    }
    cout<<"Top element is: "<<stack_arr[top]<<"\n";
}
int main(){
	int choice;

	while(1){
		cout<<"\n 1.push\n2 .pop \n3. peek \n4.display\n5.xit"<<endl;
		cin >>choice;
		switch(choice){
		case 1: push();break;
		case 2: pop();break;
		case 3: peek();break;
		case 4: display();break;
		case 5: return 0;
		default : cout<<"invalid choice!!!!!!!!\n";
		}
	}
}