#pragma once

#include "Data.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <signal.h>
#include <sstream>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>

class Serializer
{
  private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &copy);
	~Serializer();

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};