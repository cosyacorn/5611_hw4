#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<ctype.h>

int main(int argc, char *argv[]){

  int opt, nflag, num, i, j, k;
  double c, **eqns, *ans, sum;
  srand48(time(NULL));


  //COMMAND LINE STUFF
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

  eqns=(double**)malloc(num*sizeof(double *));
  ans=(double*)malloc(num*sizeof(double));
  for(i=0;i<num;i++){
    eqns[i]=(double*)malloc((num+1)*sizeof(double));
    for(j=0;j<num+1;j++){
      eqns[i][j]=drand48();//random set of equations
    }
  }
  
  //PRINT EQUATIONS
  printf("The system of equations is written in matrix form as:\n");
  for(i=0;i<num;i++){
    for(j=0;j<num+1;j++){
      printf("%f ", eqns[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  //UPPER TRIANGULAR FORM
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      if(j>i){
	c=eqns[j][i]/eqns[i][i];
	for(k=0;k<num+1;k++){
	  eqns[j][k]=eqns[j][k]-c*eqns[i][k];
	}
      }
    }
  }


  //BACK SUBSTITUTION
  ans[num-1]=eqns[num-1][num]/eqns[num-1][num-1];
  
  for(i=num-2;i>=0;i--){
    sum=0;
    for(j=i+1;j<=num;j++){
      sum+=eqns[i][j]*ans[j];
    }
    ans[i]=(eqns[i][num]-sum)/eqns[i][i];
  }

  //PRINT ANSWER (column vector)
  printf("The solution to the system of equations is:\n");
  for(i=0;i<num;i++) printf("%f\n", ans[i]);

  return 0;

}
