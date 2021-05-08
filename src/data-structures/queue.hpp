#pragma once
#include <iostream>
#include "./src/functions/datetime-plus.hpp"

namespace data_structures {
  
  struct TaskNode {
    std::string description;
    tm deadline;
    TaskNode *next;
    
    /**
     * @brief Constructor
     * 
     * @param description deskripsi task
     * @param deadline tanggal deadline
     */
    TaskNode(const std::string description, const tm deadline){
      this->description = description;
      this->deadline = deadline;
      this->next = nullptr;
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

    bool is_empty() const {
      return head == nullptr;
    }

    void enqueue(const TaskNodePointer newNode){
      // deadline lebih awal = lebih di atas

      if (is_empty()) {
        head = newNode;
        tail = newNode;
        return;
      } 

      TaskNodePointer tempPrev = nullptr;
      TaskNodePointer temp = head;
      
      while (compare_deadline(temp->deadline, newNode->deadline) == '>' || 
             compare_deadline(temp->deadline, newNode->deadline) == '='){
        if (temp == tail) break;
        tempPrev = temp;
        temp = temp->next;
      }

      if (temp == head && compare_deadline(newNode->deadline, temp->deadline) == '>'){
        newNode->next = temp;
        head = newNode;
        return;
      }
      if (temp == tail && compare_deadline(newNode->deadline, temp->deadline) == '<'){
        temp->next = newNode;
        tail = newNode;
        return;
      }
      tempPrev->next = newNode;
      newNode->next = temp;
    }

    void dequeue(){
      TaskNodePointer delPtr;
      if (is_empty()){
        delPtr = nullptr;
        return;
      }

      if (head->next == nullptr){
        delPtr = head;
        head = nullptr;
        tail = nullptr;
        delete delPtr;
        return;
      }
      
      delPtr = head;
      head = head->next;
      delete delPtr;
    }

    TaskNodePointer top() const {
      return head;
    }

    void for_each(void (func)(TaskNodePointer)) const {
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }
  };
}