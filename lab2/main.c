// main.c
#include <stdio.h>
#include <string.h>
#define BUF 32

#ifdef DEBUG
#define DEBUG_PRINTF(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define DEBUG_PRINTF(fmt, ...)
#endif

int global_var = 42;
static const char msg[] = "Hello from rodata";

int sum(int a, int b) { return a + b; }

int main() {
  char buf[BUF];
  snprintf(buf, sizeof(buf), "%s: %d\n", msg, global_var);
  puts(buf);
  int s = sum(10, 20);
  DEBUG_PRINTF("Debug: sum is %d\n", s);
  printf("sum=%d\n", s);
  return 0;
}
