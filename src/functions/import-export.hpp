#pragma once
#include <csv2.hpp>
#include <vector>
#include "../data-structures/linked-list.hpp"
#include "../data-structures/queue.hpp"

bool import_data(data_structures::CategoryList &list, std::string name);

bool export_data(data_structures::CategoryList &list, std::string name);