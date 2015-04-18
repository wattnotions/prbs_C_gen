// taken from the prbs wikipedia page and modified to make an 11 bit prbs and print to file

# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

bool prbs[2047]; 

int main(void)
{
    uint16_t start_state = 0x7D0;  /* Any nonzero start state will work. */
    uint16_t lfsr = start_state;
    bool bit;
    unsigned period = 0;
	
	FILE *fp;
	fp=fopen("test.txt", "w");
	
	fflush( stdout );
    do
    {
        /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
        bit  = ((lfsr >> 0) ^ (lfsr >> 2) ) & 1;
		fprintf(fp, "%d", bit);
        lfsr =  (lfsr >> 1) | (bit << 10);
        ++period;
    } while (lfsr != start_state);
	
	
 
    
}

