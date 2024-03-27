#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define MELTRIX_EXPORT __declspec(dllexport)
#else
  #define MELTRIX_EXPORT
#endif

MELTRIX_EXPORT void meltrix();
MELTRIX_EXPORT void meltrix_print_vector(const std::vector<std::string> &strings);
