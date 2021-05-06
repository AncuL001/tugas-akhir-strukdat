#pragma once
#include "queue.hpp"

namespace data_structures {

  class CategoryNode {
    private :
    std::string name;
    TaskPriorityQueue tasks;
    CategoryNode *prev;
    CategoryNode *next;

    public :
    /**
     * @brief Constructor
     */
    CategoryNode(std::string name){
      this->name = name;
      prev = nullptr;
      next = nullptr;
    }

    void changeName(std::string newName){
      name = newName;
    }
  };

  typedef CategoryNode *CategoryNodePointer;
  
  class CategoryList {
    private :
    CategoryNodePointer head;
    CategoryNodePointer tail;

    public :
    /**
     * @brief Constructor
     */
    CategoryList(){
      head = nullptr;
      tail = nullptr;
    }

    void insertCategory(const CategoryNodePointer newNode){
      //TODO : Implementasikan
    }

    void removeCategory(std::string name){
      //TODO : Implementasikan
    }

    void changeNodeName(std::string oldName, std::string newName){
      //TODO : Implementasikan
    }

    void for_each() const {
      //TODO : Implementasikan
    }
  };
}