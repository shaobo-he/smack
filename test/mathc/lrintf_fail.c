#include "smack.h"
#include <math.h>
#include <fenv.h>

// @expect error

int main(void) {
  float NaN = 0.0f / 0.0f;
  float Inf = 1.0f / 0.0f;
  float negInf = -1.0f / 0.0f;

  float a = -2.5f;
  float b = -2.4999999999f;
  float c = -2.5000000001f;
  float d = 8.3f;

  fesetround(FE_TONEARESTEVEN);
  assert(lrintf(a) == -2);
  assert(lrintf(b) == -2);
  assert(lrintf(c) == -3);
  assert(lrintf(d) == 8);

  fesetround(FE_TONEARESTAWAY);
  assert(lrintf(a) == -3);
  assert(lrintf(b) == 2);
  assert(lrintf(c) == -3);
  assert(lrintf(d) == 8);

  fesetround(FE_UPWARD);
  assert(lrintf(a) == -2);
  assert(lrintf(b) == -2);
  assert(lrintf(c) == -2);
  assert(lrintf(d) == 9);

  fesetround(FE_DOWNWARD);
  assert(lrintf(a) == -3);
  assert(lrintf(b) == -3);
  assert(lrintf(c) == -3);
  assert(lrintf(d) == 8);

  fesetround(FE_TOWARDZERO);
  assert(lrintf(a) == -2);
  assert(lrintf(b) == -2);
  assert(lrintf(c) == -2);
  assert(lrintf(d) == 8);

  assert(lrintf(0.0f) == 0);
  assert(lrintf(-0.0f) == 0);

  return 0;
}

