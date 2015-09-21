/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "vector.h"

/* Define what our struct is */
struct vector_t {
	size_t size;
	int *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Create a new vector */
vector_t *vector_new() {
	vector_t *retval;  

	/* First, we need to allocate the memory for the struct */
	retval = malloc(1 * sizeof(vector_t));

	/* Check our return value to make sure we got memory */
	if(retval == NULL)
                allocation_failed();
	 
	/* Now we need to initialize our data */
	retval->size = 1;
	retval->data = malloc(retval->size * sizeof(int));

	/* Check our return value to make sure we got memory */
	if(retval->data == NULL) {
		free(retval);
                allocation_failed();
	}

	retval->data[0] = 0;
	
	/* and return... */
	return retval;
}

/* Free up the memory allocated for the passed vector */
void vector_delete(vector_t *v) {
	/* Remember, you need to free up ALL the memory that is allocated */	

	free(v);

	/* ADD CODE HERE */

}

/* Return the value in the vector */
int vector_get(vector_t *v, size_t loc) {

	/* If we are passed a NULL pointer for our vector, complain about it and
         * exit.
	 */
	if(v == NULL) {
		fprintf(stderr, "vector_get: passed a NULL vector.\n");
                abort();
	}

	/* If the requested location is higher than we have allocated, return 0.
	 * Otherwise, return what is in the passed location.
	 */
	if(loc < v->size) {
		return v->data[loc];
	} else {
		return 0;
	}
}

/* Set a value in the vector. If the extra memory allocation fails, call
   allocation_failed(). */
void vector_set(vector_t *v, size_t loc, int value) {
	/* What do you need to do if the location is greater than the size we have
	 * allocated?  Remember that unset locations should contain a value of 0.
	 */
	 if(loc >= v->size){
	 	v->size = loc + 1;
	 	v->data = realloc(v->data,v->size*sizeof(int));
	 	v->data[loc] = value;
	 }else{
	 	v->data[loc] = value;
	 }

}


int main(int argc, char **argv) {
	vector_t *v;
	
	printf("Calling vector_new()\n");
	v = vector_new();
	
	printf("Calling vector_delete()\n");
	vector_delete(v);
	
	printf("vector_new() again\n");
	v = vector_new();

	printf("These should all return 0 (vector_get()): ");
	printf("%d ", vector_get(v, 0));
	printf("%d ", vector_get(v, 1));
	printf("%d\n", vector_get(v, 2));

	printf("Doing a bunch of vector_set()s\n");
	vector_set(v, 0, 98);
	vector_set(v, 11, 15);
	vector_set(v, 15, -23);
	vector_set(v, 24, 65);
    vector_set(v, 500, 3);
	vector_set(v, 12, -123);
	vector_set(v, 15, 21);
	vector_set(v, 25, 43);

	printf("These should be equal:\n");
	printf("98 = %d\n", vector_get(v, 0));
	printf("15 = %d\n", vector_get(v, 11));
	printf("65 = %d\n", vector_get(v, 24));
	printf("-123 = %d\n", vector_get(v, 12));
	printf("21 = %d\n", vector_get(v, 15));
	printf("43 = %d\n", vector_get(v, 25));
    printf("0 = %d\n", vector_get(v, 23));
    printf("0 = %d\n", vector_get(v, 1));
    printf("0 = %d\n", vector_get(v, 501));
    printf("3 = %d\n", vector_get(v, 500));

    vector_delete(v);

	printf("Test complete.\n");
	
	return 0;
}

 


