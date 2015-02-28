#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char *argv[]){

  int opt, nflag, z;
  unsigned long int num, i, j;
  int *primes;
  

  nflag=0;

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

  primes = malloc(sizeof(int)*num);

  for(i=2;i<num;i++)
    primes[i]=1;

  for(i=2;i<num;i++){
    if(primes[i]){
      for(j=i;i*j<num;j++){
	primes[i*j]=0;
      }
    }
  }

  z=1;

  for(i=2;i<num;i++){
    if(primes[i]){
      printf("%dth prime is %ld\n", z++, i);
    }
  }

  free(primes);
  return 0;
}
