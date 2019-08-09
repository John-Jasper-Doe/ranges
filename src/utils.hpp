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


#include <string>
#include <vector>
#include <range/v3/algorithm/sort.hpp>
#include <range/v3/algorithm/find.hpp>


/* ------------------------------------------------------------------------- */
std::vector<std::string> split(const std::string &str, char div);

/* ------------------------------------------------------------------------- */
template<typename T>
void sort(T& ips) {
    ranges::sort(ips, std::greater<typename T::value_type>());
}



#endif /* UTILTS_H_ */
