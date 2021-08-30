#include "PathFinder.h"

// defining the > operator for custom class ANode lets us easily use the std priority_queue 
bool operator > (const ANode& lhs, const ANode& rhs)
{
	// definition of huerstic used to order elements in priority. critical logic.
	// A* can often out perform Dijkstra by incorportating this notion of EstimatedCostTo goal
    return (lhs.GetEstCost() + lhs.GetCostTo()) > (rhs.GetEstCost() + rhs.GetCostTo());
}

// implementing a star to visit the nearest goal to each "starting point"
std::vector<Node> PathFinder::GetBestPath(){
	// using A * to breadth first search iterate through map to return optimal solution
	// hueristic h(n) is taxicab distance to goal


	// Design decision, will navigate from closest goal to closest goal from our current goal
	// so we can utilize astar for point to point pathing. A pure flood fill method like Dijkstra's
	// would not require this goal shifting; however, for a sufficiently large store and sufficiently few target items 
	// A* from goal to should require less computation to path the robot to each goal due to A* out performing Dijkstra on desnse graphs
	// that being said we will have to clear notion of OPEN and CLOSED nodes after each goal is found

	// get GLOBAL start node form GMap
	Node startNode = map_.GetStart();
	while (!unvisitedGoals_.empty()){
		// get closest univsited goal
		current_goal_ = GetClosestGoal(startNode);
		// get the ANode for start Node(start node has cost to of 0)
		current_ANode_ = Anode(startNode, GetCostToGoal(startNode), 0);
		while (current_ANode_ != current_goal_)
			// expand current node
			auto neighbor_vec = map_.GetNeighbors(current_ANode_);
			// it.first == Node
			// it.second == NT
			for (auto const &potNode : neighbor_vec){
				// if at obstacle, pass
				switch(potNode.second){
					case NT::Obstacle:
						continue;
						break;
					// treating start node like any other open node (as start node will be reassigned after first goal is found)
					case NT::Start:
					case NT::Open:
						// add node to our priority queu 
						prio_q_.emplace(postNode.first, GetCostToGoal(postNode.first), current_ANode_.GetCostTo() + 1);
						break;
				}


			}



			// add first element to min heap! 
			prio_q_.emplace();



		// end by setting current goal to the new startNode

	}












	return path_;
}