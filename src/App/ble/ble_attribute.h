#ifndef __BLE_ATTRIBUTE_H__
#define __BLE_ATTRIBUTE_H__

#include <cstdint>
#include <string>
#include <array>
#include <tuple>
#include <ble_uuid.h>

namespace app::ble
{

class Attribute final
{
  public:
    using type_t                = enum {
                                         service_type           = 0x2800,
                                         characteristic_type    = 0x2803,
                                         descriptor_type        = 0x2900
                                       };
    using handle_t              = uint16_t;
    using properties_t          = enum {
                                         none                   = 0x01,
                                         readable               = 0x02,
                                         writable               = 0x04,
                                         encryp_unauthenticated = 0x10,
                                         encryp_authenticated   = 0x40,
                                         authorization          = 0x80,
                                        };

    Attribute(const char* uuid, properties_t properties, handle_t handle);
   ~Attribute() = default;

  private:
    handle_t m_handle;
    UUID     m_uuid;
  
};

}

#endif