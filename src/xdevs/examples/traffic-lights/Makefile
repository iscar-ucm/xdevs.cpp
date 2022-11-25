CC = g++
CFLAGS = -std=c++11 -Wall -g -O3
#CFLAGS = -std=c++11 -Wall -O3


XDEVS_SRC = $(shell find ../../core -type f -name '*.cpp')
XDEVS_OBJS = $(XDEVS_SRC:.cpp=.o)
#XDEVS_LIB_DIR = ../../../../lib

SRC_BASE = Generator.cpp Integer.cpp Light.cpp
SRC_TRA = main_traffic.cpp TrafficLights.cpp
OBJ_BASE = $(SRC_BASE:.cpp=.o)
OBJ_TRA = $(SRC_TRA:.cpp=.o)

all: main_traffic

main_traffic: $(XDEVS_OBJS) $(OBJ_BASE) $(OBJ_TRA)
	${CC} ${CFLAGS} $^ -o $@

%.o: %.cpp
	${CC} -c ${CFLAGS} $< -o $@

.PHONY: clean
clean:
	rm -f $(XDEVS_OBJS) $(OBJ_BASE) $(OBJ_TRA) main_traffic

uninstall:
	rm -f main_traffic
