#ifndef _node_h
#define _node_h
namespace ns_node{
class Node {
public:
	Node(int i):id(i){};
	int getId();
	bool operator==(const Node& rhs);
	bool operator<(const Node& rhs);
private:
	int id;
};
}//end namespace ns_node
#endif
