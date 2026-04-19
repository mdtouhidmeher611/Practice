#include<bits/stdc++.h>
using namespace std;

#define maximum 100

int stackarr[maximum];
int top=-1 ;

void push(int x){
	top=top+1;
	stackarr[top] = x ;
}

void pop(){
	top=top-1;
}

int peek(){
	return stackarr[top];
}

int operation(int a , int b, char c){
	if(c== '+' ) return a+b ;
	if(c== '-' ) return a-b;
	if(c== '*' ) return a*b;
	if(c== '/' ) return a/b;
	if(c== '^') return (int)pow(a,b); 
	return 0;
}


int precidence(char c){
	if(c== '+' || c== '-') return 1;
	if(c== '*' || c== '/') return 2;
	if(c== '^') return 3;
	return 0;
}


int main(){

	string postfix;
	getline(cin,postfix);

	for(int i = 0 ; i< postfix.length(); i++){
		if((postfix[i] >= 'a' && postfix[i]<= 'z' )||(postfix[i] >= 'A' && postfix[i]<= 'Z' )){
			cout<< "Enter the value of " << postfix[i] << " : ";
			cin >> postfix[i];
		}
	}

	for (char c : postfix){
		if ( c >='0' && c<= '9'){
			push(c-'0');
		}

		if( c == '+' || c == '-' ||c == '*' ||c == '/' || c== '^'){
			int b = peek();pop();
			int a = peek();pop();
			push(operation(a,b,c));
		}
	}

	int n = peek();pop();

	cout << "\nresult : "<< n << endl ;


	return 0;
	
}