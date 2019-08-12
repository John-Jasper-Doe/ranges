/**
 ******************************************************************************
 * @file    utils.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    25/07/2019
 * @brief   Utilities to help.
 ******************************************************************************
 */


#ifndef UTILTS_H_
#define UTILTS_H_


#include "defs.hpp"
#include "filter.hpp"

#include <string>
#include <vector>
#include <range/v3/algorithm/sort.hpp>


/* ------------------------------------------------------------------------- */
/**
 * @brief split
 * @param str[in] - string to split.
 * @param div[in] - separator
 * @return IP address in string.
 */
ipaddr_str_t split(const std::string &str, char div);

/**
 * @brief filter_any
 * @param pool[in] - the pool for filtered.
 * @param val[in] - value.
 * @return IP address equal to value.
 */
ip_pool_t filter_any(const ip_pool_t &pool, uint32_t val);


/* ------------------------------------------------------------------------- */
/**
 * @brief Sort template
 * @param ips[in/out] - date for sort.
 */
template<typename T>
void sort(T& ips) {
  ranges::sort(ips, std::greater<typename T::value_type>());
}

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


#endif /* UTILTS_H_ */
