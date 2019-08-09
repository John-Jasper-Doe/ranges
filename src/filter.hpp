/**
 ******************************************************************************
 * @file    filter.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The filter function.
 ******************************************************************************
 */


#include "defs.hpp"


/* ------------------------------------------------------------------------- */
bool helper_filter_any(const ipaddr_t &pool, uint32_t val);


/* ------------------------------------------------------------------------- */
template <typename... Args>
bool helper_filter(const ipaddr_t &addr, Args... args)
{
  static_assert(sizeof...(Args) <= 4,
                "filter gets 4 parameters max + ip_pool");

  ipaddr_t a{args...};
  if (a.size() > addr.size())
    return false;

  auto it_a = a.begin();
  auto it_addr = addr.begin();
  for (; it_a != a.end(); ++it_a, ++it_addr) {
    if (*it_a != *it_addr)
      return false;
  }

  return true;
}




