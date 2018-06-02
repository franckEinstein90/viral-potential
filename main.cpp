#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "analizer.cpp"

using namespace std;

int main(){
	ifstream infile; 
	matrice Mat;
	infile.open("dataFile.dat");
	if(!infile){
		cerr<< "Unable to open datafile";
		exit(1);
	}

	int num_edges;
	infile >> num_edges; 
	
	for (int i = 0; i < num_edges; i++) {
		int xi; // the ID of a person which is adjacent to yi
		int yi; // the ID of a person which is adjacent to xi
		
		infile >> xi >> yi; 
		cout<<xi<<" "<<yi<<endl;
		Mat.addConnection(xi, yi);	
	    }


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

	cout << ctr<<endl;
}



