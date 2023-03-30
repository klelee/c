#include <stdio.h>
int print_args(char *str1, char *str2) {
	printf("%s\n", str1);
	printf("%s\n", str2);

	return 0;
}
int main(int argc, char *argv[]) {
	print_args(argv[0], argv[1]);

	return 0;
}
