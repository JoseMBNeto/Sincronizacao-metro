# Sincronizacao-metro

### Aluno: José Milton Batista Neto
### Turma: 3A

## Sistema Operacional

Implementado e testado no **Windows + WSL2**

## Arquivos

| Arquivo | Descrição |
|---|---|
| sync_car.h | Define a struct station (chamei de Station) com um mutex, duas variáveis de condição e três contadores |
| sync_car.c | Implementação das funções station_init, station_load_car, station_wait_for_car e station_on_board |
| sync_car-runner.c | Teste fornecido pelo professor (contém a main do executável sync_car) |
| Makefile | Compila o projeto, cria o evidencias.log e limpa os arquivos gerados |
| evidencias.log | Registro das sessões de terminal |

## Como compilar

```bash
make
```

Gera o executável sync_car

## Como executar

```bash
./sync_car
```

## Comandos do Makefile

| Comando | O que faz |
|---|---|
| make | Compila e gera o executável sync_car |
| make clean | Apaga os arquivos .o e os executáveis
| make log | Inicia a gravação do terminal no evidencias.log |
