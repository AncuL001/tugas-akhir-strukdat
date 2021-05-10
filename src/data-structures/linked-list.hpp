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
    CategoryNodePointer current;

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
        current = newNode;
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

    bool remove_category(std::string name) {
      // 0 jika gagal, 1 jika berhasil
      CategoryNodePointer temp = find_category(name);
      if (temp == nullptr) return 0;

      if (temp == head){
        if (temp == tail){
          head = nullptr;
          tail = nullptr;
        }
        else {
          temp->next->prev = nullptr;
          head = temp->next;
        }
      }

      else {
        if (temp == tail){
          temp->prev->next = nullptr;
          tail = temp->prev;
        }
        else {
          temp->next->prev = temp->prev;
          temp->prev->next = temp->next;
        }
      }

      delete temp;
      // TODO : Benahi memory leak
      return 1;
    }

    bool rename_category(const std::string oldName, const std::string newName){
      // 0 jika gagal, 1 jika berhasil
      CategoryNodePointer temp = find_category(oldName);
      if (temp == nullptr) return 0;

      temp->name = newName;
      return 1;
    }

    void for_each(void (func)(CategoryNodePointer)) const {
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }
  };
}