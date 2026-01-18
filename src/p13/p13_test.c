#include <stdio.h>

int romanToInt(char* s);

int main() {
	struct {
		char* s;
		int   want;
	} tests[] = {
		{"III", 3},
		{"LVIII", 58},
		{"MCMXCIV", 1994},
	};

	int num_tests = sizeof(tests) / sizeof(tests[0]);
	for (int i = 0; i < num_tests; i++) {
		int got = romanToInt(tests[i].s);
		if (tests[i].want != got) {
			printf("want %d, got %d\n", tests[i].want, got);
			return 1;
		}
	}

	return 0;
}
