#ifndef __BLE_UUID_H__
#define __BLE_UUID_H__

#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <tuple>

namespace app::ble
{
class UUID final
{
  public:
    using raw_t = std::vector<uint8_t>;
    using str_t = std::string;

    UUID(const std::string& uuid);
    raw_t get_raw(void)const;
    ~UUID() = default;

  private:
    raw_t  m_raw;
    str_t  m_str;
  
};

}

#endif