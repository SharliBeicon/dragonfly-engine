#include "Manager.h"
namespace df {

Manager::Manager() : m_type("default"), m_is_started(false) {}

void Manager::setType(std::string type) { m_type = type; }

std::string Manager::getType() const { return m_type; }

bool Manager::isStarted() const { return m_is_started; }
} // namespace df
