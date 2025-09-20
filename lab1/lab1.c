#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t proc_id = getpid();
  printf("starting cpu hog with this damn process id: %d\n", proc_id);

  while (1) {
    int bullshit_num = 0;
    for (long i = 0; i < 10000000; i++) {
      bullshit_num++;
    }
  }

  return 0;
}
