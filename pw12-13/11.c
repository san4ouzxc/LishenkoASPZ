#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>
#include <stdatomic.h>

volatile sig_atomic_t sigusr1_received = 0;
volatile sig_atomic_t sigusr2_received = 0;

void* handle_sigusr1(void* arg) {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR1);

    siginfo_t info;
    int sig = sigwaitinfo(&set, &info);
    if (sig == SIGUSR1) {
        printf("Потік 1: Отримано SIGUSR1\n");
        sigusr1_received = 1;
    }

    pthread_exit(NULL);
}

void* handle_sigusr2(void* arg) {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGUSR2);

    siginfo_t info;
    int sig = sigwaitinfo(&set, &info);
    if (sig == SIGUSR2) {
        printf("Потік 2: Отримано SIGUSR2\n");
        sigusr2_received = 1;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    sigset_t all_signals;
    sigemptyset(&all_signals);
    sigaddset(&all_signals, SIGUSR1);
    sigaddset(&all_signals, SIGUSR2);
    pthread_sigmask(SIG_BLOCK, &all_signals, NULL);

    pthread_create(&t1, NULL, handle_sigusr1, NULL);
    pthread_create(&t2, NULL, handle_sigusr2, NULL);

    sleep(1);
    kill(getpid(), SIGUSR1);
    sleep(1);
    kill(getpid(), SIGUSR2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Обидва сигнали оброблено. Завершення.\n");
    return 0;
}
