#include <stdio.h>
#include <sys/prctl.h>

int main(void)
{
    int vl = prctl(PR_SVE_GET_VL) & PR_SVE_VL_LEN_MASK;
    printf("VL = %d\n", vl * 8);
    return 0;
}
