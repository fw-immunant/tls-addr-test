#include <stdio.h>
#include <stdint.h>

extern void* lib_get_tls_addr_c(void);
extern void* lib_get_tls_addr(void);

extern void* lib2_get_tls_addr_c(void);

typedef struct dl_tls_index
{
  uint64_t ti_module;
  uint64_t ti_offset;
} tls_index;

void* __tls_get_addr(tls_index*);

int main(int argc, char** argv) {
	printf("c: %16p\n", lib_get_tls_addr_c());
	printf("asm: %16p\n", lib_get_tls_addr());
	
	tls_index module1var0 = {
		.ti_module = 1,
		.ti_offset = 0,
	};
	void* addr = __tls_get_addr(&module1var0);

	printf("fake C: %16p\n", addr);

	printf("lib2: %16p\n", lib2_get_tls_addr_c());

	tls_index module2var0 = {
		.ti_module = 2,
		.ti_offset = 0,
	};
	addr = __tls_get_addr(&module2var0);

	printf("lib2 fake C: %16p\n", addr);
	return 0;
}