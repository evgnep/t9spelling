#pragma once

#include <string_view>

namespace t9spelling {

  /**
   * ������������ ������ from � to �������� �������� �� https://code.google.com/codejam/contest/dashboard?c=351101#s=p2
   * ���� ������ �������� ������������ ������ - ������� std::runtime_error
   */
  void encode(std::string_view from, std::string &to);

}
