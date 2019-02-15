#include <sstream>

#include "t9spelling.h"
#include "task.h"

void run(std::istream &from, std::ostream &to) {
  int n;
  from >> n;
  if (n < 1 || n > 100) {
    std::ostringstream s;
    s << "Invalid N: " << n;
    throw std::runtime_error(s.str());
  }

  std::string src, res;
  getline(from, src);
  for (int i = 0; i < n; ++i) {
    src.clear();
    getline(from, src);    
    t9spelling::encode(src, res);
    if (i)
      to << std::endl;
    to << "Case #" << (i+1) << ": " << res;
  }
}

