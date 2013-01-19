#include "graph.h"
namespace ns_graph{

Graph::Graph(){

}

//add a node to graph
//if graph already has a node with same id, return -1
//otherwise addNode is successful, return 0
int Graph::addNode(int id){
	
}

//remove node with given id
//return 0 on success; -1 on failure.
int Graph::removeNode(int id){
	return -1;
}

int Graph::addLink(int id1, int id2){
	return -1;
}

int Graph::removeLink(int id1, int id2){
	return -1;
}

//if node with given id exists, set the second argument n to point to the found node and return 0
//otherwise return -1
int Graph::findNode(int id, ns_node::Node *& n){
	std::map< ns_node::Node, std::list<ns_node::Node> >::const_iterator itr = this->node_map.begin();
	for (;itr!=this->node_map.end();itr++){
		if (itr->first.getId()==id){
			n = &(itr->first);
			return 0;
		}
	}
	return -1;	
}

}//end namespace ns_graph

