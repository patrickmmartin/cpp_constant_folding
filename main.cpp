/*
 * main.cpp
 *
 *  Created on: 1 Nov 2015
 *      Author: Patrick
 */

#include <iostream>

#define SCOPE_ERROR(A, B, C) A B C

namespace {
char const foolit[] = SCOPE_ERROR("A", "B", "C");
char const fooled[] = SCOPE_ERROR("A", "B", "C");

char const * const foolit_ptr = SCOPE_ERROR("A", "B", "C");
char const * const fooled_ptr = SCOPE_ERROR("A", "B", "C");

struct T {
	  static const char foolit[];
	  static const char fooled[];
	  static char const * foolit_ptr;
};

const char T::foolit[] = SCOPE_ERROR("A", "B", "C");
const char T::fooled[] = SCOPE_ERROR("A", "B", "C");
char const * T::foolit_ptr = SCOPE_ERROR("A", "B", "C");

struct U {
	  static const char foolit[];
	  static const char fooled[];
	  static char const * foolit_ptr;
};

const char U::foolit[] = SCOPE_ERROR("A", "B", "C");
const char U::fooled[] = SCOPE_ERROR("A", "B", "C");
char const * U::foolit_ptr = SCOPE_ERROR("A", "B", "C");

}


int main(int argc, char * argv[])
{
  std::cout << std::boolalpha <<
		  "(global) compare char arrays: " << (::foolit == ::fooled) << "\n" <<
		  "(global) compare string literals: " << (::foolit_ptr == ::fooled_ptr) << "\n" <<
		  "(global, T) compare char arrays: " << (T::foolit == ::foolit) << "\n" <<
		  "(global, T) compare string literals: " << (T::foolit_ptr == ::foolit_ptr) << "\n" <<
		  "(T) compare char arrays: " << (T::foolit == T::fooled) << "\n" <<
		  "(T, U) compare char arrays: " << (T::fooled == U::fooled) << "\n" <<
		  "(T, U) compare string literals: " << (T::foolit_ptr == U::foolit_ptr) << "\n"
		  "(global, U) compare string literals: " << (U::foolit_ptr == ::foolit_ptr) << "\n"
		  ;


}
