#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <grp.h>

int main() {
    uid_t uid = getuid();
    gid_t gid = getgid();

    printf("UID: %d\n", uid);
    printf("GID: %d\n", gid);

    int ngroups = 0;
    getgroups(0, NULL); 
    getgrouplist("lilpeep", gid, NULL, &ngroups);
    gid_t groups[ngroups];
    getgroups(ngroups, groups);

    printf("Groups (%d):\n", ngroups);
    for (int i = 0; i < ngroups; i++) {
        printf("  %d\n", groups[i]);
    }

    return 0;
}
