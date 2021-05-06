#pragma once
#include <iostream>
#include <time.h>

namespace data_structures {
  
  class TaskNode {
    private :
    std::string description;
    tm deadline;
    TaskNode *next;

    public :
    /**
     * @brief Constructor
     */
    TaskNode(std::string description, tm deadline){
      this->description = description;
      this->deadline = deadline;
      this->next = nullptr;
    }

    bool isDeadlineEarlier(const TaskNodePointer current) const {
      //TODO : Implementasikan
    }
  };

  typedef TaskNode *TaskNodePointer;

  class TaskPriorityQueue {
    private :
    TaskNodePointer head;
    TaskNodePointer tail;

    public:
    /**
     * @brief Constructor
     * 
     * @constructor
     */
    TaskPriorityQueue() {
      head = nullptr;
      tail = nullptr;
    }

    bool isEmpty() const {
      //TODO : Implementasikan
    }

    void enqueue(const TaskNodePointer newNode){
      //TODO : Implementasikan 
    }

    void dequeue(){
      //TODO : Implementasikan
    }

    void peek() const {
      //TODO : Implementasikan
    }

    void for_each() const {
      //TODO : Implementasikan
    }
  };
}