#include <stdio.h>
#include <sys/time.h>

long get_time_in_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000;
}

int main() {
    long start_time = get_time_in_ms();

    for (volatile long i = 0; i < 100000000; i++); 

    long end_time = get_time_in_ms();
    long duration = end_time - start_time;

    printf("Час виконання: %ld мс\n", duration);

    return 0;
}
