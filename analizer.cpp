#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class matrice{
	private:
		map<int, map<int, int> > Mat;// (num_edges + 2, map<int, int>());
	public:
		matrice(){
				
		}
		addConnection(int idA, int idB){
				Mat[idA][idB] = Mat[idB][idA];
		}
		int size() const{
			return Mat.size();
		}

	int analyze(){
		int ctr = 0;
		while (Mat.size() > 1) {
			map<int, map<int, int> >::iterator row_itr = Mat.begin();
			map<int, vector<int> > nodes_erased;
			while (row_itr != Mat.end()) {
				
				if (row_itr->second.size() == 1) {
					int idx = row_itr->first;
					int connecting_node = row_itr->second.begin()->first;	
					row_itr++;
					Mat.erase(idx);
					nodes_erased[connecting_node].push_back(idx);
				}
			else { row_itr++; }
			}
		map<int, vector<int> >::iterator cleaner = nodes_erased.begin();
		for (cleaner = nodes_erased.begin(); cleaner != nodes_erased.end(); cleaner++)
			if (Mat.count(cleaner->first) > 0) {
				for (int i = 0; i < cleaner->second.size(); i++)
					Mat[cleaner->first].erase(cleaner->second[i]);
			}
		ctr++;
		}
		return ctr;
	}

};


