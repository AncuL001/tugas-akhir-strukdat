#include <iostream>
#include "data-structures/linked-list.hpp"
#include "data-structures/queue.hpp"

#include "menus/task-menu.hpp"
#include "menus/category-menu.hpp"
#include "menus/additional-menu.hpp"

void main_menu(data_structures::CategoryList &list){
  // TODO : Error-handling untuk list kosong dan queue kosong
  // TODO : Tambahkan cls untuk setiap pindah screen
  while (true){
    data_structures::CategoryNodePointer current = list.get_current();
    std::cout << "Kategori :" << current->name << "\n\n"
              << "1. Lihat task pertama \n"
              << "2. Lihat semua task\n"
              << "3. Tambahkan task\n\n"
              << "8. Pengaturan kategori\n"
              << "9. Pengaturan lain\n\n"
              << "0. Keluar\n"
              << ">> ";
    char sel;
    std::cin >> sel;
    switch (sel){
      case '1':
        first_task_screen(current);
        break;

      case '2':
        all_task_screen(current);
        break;

      case '3':
        add_task_screen(current);
        break;

      case '8':
        category_options_screen(list);
        break;

      case '9':
        additional_options_screen(list); 
        break;

      case '0':
        return;

      default:
        break;
    }
  }
}

int main(){
  data_structures::CategoryList list;

  //Stub data
  list.insert_category(new data_structures::CategoryNode("category_1"));
  list.insert_category(new data_structures::CategoryNode("category_2"));
  list.insert_category(new data_structures::CategoryNode("category_3"));
  list.insert_category(new data_structures::CategoryNode("category_4"));
  list.insert_category(new data_structures::CategoryNode("category_5"));
  list.get_current()->tasks.enqueue(new data_structures::TaskNode("1_task_1", parse_date("2021-12-14")));
  list.get_current()->tasks.enqueue(new data_structures::TaskNode("1_task_2", parse_date("2021-11-15")));
  list.get_current()->tasks.enqueue(new data_structures::TaskNode("1_task_3", parse_date("2021-11-13")));
  list.get_current()->tasks.enqueue(new data_structures::TaskNode("1_task_0", parse_date("2020-11-13")));
  main_menu(list);
}