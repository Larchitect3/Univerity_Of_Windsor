#include <stdio.h>
#include <math.h>
/* don't forget "gcc -lm" switch to compile */

/* use DEBUG 1 if you want view debug steps for testing, 
   or 0 if you want production */

#define DEBUG 0

int main()
{
	int case_counter = 1;
	double n;
	double x;

	scanf("%lf", &n);
	if (DEBUG) fprintf(stderr, "first input: [%lf]\n", n);
	while(n > 0)
	{
		if (DEBUG) fprintf(stderr, "inside loop...\n");
		x = ceil(log2(n)); /* log is base 2 */
		if (DEBUG) fprintf(stderr, "x is [%lf]\n", x);
		if (case_counter > 1) printf("\n");
		printf("Case %d: %d", case_counter++, (int)(x));
		scanf("%lf", &n);
		if (DEBUG) fprintf(stderr, "input: [%lf]\n", n);
	}
	return 0;
}

