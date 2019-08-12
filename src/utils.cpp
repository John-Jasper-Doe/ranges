/**
 ******************************************************************************
 * @file    utils.cpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    25/07/2019
 * @brief   Utilities to help.
 ******************************************************************************
 */


#include "utils.hpp"


/* ------------------------------------------------------------------------- */
ipaddr_str_t split(const std::string &str, char div)
{
  std::vector<std::string> result;

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(div);

  while(stop != std::string::npos) {
    result.push_back(str.substr(start, stop - start));

    start = stop + 1;
    stop = str.find_first_of(div, start);
  }

  result.push_back(str.substr(start));

  return result;
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
