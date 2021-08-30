#include <string>

#include "GMap.h" 
#include "PathFinder.h" 

using namespace std;
/*
 objectives. start at start point 
	maintain a map that maps coord to val
	pass to an adjency list builder that starts at start
	pass adjacency list to solver
	solver returns solution	
*/

// program entry
int main(int argc, char const *argv[])
{
	/* Read in File IO */
	string fname; 
	// check for user input
	if (argc > 1) 
		fname = string(argv[1]);
	else 
		fname = string("inputs/test_input.txt");
	
	// communicate input file to user
	cout << "Reading map input from: " << fname << endl;
	// load map into program memory
	auto gmap = GMap(fname);
	// generate adjecency list
	auto solver = PathFinder(gmap);

	/* code */
	return 0;
}