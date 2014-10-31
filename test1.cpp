#include <bits/stdc++.h>
#include "afd.hpp"
#include "afn.hpp"
using namespace std;

int main(){
		
	AFN afn;
	
	afn.addInitial(0);
	afn.addInitial(1);
	afn.addFinal(2);
	afn.addFinal(3);
	
	afn.addTransition(0,'b',0);
	afn.addTransition(0,AFN::E,2);
	afn.addTransition(1,'a',4);
	afn.addTransition(4,'a',1);
	afn.addTransition(1,AFN::E,2);
	afn.addTransition(2,'c',3);
	
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
