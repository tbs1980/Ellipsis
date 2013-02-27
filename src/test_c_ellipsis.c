#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"test_mt19937.h"
#include"test_hanson.h"
#include"test_kinetic_energy.h"

void print_diagnostic(int val,char* message);

int main(void)
{
	/* test the random number facilities */
	print_diagnostic(test_random_uni(),"uniform [0,1] random numbers");	
	print_diagnostic(test_random_norm(),"Normal [0,1] random numbers");	
	print_diagnostic(test_rand_save_state(),"random number generator save state");
	
	/* test CSV file IO */
	print_diagnostic(test_csv_IO(),"csv write and read");
	
	/* test Hanson's diagnostic */
	print_diagnostic(test_hanson_diag(),"Hanson's diagnostic");

	/* test guided hmc subroutines */
	print_diagnostic(test_kinetic_energy(),"kinetic_energy");
	
	return 0;
}

void print_diagnostic(int val,char* message)
{
	if(val == 0)
	{
		printf("Test: %s failed\n",message);
	}
	else
	{
		printf("Test: %s passed\n",message);
	}
}

