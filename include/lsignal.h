#ifndef __SIGNAL_HANDLER_H__
#include <csignal>
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

typedef void (*lua_SignalFunc)(int);

struct lua_signal {
    const char *name; /* name of the signal */
    int sig; /* the signal */
};

#endif
