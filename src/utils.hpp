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


/* ------------------------------------------------------------------------- */
/**
 * @brief Sort template
 * @param ips[in/out] - date for sort.
 */
template<typename T>
void sort(T& ips) {
  ranges::sort(ips, std::greater<typename T::value_type>());
}


#endif /* UTILTS_H_ */
