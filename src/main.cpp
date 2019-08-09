/**
 ******************************************************************************
 * @file    main.cpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The main project file is "Range".
 ******************************************************************************
 */


#include "io.hpp"
#include "utils.hpp"
#include "range/v3/all.hpp"

auto filter_accept_check_any(const ipaddr_t &a) {
  return ranges::find(a, static_cast<uint32_t>(46)) != ranges::end(a);
}

auto filter_accept_check_any2(const ipaddr_t &a) {
  return ranges::find(a, static_cast<uint32_t>(1)) == ranges::begin(a);
}


auto filter_accept_check_any3(const ipaddr_t &a) {
  return ranges::equal(a, static_cast<uint32_t>(1)) == ranges::begin(a);
}


int main()
{
  ip_pool_t ip_pool;
  get_from_stream(ip_pool);
  sort(ip_pool);

  ip_pool_t dd;
  for (ipaddr_t &ip : ip_pool) {
    if (filter_accept_check_any2(ip))
      dd.push_back(ip);
  }

  ip_print(dd);
  return EXIT_SUCCESS;
}
