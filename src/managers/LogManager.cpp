#include "LogManager.h"
#include <cstdio>

namespace df {

int LogManager::startUp() {
  m_p_f = std::fopen(LOGFILE_NAME.c_str(), "w");
  if (m_p_f == nullptr) {
    return -1;
  }

  return 0;
}

void LogManager::shutDown() {
  if (m_p_f != nullptr) {
    std::fclose(m_p_f);
    m_p_f = nullptr;
  }
}

void LogManager::setFlush(bool do_flush) { m_do_flush = do_flush; }

int LogManager::writeLog(const char *fmt, ...) {
  if (m_p_f == nullptr) {
    return -1; // Archivo no está abierto
  }

  va_list args;
  va_start(args, fmt);
  int bytes_written = vfprintf(m_p_f, fmt, args);
  va_end(args);

  if (bytes_written < 0) {
    std::perror("Error al escribir en el archivo");
    return -1;
  }

  if (m_do_flush) {
    std::fflush(m_p_f);
  }
  return bytes_written;
}

} // namespace df
