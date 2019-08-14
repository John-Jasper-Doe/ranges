/**
 ******************************************************************************
 * @file    filter.cpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The filter function.
 ******************************************************************************
 */



#include "filter.hpp"
#include <range/v3/algorithm/find.hpp>


/* ------------------------------------------------------------------------- */
bool helper_filter_any(const ipaddr_t &addr, uint32_t val)
{
  return ranges::find(addr, val) != ranges::end(addr);
}

/* ------------------------------------------------------------------------- */
bool helper_filter(const ipaddr_t &addr, const ipaddr_t &tmp_addr)
{
  if (tmp_addr.size() > addr.size())
    return false;

  auto it_tmp_addr = tmp_addr.begin();
  auto it_addr = addr.begin();
  for (; it_tmp_addr != tmp_addr.end(); ++it_tmp_addr, ++it_addr) {
    if (*it_tmp_addr != *it_addr)
      return false;
  }

  return true;
}

/* ------------------------------------------------------------------------- */
ip_pool_t filter_any(const ip_pool_t &pool, uint32_t val)
{
  ip_pool_t result;
  for (const ipaddr_t &ip : pool) {
    if (helper_filter_any(ip, val))
      result.push_back(ip);
  }
  return result;
}

