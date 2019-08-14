/**
 ******************************************************************************
 * @file    defs.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   Definition on this project.
 ******************************************************************************
 */


#ifndef DEFS_HPP_
#define DEFS_HPP_

#include <string>
#include <vector>

/** IP address in string representation. */
using ipaddr_str_t = std::vector<std::string>;

/** The pool IP address in string representation. */
using ip_liststr_t = std::vector<std::vector<std::string>>;

/** IP address by group. */
using ipaddr_t = std::vector<uint32_t>;

/** The poll IP address. */
using ip_pool_t = std::vector<ipaddr_t>;


#endif /* DEFS_HPP_ */
