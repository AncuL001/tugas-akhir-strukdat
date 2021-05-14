#include "category-menu.hpp"

void print_categories(const data_structures::CategoryList list){
  std::cout << "\nDaftar Kategori:";
  list.for_each([](data_structures::CategoryNodePointer category){
    std::cout << " " << category->name << "\n";
  });
}

void move_category_screen(data_structures::CategoryList &list){
  std::string name;
  print_categories(list);

  std::cout << "\n0. Batal\n>>";
  std::getline(std::cin, name);
  if (name == "0") return;

  list.move_current(name);
}

void rename_category_screen(data_structures::CategoryList &list){
  std::string oldName, newName;
  print_categories(list);

  std::cout << "\n0. Batal\n>>";
  std::getline(std::cin, oldName);
  if (oldName == "0") return;

  std::cout << "Nama Baru:\n>>";
  std::getline(std::cin, newName);
  if (newName == "0") return;

  list.rename_category(oldName, newName);
}

void add_category_screen(data_structures::CategoryList &list){
  std::string name;
  std::cout << "0. Batal\n"
            << "Nama Baru:\n>>";
  std::getline(std::cin, name);
  if (name == "0") return;

  list.insert_category(new data_structures::CategoryNode(name));
}

void remove_category_screen(data_structures::CategoryList &list){
  std::string name;
  print_categories(list);

  std::cout << "\n0. Batal\n>>";
  std::getline(std::cin, name);
  if (name == "0") return;

  list.remove_category(name);
}

void view_category_screen(const data_structures::CategoryList list){
  print_categories(list);
  std::cout << "0. Kembali\n>>";
  char sel;
  std::cin >> sel;
  switch (sel){
    case '0':
      return;

     default:
      break;
  }
}

void category_options_screen(data_structures::CategoryList &list){
  data_structures::CategoryNodePointer current = list.get_current();
  std::cout << "Kategori : " << current->name << "\n\n"
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