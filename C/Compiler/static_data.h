void init_static_data();
void store_static_word(unsigned int n);
void store_static_half(unsigned short n);
void store_static_byte(unsigned char n);
void store_static_space(unsigned int n, unsigned int sz);
void store_static_string(char* s);
void output_static_data(FILE* f);