/**
 ******************************************************************************
 * @file    filter.cpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The filter function.
 ******************************************************************************
 */



#include "filter.hpp"
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/filter.hpp>


/* ------------------------------------------------------------------------- */
ip_pool_t filter_any(const ip_pool_t &pool, uint32_t val)
{
  ip_pool_t result;
  for (const ipaddr_t &ip : pool)
    ranges::for_each(ip | ranges::view::filter([&](uint32_t i) { return i == val; }), [&](auto) { result.push_back(ip); });

  return result;
}

