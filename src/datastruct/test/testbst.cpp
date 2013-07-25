#include "bst.h"
#include <iostream>
int main()
{
  bst<std::string> b;
  b.insert("LinYang", "ly232@cornell.edu");
  b.insert("ChenWang", "cw597@cornell.edu");
  b.insert("XyZ", "xyz@cornell.edu");
  b.print_tree();
  return 0;
}
