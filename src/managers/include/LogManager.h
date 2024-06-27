#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include "Manager.h"
#include <cstdio>
#include <string>

namespace df {

const std::string LOGFILE_NAME = "dragonfly.log";

class LogManager : public Manager {

private:
  LogManager();
  LogManager(LogManager const &);
  void operator=(LogManager const &);

  bool m_do_flush;
  std::FILE *m_p_f;
  static LogManager *m_instance;

public:
  ~LogManager();

  static LogManager &getInstance() {
    if (m_instance == nullptr) {
      m_instance = new LogManager();
    }

    return *m_instance;
  }

  int startUp();
  void shutDown();
  void setFlush(bool do_flush = true);
  int writeLog(const char *fmt, ...);
};

} // namespace df

#endif
