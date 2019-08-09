/**
 ******************************************************************************
 * @file    defs.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   Definition on this project.
 ******************************************************************************
 */


#include <string>
#include <vector>


using ipaddr_str_t = std::vector<std::string>;
using ip_liststr_t = std::vector<std::vector<std::string>>;
using ipaddr_t = std::vector<uint32_t>;
using ip_pool_t = std::vector<ipaddr_t>;
