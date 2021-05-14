#include "additional-menu.hpp"

void undo_action(data_structures::CategoryList &list){
  // TODO : Implementasikan
}

void import_data(data_structures::CategoryList &list){
  // TODO : Implementasikan
}

void export_data(data_structures::CategoryList &list){
  // TODO : Implementasikan
}

void purge_data(data_structures::CategoryList &list){
  // TODO : Implementasikan
}

void additional_options_screen(data_structures::CategoryList &list){
  // TODO : Implementasikan Stack
  // TODO : Regret my decision to add additional menu
  system("cls");
  std::cout << "\nAksi Terakhir:\n\n\n\n"
            << "1. Undo aksi terakhir\n"
            << "2. Impor data\n"
            << "3. Ekspor data\n"
            << "4. Hapus semua data\n"
            << "0. Kembali";
  char sel;
  std::cin >> sel;
  switch (sel){
      case '1':
        undo_action(list);
        break;

      case '2':
        import_data(list);
        break;

      case '3':
        export_data(list);
        break;

      case '4':
        purge_data(list);
        break;

      case '0':
        return;

      default:
        break;
    }
}