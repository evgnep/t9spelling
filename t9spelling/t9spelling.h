#pragma once

#include <string_view>

namespace t9spelling {

  /**
   * Перекодирует строку from в to согласно правилам из https://code.google.com/codejam/contest/dashboard?c=351101#s=p2
   * Если строка содержит недопустимый символ - бросает std::runtime_error
   */
  void encode(std::string_view from, std::string &to);

}
