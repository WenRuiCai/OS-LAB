#include "lib.h"

static int j = 0;

static void user_out2string(void *arg, char *s, int l)
{
    int i;
        char * b = (char *)arg;
    // special termination call
    //if ((l==1) && (s[0] == '\0')) return;

    for (i=0; i< l; i++) {
            b[j++]=s[i];
    }
}


int fwritef(int fd, const char *fmt, ...)
{

        char buf[512] = {0};
        va_list ap;
        va_start(ap, fmt);
        user_lp_Print(user_out2string, buf, fmt, ap);
        va_end(ap);
        j = 0;
        return write(fd, buf, strlen(buf));
}
