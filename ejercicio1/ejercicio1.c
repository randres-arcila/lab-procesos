#include <stdio.h>
#include <unistd.h>

int main (void){

  int x = 100;
  printf("Empezando proceso %d\n", getpid());  
  if(fork() == 0) {
     // Codigo hijo
     x = x + x;
     printf("Este es el valor de x en el hijo: %d\n", x);
    
   }
   else {
     // Codigo padre
     x = x / 2;
     printf("Este es el valor de x en el padre: %d\n", x);
   }
   // Codijo ejecutado por ambos (para el caso)
   printf("Finalizando proceso %d\n", getpid());
   return 0;
}
