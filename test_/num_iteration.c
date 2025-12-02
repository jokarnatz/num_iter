#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	unsigned long long num;
	size_t size;
	char buffer[100];
	unsigned long long *temp;
	unsigned long long *ptr;
}	arr;

arr create_num_range() {
	arr iter;
	
	printf("Zahlenraum eingeben: ");
	
	if (fgets(iter.buffer, sizeof(iter.buffer), stdin) != NULL) {
		iter.num = strtoull(iter.buffer, NULL, 10);
		printf("Zahlenraum: %llu\n", iter.num);
	} else {
		printf("Lesefehler\n");
		iter.num = 0;
	  }
	
	iter.size = (size_t)iter.num;
	
	return iter;		
}

arr iterate_num_range(void) {
	arr seq = create_num_range();

	unsigned long long *temp = malloc(seq.num * sizeof(unsigned long long));
		if (temp == NULL) {
			fprintf(stderr, "Speicher war zu voll..");
			seq.ptr = NULL;
			seq.size = 0;
			return seq;
		} else { seq.ptr = temp;
		  }
		for (size_t i = 0; i < seq.size; i++) {
			seq.ptr[i] = (unsigned long long)pow(i, i * 0.5);
		}
	return seq;
}

int main() {
	arr seq = iterate_num_range();
	
	if (seq.ptr != NULL) {
		for (size_t i = 0; i < seq.size; i++) {
		printf("%llu", seq.ptr[i]);
		}
	free(seq.ptr);
	}
	return 0;
}
