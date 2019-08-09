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
bool helper_filter_any(const ipaddr_t &pool, uint32_t val)
{
  return ranges::find(pool, val) != ranges::end(pool);
}

