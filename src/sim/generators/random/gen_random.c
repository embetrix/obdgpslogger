/** \file
 \brief Generate random data
*/

#include <stdlib.h>
#include <stdio.h>

#include "datasource.h"

const char *random_simgen_name() {
	return "Random";
}

int random_simgen_create(void **gen, const char *seed) {
	return 0;
}

void random_simgen_destroy(void *gen) {
}

int random_simgen_getvalue(void *gen, unsigned int PID, unsigned int *A, unsigned int *B, unsigned int *C, unsigned int *D) {
	if(0x00 == PID) {
		// We're capable of pulling *anything* out of our collective asses!
		*A = 0xFF;
		*B = 0xFF;
		*C = 0xFF;
		*D = 0xFE;
	} else {
		*A = (unsigned int) random();
		*B = (unsigned int) random();
		*C = (unsigned int) random();
		*D = (unsigned int) random();
	}
	return 4;
}

// Declare our obdsim_generator. This is pulled in as an extern in obdsim.c
struct obdsim_generator obdsimgen_random = {
	random_simgen_name,
	random_simgen_create,
	random_simgen_destroy,
	random_simgen_getvalue
};
