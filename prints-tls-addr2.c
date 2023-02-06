#include <pthread.h>
#include <stdio.h>

static __thread int x;
void* lib2_get_tls_addr(void) {
	/*x = 32;
	x += 6;*/
	void* out = 0;
	asm volatile(
	//"lea x(%%rip),%%rdi\n"

	//"lea x@tlsld(%%rip), %%rax\n"



	"lea x@tlsld(%%rip), %%rdi\n"
	"callq __tls_get_addr@plt\n"
/*
	//"lea 0x20094a(%%rip),%%rdi\n"
	"callq __tls_get_addr@plt\n"
	//"mov (%%rax),%%eax\n"
	"lea x@tlsld(%%rip), %%rdi\n"
	"sub %%rdi, %%rax"
*/
	: "=a"(out) : );
	return out;
}

void* lib2_get_tls_addr_c(void) {
	return &x;
}
