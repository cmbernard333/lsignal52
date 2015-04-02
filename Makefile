SOURCES=src/lsignal.cpp
OBJ=lsignal.o
CC=clang
CFLAGS=-Wall -I include -I include/third_party/lua-5.2.3 -c
LFLAGS=-shared -L third_party/lua-5.2.3 -llua 
TARGET=lsignal.so

all: lsignal
	$(CC) $(LFLAGS) -o $(TARGET) $(OBJ) 
lsignal:
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f $(OBJ) $(TARGET) 
