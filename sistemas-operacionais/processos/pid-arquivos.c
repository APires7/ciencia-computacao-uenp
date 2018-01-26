#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int pid, fd;
    char *pidnum, c;
    int i, r;

    printf("Meu PID é %d. \n", getpid());
    printf("Vou gravar meu numero PID no arquivo meupid. \n");

    if((fd=open("meupid", O_CREAT | O_RDWR | O_TRUNC,S_IRWXU)) == -1){
        printf("Nao consegui criar o arquivo meupid. \n");
        exit(-1);
    }

    sprintf(pidnum, "%d surpresa", getpid());
    if(write(fd, pidnum, 15) == -1){
        printf("Nao consegui escrever no arquivo.");
        exit(-1);
    }

    printf("Ja escrevi o numero. Fechando o arquivo. \n");
    close(fd);
    printf("Vou abrir o arquivo novamente para leitura. \n");

    if((fd=open("meupid", O_RDONLY,S_IRWXU)) == -1){
        printf("Nao foi possivel abrir o arquivo. \n");
        exit(-1);
    }

    printf("Vou criar um processo filho agora. \n");
    pid = fork();
    if(pid == -1){
        perror("Nao foi possivel criar um processo filho. \n");
        exit(-1);
    }
    else if (pid == 0){
        printf("\t\tSou o processo filho. Meu PID = %d. \n", getpid());
        printf("\t\tVou ler o arquivo que ja estava aberto pelo processo pai antes. \n");
        printf("\t\tDa minha criacao e que eu herdei. \n");
        for(i=1; i<=5; i++){
           if(read(fd, &c, 1) == 1){
           printf("Nao consegui ler o arquivo...");
           exit(-1);
           }
           printf("O numero que foi lido no arquivo e %c. \n", c);
        }
        printf("\t\tFechando o arquivo e terminando minha execucao...\n");
        close(fd);
        exit(1);
    }
    else {
        wait();
        printf("O processo filho criado tinha o PID numero %d, \n", pid);
        printf("Vou ler o arquivo meupid. \n");
        while((r = read(fd, &c, 1)) != 0){
            if( r == -1){
                printf("Impossivel ler o arquivo.");
                exit(-1);
            }
            printf("Consegui ler => %c\n", c);
        }
        printf("Meu filho leu o numero do PID no arquivo e mexeu no meu ponteiro.\n");
        printf("Terminando minha execucao. \n");
        close(fd);
    }
    exit(0);
}
