#include <stdio.h>

#define statusMessage printf("LINE #%d in file %s reached\n", __LINE__,__FILE__)

#define errorMessage(message) fprintf(stderr, "ERROR: %s in Line %d in %s\n", message, __LINE__, __FILE__)

#define errorMessageSimple(message) fprintf(stderr, "ERROR: %s", message)

#define message(m) printf("%s\n", m)

#define printInt(i) printf("Value is: %d",  i)

