#ifndef SYNC_CAR_H
#define SYNC_CAR_H
#include <pthread.h>

typedef struct station {
    pthread_mutex_t lock;
    pthread_cond_t vagao_chegou;
    pthread_cond_t todos_sentados;
    int assentos_livres;
    int passageiros_esperando;
    int passageiros_embarcando;
} Station;

void station_init(Station *station);
void station_load_car(Station *station, int count);
void station_wait_for_car(Station *station);
void station_on_board(Station *station);

#endif