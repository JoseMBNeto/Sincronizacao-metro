CC     = gcc
CFLAGS = -Wall -Wextra -pthread
TARGET = sync_car

all: $(TARGET)

$(TARGET): sync_car.c sync_car-runner.c sync_car.h
	$(CC) $(CFLAGS) -o $(TARGET) sync_car.c sync_car-runner.c

clean:
	rm -f $(TARGET)

log:
	script -a evidencias.log -c "date; whoami; pwd; bash"

.PHONY: all clean log