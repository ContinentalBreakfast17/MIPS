typedef union mips_data {
	unsigned long long	i;
	double 				f;
} Data;

void check_alloc(void* p);
void check_result(int n);
void check_write(unsigned int n);
int is_prime(long long n);