#ifndef GMAP_H_
#define GMAP_H_

#include <map>
#include <string> 
#include <fstream>
#include <vector>
#include <iostream> // debug

#include "helpers.h"

using namespace std;

// enum representing NodeType
enum class NT : int {Obstacle, Open, Avocado, Start};

/* 
 * Grocery Map Class
 * 1. Maintains a map in memory of the input
 * 	a. responsible for file IO operations and maintaining lexicon for symbols
 * 2. Exposes convience functions for PathFinder
*/
class GMap {
private:
	// file object for input map
	ifstream map_file_;

	// maps node location to node type
	map<Node, NT> map_;

	// maintain a list of Avocado location for use in cost func of solver
	vector<Node> goals_;
	Node start_;

	// symbol lexicon for object. can be past to constructor for added flexability
	map<char, NT> symbol_list_ {
		{'#', NT::Obstacle},
		{'.', NT::Open},
		{'@', NT::Avocado},
		{'x', NT::Start},
	};

	// file parsing function
	void PopulateMap();

public:
	// Constructor takes filename, generates map in memory
	GMap(string fname) {
		// could perform some form of input error checking here
		
		// file io
		map_file_.open(fname);
		
		// populate map
		PopulateMap();
	}

	// return locations of Avocados
	vector<Node> GetGoals() {return goals_;}
	// return start location
	Node GetStart() {return start_;}
	// Get Adjaceny List of Current Node. Returns of form: North, East, South, West
	map<Node, NT> GetNeighbors(Node n);
};

#endif /* GMAP_H_ */