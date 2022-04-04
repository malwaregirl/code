#include <unistd.h>
#include <stdlib.h>

int main(void) {
	write(1, "hello\n", 7);
	exit(0);
}