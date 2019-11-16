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
#include <range/v3/algorithm/any_of.hpp>


/* ------------------------------------------------------------------------- */
ip_pool_t filter_any(const ip_pool_t &pool, uint32_t val)
{
  ip_pool_t result;
  ranges::for_each(pool | ranges::view::filter([&val](const auto &ip) { return ranges::any_of(ip, [&val](auto byte) { return byte == val; }); }),
                   [&result](const auto &ip) { result.push_back(ip); });

  return result;
}

