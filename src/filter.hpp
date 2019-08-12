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



