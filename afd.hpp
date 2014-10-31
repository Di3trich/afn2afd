#ifndef __AFD_HPP__
#define __AFD_HPP__

#include <map>
#include <set>
#include <cstdio>

class AFD{
private:
	std::map< int, std::map< char, int > > trans;
	std::set< int > fin, est;
	std::set< char > sim;
	int ini;
	bool _eval(const std::string &s, int estate, int p){
		if(fin.count(estate) && s[p]==0)
			return true;
		if(trans.count(estate)){
			if(trans[estate].count(s[p]))
				return _eval(s, trans[estate][s[p]], p+1);
		}
		return false;
	}
public:
	void setInitial(int q){
		ini=q;
	}
	void addFinal(int q){
		fin.insert(q);
	}
	void addTransition(int a, char c, int b){
		est.insert(a);
		sim.insert(c);
		est.insert(b);
		trans[a][c]=b;
		if(trans.count(b)==0)
			trans[b]=std::map< char, int >();
	}
	bool eval(const std::string &s){
		return _eval(s, ini, 0);
	}
	void show(){
		printf("Simbolos:\n");
		bool fst=true;
		for(auto &i: sim){
			if(!fst) printf(", ");
			fst=false;
			printf("'%c'", i);
		}
		printf("\nEstados:\n");
		fst=true;
		for(auto &i: est){
			if(!fst) printf(", ");
			fst=false;
			if(i==ini) printf(">");
			if(fin.count(i)) printf("(");
			printf("(%d)", i);
			if(fin.count(i)) printf(")");
		}
		printf("\nTransiciones:\n");
		for(auto &i: trans){
			for(auto &j: i.second){
				printf("(%d)---[%c]-->(%d)\n", i.first, j.first, j.second);
			}
		}
	}
};

#endif
