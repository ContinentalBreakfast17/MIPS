/*
	Terminates program if the allocation failed
*/
void check_alloc(void* p) {
	if(p == NULL) {
		printf("Error allocating space\n");
		exit(1);
	}
}

/*
    Terminates program if result is not 0, useful for checking failed mutex initializations
*/
void check_result(int n) {
    if(n != 0) {
        printf("Error doing somethin\n");
        exit(1);
    }
}

/*
	The following 3 functions taken from http://www.sanfoundry.com/c-program-implement-rabin-miller-primality-test-check-number-prime/
	Used for primality testing

/* 
 * calculates (a * b) % c taking into account that a * b might overflow 
 */
long long mulmod(long long a, long long b, long long mod) {
    long long x = 0,y = a % mod;
    while (b > 0) {
        if (b % 2 == 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/* 
 * modular exponentiation
 */
long long modulo(long long base, long long exponent, long long mod) {
    long long x = 1;
    long long y = base;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin Primality test, iteration signifies the accuracy
 */
int Miller(long long p,int iteration) {
    int i;
    long long s;
    if (p < 2)
        return 0;
    if (p != 2 && p % 2==0)
        return 0;
     s = p - 1;
    while (s % 2 == 0)
        s /= 2;
    for (i = 0; i < iteration; i++) {
        long long a = rand() % (p - 1) + 1, temp = s;
        long long mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
            return 0;
    }
    return 1;
}

/*
	Returns whether the number is prime
*/
int is_prime(long long n) {
	return Miller(n, 5);
}