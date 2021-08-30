#include "helpers.h"

int TCDist(Node n1, Node n2){
	return abs(n1.first-n2.first) + abs(n1.second-n2.second);
}