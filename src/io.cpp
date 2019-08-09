#include "io.hpp"
#include "utils.hpp"

#include <iostream>


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
    auto ip_part_it = ip.cbegin();
    for (; ip_part_it != ip.cend(); ++ip_part_it) {
      if (ip_part_it != ip.cbegin())
        std::cout << ".";

      std::cout << *ip_part_it;
    }
    std::cout << std::endl;
  }
}
