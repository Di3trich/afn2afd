#ifndef __AFN_HPP__
#define __AFN_HPP__

#include <map>
#include <set>
#include <queue>
#include "afd.hpp"

class AFN{
private:
	std::map< int, std::set< std::pair< char, int > > > trans;
	std::set< int > ini, fin, est;
	std::map< int, std::set< int > > eTrans;
	std::set< char > sim;
	void _dfsETrans(int v, std::set< int > &estate){
		if(estate.count(v)) return;
		estate.insert(v);
		for(auto &q: eTrans[v])
			_dfsETrans(q, estate);
	}
	std::set< int > _getEstate(const std::set< int > &st){
		std::set< int > estate;
		for(auto &q: st)
			_dfsETrans(q, estate);
		return estate;
	}
	bool _isFinal(const std::set< int > &st){
		for(auto &q: st)
			if(fin.count(q))
				return true;
		return false;
	}
public:
	const static char E=-1;
	void addInitial(int q){
		ini.insert(q);
	}
	void addFinal(int q){
		fin.insert(q);
	}
	void addTransition(int a, char c, int b){
		est.insert(a);
		est.insert(b);
		if(c==E){
			eTrans[a].insert(b);
		}else{
			sim.insert(c);
			trans[a].insert(std::make_pair(c, b));
			if(trans.count(a)==0)
				trans[a]=std::set< std::pair<char,int> >();
		}
	}
	AFD getAFD(int qidini=0){
		int qid=qidini;
		std::map< std::set< int >, int > name;
		std::queue< std::set< int > > que;
		AFD afd;
		std::set< int > initial=_getEstate(ini);
		name[initial]=qid++;
		afd.setInitial(name[initial]);
		if(_isFinal(initial))
			afd.addFinal(name[initial]);
		que.push(initial);
		while(!que.empty()){
			auto q = que.front(); que.pop();
			for(auto &s: sim){
				std::set< int > es;
				for(auto &i: q){
					for(auto &j: trans[i]){
						if(s==j.first)
							es.insert(j.second);
					}
				}
				es=_getEstate(es);
				if(!es.empty()){
					if(name.count(es)==0){
						name[es]=qid++;
						que.push(es);
					}
					afd.addTransition(name[q], s, name[es]);
					if(_isFinal(es))
						afd.addFinal(name[es]);
				}
			}
		}
		return afd;
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
			if(ini.count(i)) printf(">");
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
