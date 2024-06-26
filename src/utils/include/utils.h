#include <fstream>

namespace df {

inline void writeMessage(const char *fmt, ...) {
  std::ofstream logFile("log_file.log");
}

} // namespace df
