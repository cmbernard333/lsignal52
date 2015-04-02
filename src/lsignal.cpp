#include "lsignal.h"
#include <csignal>
#include <cstdlib>
#define LUA_SIGNAL "lua_signal"
extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}
static const struct lua_signal lua_signals[] = {
    {"SIGABRT", SIGABRT},
    {"SIGFPE" , SIGFPE},
    {"SIGILL" , SIGILL},
    {"SIGINT" , SIGINT},
    {"SIGSEGV", SIGSEGV},
    {"SIGTERM", SIGTERM},
    {NULL, 0} 
};

/* prototypes */
static void lua_Signal(lua_State *L);
static void lua_Raise (lua_State *L);
static struct lua_Reg lsignal_lib[] = {
    {"signal", l_signal},
    {"raise",  l_raise},
    {NULL,NULL}
};

/* implementations */
static void lua_Signal(lua_State *L) {
    int args = gettop(L);
    return 0;
}

static void lua_Raise(lua_State *L) {
    int args = gettopt(L);
    return 0;
}

int luaopen_lsignal(lua_State *L) {
    int i = 0;
    /* register the library */
    lua_newlib(L);
    luaL_setfuncs(L,lsignal_lib,0);
    /* push on signal names into table */
    while(lua_signals[i].name != NULL) {
        /* signal table */
        lua_pushstring(L, lua_signals[i].name);
        lua_pushnumber(L, lua_signals[i].sig);
        lua_settable(L,-3);
    } 
    return 1;
}

