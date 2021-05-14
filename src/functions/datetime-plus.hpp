#pragma once
#include <iostream>
#include <sstream>
#include <ctime>

/**
 * @brief membandingkan dua tanggal
 * 
 * @note menggunakan tm_year, tm_mon, tm_mday dalam struct tm
 * @see https://www.cplusplus.com/reference/ctime/tm/
 * 
 * @param lhs
 * @param rhs
 * @return '>' jika tanggal yang kanan lebih awal, '<' jika yang kiri lebih awal, '=' jika kedua tanggal sama
 */
char compare_deadline(tm lhs, tm rhs);

tm parse_date(std::string string_form);