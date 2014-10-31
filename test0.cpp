#include <bits/stdc++.h>
#include "afd.hpp"
#include "afn.hpp"
using namespace std;

int main(){
		
	AFN afn;
	
	afn.addInitial(1);
	afn.addFinal(4);
	
	afn.addTransition(1,'a',1);
	afn.addTransition(1,'b',1);
	afn.addTransition(1,'b',2);
	afn.addTransition(2,'b',3);
	afn.addTransition(3,'a',4);
	
	AFD a=afn.getAFD(1);
	
	afn.show();
	cout<<endl;
	
	a.show();
	cout<<endl;
	
	string s;
	while(cout<<"Expresion: ", getline(cin, s), s!="$"){
		if(a.eval(s)) cout<<"VALIDO"<<endl<<endl;
		else cout<<"INVALIDO"<<endl<<endl;
	}
	
	return 0;
}
