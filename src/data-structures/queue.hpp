#pragma once
#include <string>

namespace data_structures {
  
  class TaskNode {
    private :
    std::string description;
    TaskNode *next;
  };

  typedef TaskNode *TaskNodePointer;

  class PriorityQueue {
    private :
    TaskNodePointer head;
    TaskNodePointer tail;
  };
}