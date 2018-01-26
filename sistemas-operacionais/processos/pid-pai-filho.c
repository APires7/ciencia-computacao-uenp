#include <stdio.h>
#include <unistd.h>

int main(){
    int id;

    id = fork();

    if(id != 0){
        printf("Eu sou o pai e espero pelo meu filho %d.\n", id);
        wait(0);
        printf("Meu filho acabou de terminar...vou terminar também!\n");
    }
    else {
        printf("Eu sou o filho %d e espero 10 segundos.\n", getpid());
        sleep(10);
        printf("Já esperei e vou embora...\n");
    }
}
