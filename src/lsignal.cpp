#include "lsignal.h"
#include <csignal>
#include <cstdlib>
#define LUA_SIGNAL "lua_signal"
#ifdef DEBUG
#include <iostream>
#endif
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

static const struct lua_signal lua_signals[] = {{"SIGABRT", SIGABRT},
                                                {"SIGFPE", SIGFPE},
                                                {"SIGILL", SIGILL},
                                                {"SIGINT", SIGINT},
                                                {"SIGSEGV", SIGSEGV},
                                                {"SIGTERM", SIGTERM},
                                                {NULL, 0}};

/* prototypes */
static int lua_Signal(lua_State *L);
static int lua_Raise(lua_State *L);
static const struct luaL_Reg lsignal_lib[] = {
    {"signal", lua_Signal}, {"raise", lua_Raise}, {NULL, NULL}};

/* implementations */
static int lua_Signal(lua_State *L) {
  int args = lua_gettop(L);
  return 0;
}

static int lua_Raise(lua_State *L) {
  int args = lua_gettop(L);
  return 0;
}

int luaopen_lsignal(lua_State *L) {
  int i = 0;
  /* register the library */
  lua_newtable(L);
  luaL_setfuncs(L, lsignal_lib, 0);
  /* push another named table */
  lua_pushstring(L, LUA_SIGNAL);
  lua_newtable(L);
  /* push on signal names into table */
  while (lua_signals[i].name != NULL) {
    /* signal table */
	#ifdef DEBUG
	  std::cout<<"Adding symbol "<<lua_signals[i].name<<","<<lua_signals[i].sig<<std::endl;
	#endif
    lua_pushstring(L, lua_signals[i].name);
    lua_pushnumber(L, lua_signals[i].sig);
    lua_settable(L, -3);
	i++;
  }
  return 1;
}
}
