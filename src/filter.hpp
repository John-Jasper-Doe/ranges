/**
 ******************************************************************************
 * @file    filter.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The filter function.
 ******************************************************************************
 */

#ifndef FILTER_HPP_
#define FILTER_HPP_


#include "defs.hpp"


/* ------------------------------------------------------------------------- */
/**
 * @brief helper_filter_any
 * @param addr[in] - IP-address.
 * @param val[in] - value for comparison.
 * @return "true" - if the address you are looking for is "false" - otherwise.
 */
bool helper_filter_any(const ipaddr_t &addr, uint32_t val);

/**
 * @brief helper_filter
 * @param addr[in] - IP-address.
 * @param tmp_addr[in] - value for comparison.
 * @return "true" - if the address you are looking for is "false" - otherwise.
 */
bool helper_filter(const ipaddr_t &addr, const ipaddr_t &tmp_addr);

/**
 * @brief filter_any
 * @param pool[in] - the pool for filtered.
 * @param val[in] - value.
 * @return IP address equal to value.
 */
ip_pool_t filter_any(const ip_pool_t &pool, uint32_t val);


/* ------------------------------------------------------------------------- */
/**
 * @brief filter
 * @param pool[in] - the pool for filtered.
 * @param args[in] - other arguments.
 * @return IP address equal to value.
 */
template <typename... Args>
ip_pool_t filter(const ip_pool_t &pool, Args... args)
{
  static_assert(sizeof...(Args) <= 4,
                "filter gets 4 parameters max + ip_pool");

  ip_pool_t result;
  ipaddr_t tmp_array{args...};

  for (const ipaddr_t &ip : pool) {
    if (helper_filter(ip, tmp_array))
      result.push_back(ip);
  }
  return result;
}


#endif /* FILTER_HPP_ */
