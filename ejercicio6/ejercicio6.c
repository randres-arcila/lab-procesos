#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int status;
    pid_t wc;
    
    if (rc == 0){
        printf("soy el hijo %d y el padre espera hasta que reaccione\n", (int)getpid());
        sleep(2);
        printf("estoy listo\n");
    }else{
        printf("Soy el padre, esperando hijo %d \n", rc);
        do{
            wc = waitpid(rc, &status, WNOHANG);
            if (wc == -1)
                perror("waitpid() error");
            else if (wc == 0){
                printf("hijo sin reaccionar\n");
                sleep(2);
            }else{
                if (WIFEXITED(status))
                    printf("hijo reaccionó\n");
                }
        } while (wc == 0);
    }
    return 0;
}