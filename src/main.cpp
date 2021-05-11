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
    std::cout << "Kategori :" << list.current->name << "\n\n"
              << "1. Lihat task pertama \n"
              << "2. Lihat semua task\n"
              << "3. Tambahkan task\n\n"
              << "8. Pengaturan kategori\n"
              << "9. Pengaturan lain\n\n"
              << "0. Keluar\n"
              << ">>";
    char sel;
    std::cin >> sel;
    switch (sel){
      case '1':
        first_task_screen(list.current);
        break;

      case '2':
        all_task_screen(list.current);
        break;

      case '3':
        add_task_screen(list.current);
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
  main_menu(list);
}