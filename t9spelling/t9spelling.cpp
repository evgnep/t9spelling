#include <sstream>
#include <unordered_map>

#include "t9spelling.h"

/**
 * Возвращает последовательность клавиш, соответствующую символу
 * Если символ недопустим - бросает std::runtime_error
 */
static std::string_view char2keys(char c) {
  static std::unordered_map<char, std::string> map; // словарь символ -> клавиши
  if (map.empty()) { // инициализация словаря
    constexpr auto keyCnt = 10;
    static const char* const data[keyCnt] = {
      " ", // 0
      "", // 1
      "abc", // 2
      "def", // 3
      "ghi", //4
      "jkl", //5
      "mno", // 6
      "pqrs", // 7
      "tuv", // 8
      "wxyz" // 9
    };
    for (auto key = 0; key < keyCnt; ++key)
      for (auto start = data[key], cur = start; *cur; ++cur) {
        map[*cur] = std::string(cur - start + 1, '0' + key);
      }
  }

  auto it = map.find(c);
  if (it == map.end()) {
    std::ostringstream s;
    s << "Invalid character: " << c;
    throw std::runtime_error(s.str());
  }
  return it->second;
}

void t9spelling::encode(std::string_view from, std::string &to) {
  to.clear();
  to.reserve(from.size() * 5); // с запасом (zz -> 9999 9999)

  char prevKey = 0;
  for (auto c : from) {
    const auto keys = char2keys(c);
    if (keys[0] == prevKey)
      to.push_back(' ');
    to.append(keys);
    prevKey = keys[0];
  }
}
