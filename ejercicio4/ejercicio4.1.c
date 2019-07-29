#include <stdio.h>
#include <unistd.h>

int main (void){

  //int *status_code;
  printf("Padre -> \n");
  switch(fork()) {
    case 0:
      // Codigo del proceso hijo
      execl("/bin/ls", "/bin/ls", ".", NULL);
    case -1: 
      // Error
      printf("ERROR!!!");
      break;
  }
  //wait(status_code); // Ensayarlo sin comentarlo y comentandolo a ver que pasa
  //printf("Esto no lo ejecutara el hijo\n");
  return 0;
}