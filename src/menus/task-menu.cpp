#include "task-menu.hpp"

void first_task_screen(data_structures::CategoryNodePointer current){
  // TODO : Benahi kasus task kosong
  while (true){
    auto top = current->tasks.top();
    std::cout << "Kategori : " << current->name << "\n\n\n\n"
              << top->description
              << "Deadline : " << top->deadline.tm_year << "-" 
                              << top->deadline.tm_mon << "-" 
                              << top->deadline.tm_mday << "\n\n\n\n\n" 
              << "1. Tandai selesai\n"
              << "0. Kembali\n"
              << ">>";
    char sel;
    std::cin >> sel;
    switch (sel){
      case '1':
        current->tasks.dequeue();
        break;

      case '0':
        return;

       default:
        break;
    }
  }
}

void all_task_screen(const data_structures::CategoryNodePointer current){
  // TODO : Benahi kasus task kosong
  // TODO : Pagination
  auto tasks = current->tasks;
  std::cout << "Kategori : " << current->name << "\n\n\n"
            << "Deadline   | Task\n";
  tasks.for_each([](data_structures::TaskNodePointer task){
    std::cout << task->deadline.tm_year << "-" 
              << task->deadline.tm_mon << "-" 
              << task->deadline.tm_mday << " | " 
              << task->description << "\n";
  });
  std::cout << "\n\n\n 0. Kembali\n>>";
  char sel;
  std::cin >> sel;
  switch (sel){
    case '0':
      return;

     default:
      break;
  }
}

void add_task_screen(data_structures::CategoryNodePointer current){
  // TODO : Benahi input tanggal yang tidak benar
  std::string name;
  std::string deadline;
  std::cout << "Kategori : " << current->name << "\n\n\n"
            << "Nama Task :\n>>";
  std::getline(std::cin, name);
  std::cout << "\nDeadline (YYYY-MM-DD) :\n>>";
  std::cin >> deadline;
  current->tasks.enqueue(new data_structures::TaskNode(name, parse_date(deadline)));
}