#pragma once

#define WIN32_LEAN_AND_MEAN
#define BUFF_SIZE 5

#include <iostream>
#include <vector>
#include "ClientServer.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;
int convertVecCharToInt(vector<char> vec);
