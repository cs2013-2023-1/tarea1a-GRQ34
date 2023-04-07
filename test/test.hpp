#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../tarea/foo.h"
#include <cmath>

using namespace std;

auto random(int x, int y){ return rand() % (y-x+1) + x;}
bool is_equal(float a, float b, float epsilon = 0.001f){
    return fabs(a - b) < epsilon;
}