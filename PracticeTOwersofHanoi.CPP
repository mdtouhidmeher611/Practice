#include<bits/stdc++.h>
using namespace std;

void toh(int n,char beg,char aux,char end){
if(n==1){
	cout<< "disk " << n <<" : " << beg << "-->"<< end <<endl;
	return;
}
toh(n-1,beg,end,aux);
cout<< "disk " << n <<" : "<< beg <<"-->"<<end<<endl;
toh(n-1,aux,beg,end);

}

int main(){
	int n;
	cout <<"Enter number of disks: ";
	cin >>n;

	toh(n,'X','Y','Z');
}