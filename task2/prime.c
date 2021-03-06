#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>


int main(int argc, char *argv[]){

  int opt, nflag, z;
  unsigned long int num, i, j;
  int *primes;
  

  nflag=0;

  //set up command line argument
  while((opt=getopt(argc, argv, "n:"))!=-1){
    switch (opt){

    case 'n':
      num=atoi(optarg);
      nflag=1;
      break;

    case '?':
      if(optopt=='n')
	printf("Need an argument for -%c\n", optopt);
      else if(isprint(optopt))
	printf("Unknown option '-%c'\n", optopt);
      else
	printf("What's going on here?\n");
      return 1;
      
    default:
      abort();
    }
  }

  //set value for no supplied argument
  if(nflag==0) num=100;

  primes = malloc(sizeof(int)*num);


  //set all numbers to have a prime value of 1 (true)
  for(i=2;i<num;i++)
    primes[i]=1;

  for(i=2;i<num;i++){
    if(primes[i]){ //if number is prime
      for(j=i;i*j<num;j++){//loop over multiples of i
	primes[i*j]=0; //set prime value to 0 (false)
      }
    }
  }

  z=1; //counter for no of primes
  for(i=2;i<num;i++){
    if(primes[i]){
      printf("%dth prime is %ld\n", z++, i);
    }
  }

  free(primes);
  return 0;
}
