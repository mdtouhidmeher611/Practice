#include<bits/stdc++.h>
using namespace std;

#define maximum 100

char stackarr[maximum];
int top=-1 ;

void push(char x){
	top=top+1;
	stackarr[top] = x ;
}

void pop(){
	top=top-1;
}

char peek(){
	return stackarr[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void display(){
	for(int i=0;i<=top;i++)
		cout<<stackarr[i];
}

int main(){

	string infix,postfix="";
	cout<<"Enter infix: ";
	getline(cin,infix);

	cout<<"\n step \t symbol \t stack \t postfix\n";

	int count=1;

	for (char c: infix){
		if(c==' ') continue;

		else if(isalnum(c)){
			postfix=postfix+c;
		}
		else if(c=='('){
			push(c);
		}
		else if(c==')'){
			while(peek()!='('){
				postfix= postfix + peek() ; pop();

			}
			pop();
		}
		else{
			while( /*top !=-1 &&*/ precedence(c)<=precedence(peek())){
				postfix= postfix + peek();pop();
			}
			push(c);
		}
		cout<<"\n "<<count<<"\t"<< c <<"\t\t";display();cout<<"\t"<<postfix;
		count=count+1;
	}
	if(top!=-1){
		while(top!=-1){
			postfix=postfix+peek();pop();
		}
		cout<<"\n "<<count<<"\t\t\t";display();cout<<"\t"<<postfix;
	}
	return 0;
}