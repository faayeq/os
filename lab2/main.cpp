// main.c
#include <stdio.h>
#include <string.h>
#define BUF 32

int global_var = 42;                           // goes to .data
static const char msg[] = "Hello from rodata"; // .rodata

int sum(int a, int b) { return a + b; }

int main() {
  char buf[BUF]; // buf in stack (.bss/stack)
  snprintf(buf, sizeof(buf), "%s: %d\n", msg, global_var);
  puts(buf);
  int s = sum(10, 20);
  printf("sum=%d\n", s);
  return 0;
}
