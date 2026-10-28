#include "sync_car.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void station_init(Station *station){
    int ret;
    ret = pthread_mutex_init(&station->lock, NULL);
    if (ret != 0){
        fprintf(stderr, "Erro ao iniciar o mutex: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }

    ret = pthread_cond_init(&station->vagao_chegou, NULL);
    if (ret != 0){
        fprintf(stderr, "Erro ao iniciar o vagao_chegou: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }

    ret = pthread_cond_init(&station->todos_sentados, NULL);
    if (ret != 0){
        fprintf(stderr, "Erro ao iniciar o todos_sentados: %s\n", strerror(ret));
        exit(EXIT_FAILURE);
    }

    station->assentos_livres = 0;
    station->passageiros_esperando = 0;
    station->passageiros_embarcando = 0;
}