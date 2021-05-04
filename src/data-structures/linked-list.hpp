#pragma once
#include "queue.hpp"

namespace data_structures {

  class CategoryNode {
    private :
    std::string name;
    PriorityQueue tasks;
    CategoryNode *next;
  };

  typedef CategoryNode *CategoryNodePointer;
  
  class LinkedList {
    private :
    CategoryNodePointer head;
    CategoryNodePointer tail;
  };
}