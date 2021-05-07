#pragma once
#include "queue.hpp"

namespace data_structures {

  struct CategoryNode {
    std::string name;
    TaskPriorityQueue tasks;
    CategoryNode *prev;
    CategoryNode *next;
    
    /**
     * @brief Constructor
     * 
     * @param name nama kategori baru
     */
    CategoryNode(std::string name){
      this->name = name;
      prev = nullptr;
      next = nullptr;
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

    bool is_empty(){
      return head == nullptr;
    }

    void insert_category(const CategoryNodePointer newNode){
      if (is_empty()){
        head = newNode;
        tail = newNode;
        return;
      }
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }

    CategoryNodePointer find_category(const std::string name) const {
      CategoryNodePointer temp = head;
      while (temp->name != name && temp){
        temp = temp->next;
      }
      return temp;
    }

    void remove_category(std::string name) {
      CategoryNodePointer temp = find_category(name);
      //TODO : Implementasikan
    }

    void rename_category(const std::string oldName, const std::string newName){
      CategoryNodePointer temp = find_category(oldName);
      if (temp){
        temp->name = newName;
      }
    }

    void for_each() const {
      //TODO : Implementasikan
    }
  };
}