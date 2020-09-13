// main.c 
/*
	Example invocation 
	coolcrypto creature_creature_creature ]VTYJQC]aGC]_PDJ[{RJ[EEMLA

	Part 1: Find the encryption key. 
	Solution: Applying XOR to input and output shows a repeating key of ">$18".

	Part 2: Determine the encrypted output for the phrase "Smith"
	Solution: Run code with params of Smith and the key (repeated enough to match length) = mIXLV 

*/

#include <stdio.h> 

int main(int argc, char *argv[]) { 

	// Require plain text and encrypted text as parameters 
	if (argc < 3) {
		printf("Usage: coolcrypto paintext encryptedtext\n");
		return -1; 
	}

	// get plaintext length
	int idx=0; 
	while ((argv[1][idx] != '\0') && (idx < 28)) {
		idx++;
	}
	int plainLength = idx; 

	// get enctext length 
	idx=0; 
	while ((argv[1][idx] != '\0') && (idx < 28)) {
		idx++;
	}
	int encLength = idx; 

	// Stop if params are not same length 
	if (plainLength != encLength) {
		printf("Plaintext and encrypted text must be same length (got %d and %d\n", plainLength, encLength); 
		return -1;
	}

	// calc diff between ascii chars in plain and enc text 
	char delta[plainLength]; 
	char deltax[plainLength];
	for (int x=0; x<plainLength; x++) { 
		delta[x] = argv[1][x] - argv[2][x];
		deltax[x] = argv[1][x] ^ argv[2][x];
	}

	printf("P: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3c ", argv[1][x]); 
	printf("\n"); 

	printf("P: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3d ", argv[1][x]); 
	printf("\n"); 

	printf("E: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3c ", argv[2][x]); 
	printf("\n"); 

	printf("E: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3d ", argv[2][x]); 
	printf("\n"); 

	printf("D: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3d ", delta[x]); 
	printf("\n") ;

	printf("X: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3c ", deltax[x]); 
	printf("\n") ;

	printf("X: ");
	for (int x=0; x<plainLength; x++) 
		printf("%3d ", deltax[x]); 
	printf("\n") ;

}