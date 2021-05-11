#include "category-menu.hpp"

void print_categories(const data_structures::CategoryList list){
  //TODO : Implementasikan
}

void move_category_screen(data_structures::CategoryList &list){
  //TODO : Implementasikan
}

void rename_category_screen(data_structures::CategoryList &list){
  //TODO : Implementasikan
}

void add_category_screen(data_structures::CategoryList &list){
  //TODO : Implementasikan
}

void remove_category_screen(data_structures::CategoryList &list){
  //TODO : Implementasikan
}

void view_category_screen(const data_structures::CategoryList list){
  //TODO : Implementasikan
}

void category_options_screen(data_structures::CategoryList &list){
  std::cout << "Kategori : " << list.current->name << "\n\n"
            << "1. Pindah Kategori\n"
            << "2. Ubah Nama Kategori\n"
            << "3. Tambahkan Kategori\n"
            << "4. Hapus Kategori\n"
            << "5. Lihat Semua Kategori\n\n\n\n\n\n\n"
            << "0. Kembali\n"
            << ">>";
  char sel;
    std::cin >> sel;
    switch (sel){
      case '1':
        move_category_screen(list);
        break;

      case '2':
        rename_category_screen(list);
        break;

      case '3':
        add_category_screen(list);
        break;

      case '4':
        remove_category_screen(list);
        break;

      case '5':
        view_category_screen(list); 
        break;

      case '0':
        return;

      default:
        break;
    }
}