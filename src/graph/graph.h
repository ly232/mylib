/*
Author: Lin Yang
Date: 1/10/2013
Description:
a general purpose graph class, implementing various graph algorithms.
*/
#ifndef _graph_h
#define _graph_h
#include <map>
#include <list>
#include "node.h"
namespace ns_graph{
class Graph{
public:
	Graph();
	int addNode(int id);
	int removeNode(int id);
	int addLink(int id1, int id2);
	int removeLink(int id1, int id2);
	int findNode(int id, ns_node::Node *& n);
private:
	std::map< ns_node::Node, std::list<ns_node::Node> > node_map; //key=node, value=node_neighbor

};
} //end namespace ns_graph
#endif


