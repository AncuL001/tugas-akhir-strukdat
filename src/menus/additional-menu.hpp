#pragma once
#include "./src/data-structures/linked-list.hpp"
#include "./src/data-structures/queue.hpp"

void undo_action(data_structures::CategoryList &list);

void import_data(data_structures::CategoryList &list);

void export_data(data_structures::CategoryList &list);

void purge_data(data_structures::CategoryList &list);

void additional_options_screen(data_structures::CategoryList &list);