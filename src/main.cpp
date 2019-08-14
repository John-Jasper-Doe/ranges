/**
 ******************************************************************************
 * @file    main.cpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The main project file is "Range".
 ******************************************************************************
 */


#include "io.hpp"
#include "filter.hpp"
#include "utils.hpp"

/* ------------------------------------------------------------------------- */
int main()
{
  ip_pool_t ip_pool;
  get_from_stream(ip_pool);
  sort(ip_pool);
  ip_print(ip_pool);

  ip_pool_t ip_pool_filtered;
  ip_pool_filtered = filter(ip_pool, static_cast<uint32_t>(1));
  ip_print(ip_pool_filtered);

  ip_pool_filtered = filter(ip_pool,
                            static_cast<uint32_t>(46),
                            static_cast<uint32_t>(70));
  ip_print(ip_pool_filtered);

  ip_pool_filtered = filter_any(ip_pool, 46);
  ip_print(ip_pool_filtered);
  return EXIT_SUCCESS;
}
