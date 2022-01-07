/*
*
* Author : Udhayamoorthi
*
* keyboard driver
*
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evvalue[3] = {
    "You Have Released",
    "You Have Pressed",
    "You Have Repeated"
};

int main(void)
{
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event evtest;
    ssize_t n;
    int fd;

    fd = open(dev, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Not able to open %s: %s.n", dev, strerror(errno));
        return -1;
    }
    while (1) {
        n = read(fd, &evtest, sizeof evtest);
        if (n == (ssize_t)-1) {
            if (errno == EINTR)
                continue;
            else
                break;
        } else
        if (n != sizeof evtest) {
            errno = EIO;
            break;
        }
 if (evtest.type == EV_KEY && evtest.value >= 0 && evtest.value <= 0)
            printf("%s 0x%04x (%d)n", evvalue[evtest.value], (int)evtest.code, (int)evtest.code);

    }
    fflush(stdout);
    fprintf(stderr, "%s.n", strerror(errno));
    return 1;
}

