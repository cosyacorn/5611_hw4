#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[]){

  int opt, nflag, num, **eqns, i, j;
  srand(time(NULL));

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

  if(nflag!=1) num=100;

  eqns=(int**)malloc(num*sizeof(int *));
  for(i=0;i<num;i++){
    eqns[i]=(int*)malloc((num+1)*sizeof(int));
    for(j=0;j<num+1;j++){
      eqns[i][j]=rand();
    }
  }


  for(i=0;i<num;i++){
    for(j=0;j<num+1;j++){
      printf("%d ", eqns[i][j]);
    }
    printf("\n");
  }

}
