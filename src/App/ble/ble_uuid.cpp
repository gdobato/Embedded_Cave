#include <ble_uuid.h>
#include <string>
#include <algorithm>
#include <iterator>

namespace app::ble
{

UUID::UUID(const std::string& uuid):m_str(uuid)
{

  m_str.erase(std::remove(m_str.begin(), m_str.end(), '-'), m_str.end());
  std::copy (m_str.begin(), m_str.end(), back_inserter(m_raw));
  for (auto i = m_raw.begin(); i != m_raw.end() ; i=i+2 )
  {
      std::iter_swap(i, i + 1);
  }

}

UUID::raw_t UUID::get_raw(void)const
{
  return m_raw;
}

}