#include <stdio.h>
#include <stdint.h>

typedef unsigned long long u64;

/* 0! .. 20! fit in 64-bit; 21! overflows. */
static const u64 FACT_LUT[21] = {
    1ULL,                       /* 0!  */
    1ULL,                       /* 1!  */
    2ULL,                       /* 2!  */
    6ULL,                       /* 3!  */
    24ULL,                      /* 4!  */
    120ULL,                     /* 5!  */
    720ULL,                     /* 6!  */
    5040ULL,                    /* 7!  */
    40320ULL,                   /* 8!  */
    362880ULL,                  /* 9!  */
    3628800ULL,                 /* 10! */
    39916800ULL,                /* 11! */
    479001600ULL,               /* 12! */
    6227020800ULL,              /* 13! */
    87178291200ULL,             /* 14! */
    1307674368000ULL,           /* 15! */
    20922789888000ULL,          /* 16! */
    355687428096000ULL,         /* 17! */
    6402373705728000ULL,        /* 18! */
    121645100408832000ULL,      /* 19! */
    2432902008176640000ULL      /* 20! */
};

static u64 factorial_iterative(unsigned n) {
    if (n < 2) return 1ULL;
    u64 acc = 1ULL;
    for (unsigned i = 2; i <= n; ++i) {
        acc *= (u64)i;
    }
    return acc;
}

int main(void) {
    int failures = 0;

    /* Check 0..20 against the LUT */
    for (unsigned n = 0; n <= 20; ++n) {
        u64 got = factorial_iterative(n);
        u64 exp = FACT_LUT[n];
        if (got != exp) {
            printf("FAIL: %u! got=%llu exp=%llu\n", n, (unsigned long long)got, (unsigned long long)exp);
            failures++;
        } else {
            printf("OK  : %u! = %llu\n", n, (unsigned long long)got);
        }
    }

    /* Show that 21! will overflow 64-bit if we tried to compute it here. */
    puts("Note: 21! exceeds 64-bit unsigned range; we’ll add a safe-guarded version next step.");

    return failures ? 1 : 0;
}
