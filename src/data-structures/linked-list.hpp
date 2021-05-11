#pragma once
#include "queue.hpp"

namespace data_structures {

  /**
   * @brief implementasi struct untuk elemen kategori
   */
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

  /**
   * @brief tipe data pointer untuk kategori
   */
  typedef CategoryNode *CategoryNodePointer;
  
  /**
   * @brief implementasi class untuk linked list
   */
  class CategoryList {
    private :
    CategoryNodePointer head;
    CategoryNodePointer tail;

    public :
    /**
     * @brief menyimpan kategori yang sedang digunakan
     */
    CategoryNodePointer current;

    /**
     * @brief Constructor
     */
    CategoryList(){
      head = nullptr;
      tail = nullptr;
    }

    /**
     * @brief mengetahui apakah list kosong
     *
     * @return 1 jika kosong, 0 jika tidak
     */
    bool is_empty(){
      return head == nullptr;
    }

    /**
     * @brief memasukan node ke paling belakang list.
     * 
     * @param newNode node yang ingin dimasukkan.
     */
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

    /**
     * @brief mencari node dengan nama yang dimaksud.
     * 
     * @param name nama node yang ingin dicari.
     * @return sebuah node jika ada, nullptr jika tidak ada
     */
    CategoryNodePointer find_category(const std::string name) const {
      CategoryNodePointer temp = head;
      while (temp->name != name && temp){
        temp = temp->next;
      }
      return temp;
    }

    /**
     * @brief menghapus node dengan nama yang dimaksud.
     * 
     * @todo benahi memory leak (karena node task yang di kategori tidak di-delete)
     * @todo mengubah fungsi supaya memasukkan node ke undo stack.
     * 
     * @param name nama node yang ingin dihapus.
     * @return 0 jika penghapusan gagal (node tidak ditemukan), 1 jika berhasil
     */
    bool remove_category(std::string name) {
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
      return 1;
    }

    /**
     * @brief mengubah nama node.
     * 
     * @param oldName nama node yang ingin diganti namanya.
     * @param newName nama baru node.
     * @return 0 jika penggantian nama gagal (node tidak ditemukan), 1 jika berhasil
     */
    bool rename_category(const std::string oldName, const std::string newName){
      // 0 jika gagal, 1 jika berhasil
      CategoryNodePointer temp = find_category(oldName);
      if (temp == nullptr) return 0;

      temp->name = newName;
      return 1;
    }

    /**
     * @brief mengiterasi elemen pada list dan memberikannya kepada fungsi.
     *
     * @param func fungsi yang akan diberikan elemen.
     */
    template <typename F>
    void for_each(F func) const {
      for (auto temp = head; temp; temp = temp->next){
        func(temp);
      }
    }
  };
}