#include <bits/stdc++.h>
#include "afd.hpp"
#include "afn.hpp"
using namespace std;

int main(){
		
	AFN afn;
	
	afn.addInitial(0);
	afn.addFinal(5);
	
	afn.addTransition(0,'a',1);
	afn.addTransition(1,'a',0);
	afn.addTransition(0,AFN::E,2);
	afn.addTransition(0,'c',4);
	afn.addTransition(2,'b',3);
	afn.addTransition(3,'b',2);
	afn.addTransition(2,AFN::E,5);
	afn.addTransition(4,'a',4);
	afn.addTransition(4,AFN::E,5);
	
	AFD a=afn.getAFD();
	
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
