#include "GMap.h"

void GMap::PopulateMap(){
	// c++ method of interfacing with files
	string line;

	// index into current position
	Node curr_pos(0,0);

	if (map_file_.is_open()){
	    // iterate through each line in file
	    while ( getline (map_file_,line) )
	    {
	    	for (char c : line) {
	    		cout << c;
	    		map_[curr_pos] = symbol_list_[c];
	    		if (map_[curr_pos] == NT::Avocado){
	    			goals_.push_back(curr_pos);
	    		} else if (map_[curr_pos] == NT::Start){
	    			start_ = curr_pos;
	    		}
	    		curr_pos.first++;
	    	}
	    	curr_pos.first = 0;
	    	curr_pos.second++;
	    	cout << endl;
	    }
	    map_file_.close();
	    cout << "Map Generated From Input" << endl;
	} else {
		cout << "could not open your boy" << endl;
	}
}

map<Node, NT> GMap::GetNeighbors(Node n){
	map<Node, NT> neighb_map;
	
	vector<Node> neigh_nodes = {
		Node(n.first, n.second-1), // North
		Node(n.first+1, n.second), // East
		Node(n.first, n.second+1), // South
		Node(n.first-1, n.second)  // West
	};

	for (Node n : neigh_nodes){
		// if map was not bounded would need to do bound check
		neighb_map[n] = map_[n];
	}

	return neighb_map;
}