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

void station_wait_for_car(Station *station){
    pthread_mutex_lock(&station->lock);
    station->passageiros_esperando++;

    while (station->assentos_livres == 0){
        pthread_cond_wait(&station->vagao_chegou, &station->lock);
    }
    
    station->passageiros_esperando--;
    station->assentos_livres--;
    station->passageiros_embarcando++;
    pthread_mutex_unlock(&station->lock);
}

void station_on_board(Station *station){
    pthread_mutex_lock(&station->lock);

    station->passageiros_embarcando--;

    if (station->passageiros_embarcando == 0){
        pthread_cond_signal(&station->todos_sentados);
    }

    pthread_mutex_unlock(&station->lock);
}

void station_load_car(Station *station, int count){
    if (count < 0){
        count = 0;
    }    

    pthread_mutex_lock(&station->lock);
    station->assentos_livres = count;

    if (count > 0){
        pthread_cond_broadcast(&station->vagao_chegou);
    }

    while(!(station->passageiros_embarcando == 0 && (station->assentos_livres == 0 || station->passageiros_esperando == 0))){
        pthread_cond_wait(&station->todos_sentados, &station->lock);
    }

    station->assentos_livres = 0;
    pthread_mutex_unlock(&station->lock);
}