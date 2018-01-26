#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;

    printf("Meu PID é %d e vou criar um processo filho. \n", getpid());
    pid = fork();

    if(pid == 0){
        printf("\t\tMeu PID é %d e fui criado por %d. \n", getpid(), getppid());
        printf("\t\tVerifique os processos em execução com o comando ps. \n");
        sleep(10);
        printf("Processo filho terminado normalmente. \n");
        exit(0);
    }
    else {
        for(;;);
    }
}
