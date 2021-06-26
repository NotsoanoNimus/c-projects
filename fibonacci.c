#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


typedef unsigned long long ulong64;


void usage(char* appName) {
    printf("USAGE:   %s {numPlaces} [numberOnly]\n    If the [numberOnly] param is suppled, prints only the result and no text.", appName);
    exit(1);
}

ulong64 fibbo(ulong64 toPlace) {
    ulong64 f1 = 1;
    ulong64 f2 = 1;
    for(ulong64 i = 0; i < (toPlace-2); i++) {
        ulong64 f1old = f1;
        f1 += f2;
        f2 = f1old;
    }
    return f1;
}


int main(int argc, char *argv[]) {
    char *endptr = NULL;
	if(argc < 2 || argc > 3) { usage(argv[0]); }
    ulong64 lPlace = strtol(argv[1], &endptr, 0);
    if(errno || argv[1] == endptr) {
        printf("ERROR: You must enter a parseable integer.\n");
        usage(argv[0]);
    }
    lPlace--;
    ulong64 res = lPlace <= 0 ? 0 : 1;
    if(lPlace > 2) { res = fibbo(lPlace); }
    if(argv[2]) { printf("%lu ", res); }
    else { printf("%16s places into the Fibonacci sequence yields:   %lu\n", argv[1], res); }
}
