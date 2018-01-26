#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;

    printf("Meu PID é %d. Vou criar um processo filho.\n", getpid());
    pid = fork();

    if(pid == 0){
        printf("\t\tProcesso filho criado com PID = %d.\n", getpid());
        printf("Vou ficar executando indefinidamente.\n");
        for(;;);
    }
    else{
        sleep(5);
        printf("O processo pai termina e deixa o filho órfão.\n");
        printf("Veja se o processo filho continua rodando com o comando\n");
        printf("ps\n");
    }
    exit(0);
}
