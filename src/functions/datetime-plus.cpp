#include "datetime-plus.hpp"

char compare_deadline(tm lhs, tm rhs){
  if (lhs.tm_year > rhs.tm_year) return '>';
  if (lhs.tm_year < rhs.tm_year) return '<';

  if (lhs.tm_mon > rhs.tm_mon) return '>';
  if (lhs.tm_mon < rhs.tm_mon) return '<';

  if (lhs.tm_mday > rhs.tm_mday) return '>';
  if (lhs.tm_mday < rhs.tm_mday) return '<';

  return '=';
}

tm parse_date(std::string string_form){
  // TODO : Implementasikan
}