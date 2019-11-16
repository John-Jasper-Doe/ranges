#include "io.hpp"
#include "utils.hpp"

#include <iostream>
#include <range/v3/algorithm/for_each.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/intersperse.hpp>


/* ------------------------------------------------------------------------- */
bool get_from_stream(ip_pool_t &data)
{
  for(std::string line; std::getline(std::cin, line);) {
    std::vector<std::string> tmp_str_data(split(line, '\t'));
    std::vector<std::string> tmp_str_ip(split(tmp_str_data.at(0), '.'));

    if (tmp_str_ip.size() != 4)
      continue;

    data.push_back(
          ipaddr_t( {static_cast<uint32_t>(std::stoi(tmp_str_ip.at(0))),
                     static_cast<uint32_t>(std::stoi(tmp_str_ip.at(1))),
                     static_cast<uint32_t>(std::stoi(tmp_str_ip.at(2))),
                     static_cast<uint32_t>(std::stoi(tmp_str_ip.at(3)))
                    } ));
  }
  return true;
}

/* ------------------------------------------------------------------------- */
void ip_print(ip_pool_t &data)
{
  for (const auto &ip : data) {
    ranges::for_each(ip | ranges::view::transform([](const auto &i) { return std::to_string(i); }) | ranges::view::intersperse("."),
                     [](auto ip_part) { std::cout << ip_part; });

    std::cout << std::endl;
  }
}
