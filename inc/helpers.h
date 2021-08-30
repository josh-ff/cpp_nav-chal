#ifndef HELPERS_H_
#define HELPERS_H_

#include <math.h>
#include <utility> // pair
using namespace std;

// bonus points if they make a more sophisticated point or node class
// (0,0) will be defined as top left of input
typedef pair<int,int> Node;
	
// taxicab distance equation d = abs(x1-x2) + abs(y1-y2)
// because of traversal options being: up, down, left, right || grid based world
// calculating the Manhattan or 'TaxiCab' distance is a more meaningful hueristic 
int TCDist(Node n1, Node n2);

#endif /* HELPERS_H_ */