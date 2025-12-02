#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gmp.h>

typedef struct {
	mpf_t num;
	size_t size;
	char buffer[100];
	mpf_t *temp;
	mpf_t *ptr;
}	arr;

arr create_num_range() {
	arr iter;
	mpf_init2(iter.num, 128);

	printf("Zahlenraum eingeben: ");
	
	if (fgets(iter.buffer, sizeof(iter.buffer), stdin) != NULL) {
		iter.num = mpf_set_str(iter.num, iter.buffer, 10);
		gmp_printf("Zahlenraum: %Ff\n", iter.num);
	} else {
		printf("Lesefehler\n");
		iter.num = 0;
	  }
	
	iter.size = (size_t)iter.num;
	
	return iter;		
}

arr iterate_num_range(void) {
	arr seq = create_num_range();

	mpf_t *temp = malloc(seq.num * sizeof(mpf_t));
		if (temp == NULL) {
			fprintf(stderr, "Speicher war zu voll..");
			seq.ptr = NULL;
			seq.size = 0;
			return seq;
		} else { seq.ptr = temp;
		  }
		for (size_t i = 0; i < seq.size; i++) {
			if (i <= 0) {
				seq.ptr[i] = 0; // eigentlich i = n.d.
			} else if (i > 0) {
			seq.ptr[i] = (mpf_t)mpf_pow_ui(i, i * 0.5);
			}
		}
	return seq;
}

int main() {
	arr seq = iterate_num_range();
	
	if (seq.ptr != NULL) {
		for (size_t i = 0; i < seq.size; i++) {
		gmp_printf("%Ff\n", seq.ptr[i]);
		}
	free(seq.ptr);
	}
	return 0;
}
