#include <ctype.h>
/**
 * Generate a hash key from a string.
 *
 * @param string           The string.
 * @return                 A hash key for the string.
 */
int string_hash(void *string)
{
	// This is the djb2 string hash function 

	int result = 5381;
	unsigned char *p;

	p = (unsigned char *) string;

	while (*p != '\0') {
		result = (result << 5) + result + *p;
		++p;
	}

	return result;
}
