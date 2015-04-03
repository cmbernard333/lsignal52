SOURCES=src/lsignal.cpp
OBJ=lsignal.o
CC=clang++
LUA_PATH=third_party/lua-5.2.4/src
CFLAGS=-fPIC -Wall -I include -I $(LUA_PATH) -c
LFLAGS=-shared -L $(LUA_PATH) -llua 
TARGET=lsignal.so

.PHONY: debug
debug: CFLAGS+=-DDEBUG
debug: all 

.PHONY: release
release: CFLAGS+=-O2
release: all

all: lsignal
	$(CC) $(LFLAGS) -o $(TARGET) $(OBJ) 
lsignal:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f $(OBJ) $(TARGET) 
