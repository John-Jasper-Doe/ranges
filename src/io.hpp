/**
 ******************************************************************************
 * @file    io.hpp
 * @author  Max aka AVETER <aveter@bk.ru>
 * @date    20/07/2019
 * @brief   The I/O function.
 ******************************************************************************
 */

#ifndef IO_HPP_
#define IO_HPP_

#include "defs.hpp"


/* ------------------------------------------------------------------------- */
/**
 * @brief get_from_stream
 * @param data[out] - the pool IP-addres.
 * @return  state
 */
bool get_from_stream(ip_pool_t &data);

/**
 * @brief ip_print
 * @param data[in] - the pool IP-addres.
 */
void ip_print(ip_pool_t &data);


#endif /* IO_HPP_ */
