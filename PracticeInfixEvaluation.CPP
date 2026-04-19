#include<bits/stdc++.h>
using namespace std;

int apply(int a,int b , char c){
	if(c== '+') return a+b ;
	if(c== '-') return a-b ;
	if(c== '*') return a*b ;
	if(c== '/') return a/b ;
	if(c== '^') return pow(a,b);
	return 0;
}

int precidence(char c){
	if(c== '+') return 1;
	if(c== '-') return 1 ;
	if(c== '*') return 2 ;
	if(c== '/') return 2 ;
	if(c== '^') return 3;
	return 0;
}

int main(){
	string infix ;
	cout <<" enter the infix notation : " ;
	getline(cin,infix);

	stack<int> operand ;
	stack<char> oprs;

	for(int i=0;i<infix.length();i++){
		char c = infix[i];

		if(c==' ') continue;
		if(isdigit(c)){
			int value = 0;
			while (i<infix.length() && isdigit(infix[i])){
				value = value*10 +(infix[i]-'0');
				i++;
			}
			i--;
			operand.push(value);

		}

		else if(isalpha(c)){
			int value;
			cout <<"Enter the value of  " << c << " : ";
			cin >> value;
			operand.push(value);
		}

		else if(c=='('){
			oprs.push(c);
		}
		else if(c==')'){
			while(oprs.top()!='(' && !oprs.empty()){
				int b= operand.top();operand.pop();
				int a= operand.top();operand.pop();
				char op = oprs.top();oprs.pop();
				operand.push(apply(a,b,op));
			}
			if(!oprs.empty()) oprs.pop();
		}
		else{
			while(!oprs.empty() && precidence(oprs.top()) >= precidence(c)){
				int b= operand.top();operand.pop();
				int a= operand.top();operand.pop();
				char op = oprs.top();oprs.pop();
				operand.push(apply(a,b,op));
			}
			oprs.push(c);
		}

	}

	while(!oprs.empty() ){
		int b= operand.top();operand.pop();
		int a= operand.top();operand.pop();
		char op = oprs.top();oprs.pop();
		operand.push(apply(a,b,op));
	}
	cout << "final result : " << operand.top()<<endl;

	return 0;
}