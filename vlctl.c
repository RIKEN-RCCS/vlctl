#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/prctl.h>

int vl_list[] = { 128, 256, 512 };

void usage()
{
    fprintf(stderr,
            "usage: vlctl <length> command [ args ... ]\n"
            "<length> = 128 | 256 | 512.\n");
}

int check_vl(int vl)
{
    for (int i = 0; i < sizeof(vl_list) / sizeof(vl_list[0]); i++) {
        if (vl == vl_list[i]) return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        usage();
        exit(1);
    }

    int vl = atoi(argv[1]);
    if (check_vl(vl)) {
        fprintf(stderr, "invalid vector length: %s\n", argv[1]);
        usage();
        exit(1);
    }

    unsigned long vl_byte = vl / 8;
    char **command_arg = &argv[2];
    int ret;

    ret = prctl(PR_SVE_SET_VL, vl_byte | PR_SVE_SET_VL_ONEXEC);
    if (ret < 0) {
        perror("prctl(PR_SVE_SET_VL, vl_byte | PR_SVE_SET_VL_ONEXEC)");
        exit(1);
    }

    execvp(*command_arg, command_arg);

    /* excecuton failed */
    perror(*command_arg);
    return 1;
}
