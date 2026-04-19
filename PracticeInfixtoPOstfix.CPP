#include<bits/stdc++.h>
using namespace std;

int precedence(char op){

	if(op=='+' || op == '-') return 1;
	if(op=='*' || op == '/') return 2;
	if(op=='+' || op == '-') return 1;
	return 0;
}


int main(){
	stack<char> oprs;
	string infix, postfix =""; 
	getline(cin,infix);

	cout<< "\n step\t \t symbol\t stack \t postfix\n";

	cout<<"__________________________________________\n";
	int step=1;
	for(char c : infix){
		if(c == ' ') continue;
		cout << step++ <<" \t\t "<< c << "\t ";

		if(isalnum(c)){
			postfix+=c;
		}

     	else if (c == '(') {
            oprs.push(c);
        }
        else if (c == ')') {
            while (!oprs.empty() && oprs.top() != '(') {
                postfix += oprs.top();
                oprs.pop();
            }
            if (!oprs.empty()) oprs.pop(); // remove '('
        }

        else {
        	while(!oprs.empty() && (precedence(oprs.top())>= precedence(c))){
        		postfix+= oprs.top();
        		oprs.pop();
        	}
        	oprs.push(c);
        }

        stack<char>temp = oprs;
        string stackcontent = "";
        while(!temp.empty()){
        	stackcontent = temp.top() + stackcontent;
        	temp.pop();
        }

       cout << stackcontent <<"\t" << postfix << endl ;

	}

	while(!oprs.empty()){
		postfix+=oprs.top();oprs.pop();
	}
	cout<< step <<"\t \t\t\t"<< postfix<<"\n";

	cout<< "\nfinal postfix  :  "<<postfix<<endl;

	return 0;
}