//bst.cpp
#include "bst.h"
bst::bst():root(NULL)
{

}

bst::~bst()
{

}

bst::bst(const bst& rhs)
{

}

const bst& bst::operator=(const bst& rhs)
{
  return rhs;
}

int bst::height()
{
  return -1;
}

STATUS bst::delete(const std::string& key)
{
  return FAIL;
}
