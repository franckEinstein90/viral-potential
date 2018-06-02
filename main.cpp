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
		Mat.addConnection(xi, yi);	
	    }
	cout<<Mat.analyze();
}




