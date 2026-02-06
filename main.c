#include <stdio.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>

int main() {
  struct sysinfo info;
  struct utsname system_nm;
  pid_t process_id = getpid();

  if (uname(&system_nm) == 0) {
    printf("OS: %s %s\n", system_nm.sysname, system_nm.release);
    printf("Hardware: %s\n", system_nm.machine);
  }

  if (sysinfo(&info) != 0) {
    perror("sysinfo failed");
    return 1;
  }

  printf("Uptime: %ld seconds\n", info.uptime);
  printf("Total RAM: %lu MB\n", info.totalram / 1024 / 1024);
  printf("Free RAM: %lu MB\n", info.freeram / 1024 / 1024);
  printf("Current PID: %d\n", process_id);

  printf("----------------------------------\n");
  return 0;
}
