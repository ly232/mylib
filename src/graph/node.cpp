#include "node.h"
namespace ns_node{
int Node::getId(){
	return this->id;
}

bool Node::operator==(const Node& rhs){
	return (this->id==rhs.id)?true:false;
}

bool Node::operator<(const Node& rhs){
	return (this->id<rhs.id)?true:false;
}
}//end namespace ns_node
