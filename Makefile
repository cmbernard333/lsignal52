SOURCES= src/lsignal.cpp
OBJ= lsignal.o
CC= clang++
LUA_PATH= third_party/lua-5.2.3/src
LUA_INCLUDE= -I include -I $(LUA_PATH) 
LUA_LIB= -L $(LUA_PATH) -llua
# linux
CFLAGS_LINUX= -fPIC
# macosx
CFLAGS_MACOSX=
# linux
LFLAGS_LINUX= -shared 
# macosx
LFLAGS_MACOSX= -bundle -undefined dynamic_lookup
# target
TARGET= lsignal.so
# placeholder
CFLAGS= -Wall -I include -I $(LUA_PATH) -c
# DON'T LINK IF LUA IS EVENTUALLY DOING TO CALL THIS!
# LFLAGS= $(LUA_LIB) 

# ho-lee-sheet they have if statements and os checks
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin) 
	CFLAGS+=$(CFLAGS_MACOSX)
	LFLAGS+=$(LFLAGS_MACOSX)
else
	CFLAGS+=$(CFLAGS_LINUX)
	LFLAGS+=$(LFLAGS_LINUX)
endif

.PHONY: debug
debug: CFLAGS+=-DDEBUG
debug: all 

.PHONY: release
release: CFLAGS+=-O2
release: all

all: lsignal
	@echo "LFLAGS: $(LFLAGS)"
	$(CC) $(LFLAGS) -o $(TARGET) $(OBJ) 
lsignal:
	@echo "CFLAGS: $(CFLAGS)"
	$(CC) $(CFLAGS) $(SOURCES)

clean:
	rm -f $(OBJ) $(TARGET) 
