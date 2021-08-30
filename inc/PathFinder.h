#ifndef PATH_FINDER_H_
#define PATH_FINDER_H_

#include "GMap.h" // Node 
#include "helpers.h"
#include <vector>
#include <queue> // priority_queue
#include <limits> // int::MAX
using namespace std;

// Extending the Node class specific to our solver implementation
// A* requires maintaining a notion of:
// * previous node
// * estimated cost
// * cost to node

class ANode : public Node {
	public:
		// Constructor takes inital map node + the estimated cost to current goal
		ANode(Node n, int est_cost) : Node(n), estimated_cost_(est_cost), cost_to_(numeric_limits<int>::max()) {}
		// Constructor takes inital map node + the estimated cost to current goal + current cost to
		ANode(Node n, int est_cost, int cost_to) : Node(n), estimated_cost_(est_cost), cost_to_(cost_to) {}
		// Ensure that "cost to node" can only be updated when providing a new path to that node (through another node) 
		void UpdateCostTo(Node n, int cost) {
			prev_ = n;
			cost_to_ = cost;
		}
		// estimated cost to goal
		int GetCostTo() const {return cost_to_;} 
		int GetEstCost() const {return estimated_cost_;} 
		// friend class needed for std::greater for use in minumum heap
    	friend bool operator > (const ANode& lhs, const ANode& rhs);

	private:
		// ideally would be constant, will need to define = operator
		int estimated_cost_;
		int cost_to_;
		// previous node correlated to current "cost to node" 
		ANode prev_;
};

class PathFinder {
public:
	PathFinder(GMap &map) : map_(map) {
		unvisitedGoals_ = map_.GetGoals();
	};
	// returns the best path once completed
	vector<Node> GetBestPath();
private:
	// takes the map stored as memory by reference
	GMap& map_;
	// goal tracking
	Node current_goal_;
	ANode current_ANode_;

	vector<Node> completedGoals_;
	vector<Node> unvisitedGoals_; 
	// where the best path will be stored
	vector<Node> path_;
	// min heap priority queue wher value represents (cost to node + estimated cost to goal)
	priority_queue<ANode, vector<ANode>, greater<ANode>> prio_q_;

	vector<Node> closedNodes;
	vector<Node> openNodes;

	int GetCostToGoal(Node n){
		// TODO throw err check
		return TCDist(current_goal_, n);
	}

	// Returns the closest goal to the current node.
	Node GetClosestGoal(Node n) {
		int closest_goal_dist = numeric_limits<int>::max();
		Node next_goal;
		for (auto const g : unvisitedGoals_){
			auto d = TCDist(n,g);
			if (d < closest_goal_dist){
				closest_goal_dist = d;
				next_goal = g;
			}
		}
		return next_goal;
	}
};

#endif /* PATH_FINDER */