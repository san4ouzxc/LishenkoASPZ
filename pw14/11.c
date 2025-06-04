#include <stdio.h>
#include <stdlib.h>
#include <sys/event.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct {
    int id;
    int count;
} timer_info_t;

int main() {
    int kq = kqueue();
    if (kq == -1) {
        perror("kqueue");
        return 1;
    }

    struct kevent kev;
    timer_info_t tinfo = {1, 0};

    EV_SET(&kev, 1, EVFILT_TIMER, EV_ADD | EV_ENABLE, 0, 1000, &tinfo);

    if (kevent(kq, &kev, 1, NULL, 0, NULL) == -1) {
        perror("kevent");
        return 1;
    }

    while (1) {
        struct kevent event;
        int nev = kevent(kq, NULL, 0, &event, 1, NULL);
        if (nev == -1) {
            perror("kevent");
            break;
        }

        timer_info_t *info = (timer_info_t *)event.udata;
        info->count++;
        printf("Таймер #%d спрацював %d разів\n", info->id, info->count);

        if (info->count >= 5) {
            printf("Завершення після 5 спрацьовувань.\n");
            break;
        }
    }

    close(kq);
    return 0;
}
