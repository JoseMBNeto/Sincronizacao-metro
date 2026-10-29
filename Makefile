CC           = gcc
CFLAGS       = -Wall -Wextra -pthread
RUNNER_FLAGS = $(CFLAGS) -Wno-unused-parameter
TARGET       = sync_car

all: $(TARGET)

$(TARGET): sync_car.o sync_car-runner.o
	$(CC) -pthread -o $(TARGET) sync_car.o sync_car-runner.o

sync_car.o: sync_car.c sync_car.h
	$(CC) $(CFLAGS) -c sync_car.c -o sync_car.o

sync_car-runner.o: sync_car-runner.c sync_car.h
	$(CC) $(RUNNER_FLAGS) -c sync_car-runner.c -o sync_car-runner.o

clean:
	rm -f $(TARGET) *.o

log:
	script -a evidencias.log -c "date; whoami; pwd; bash"

.PHONY: all clean log