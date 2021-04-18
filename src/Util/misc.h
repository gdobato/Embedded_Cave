#ifndef __MISC_H__
#define __MISC_H__


namespace util::misc
{
  template <typename... Args> inline void unused(Args&&...) {}
}

#endif