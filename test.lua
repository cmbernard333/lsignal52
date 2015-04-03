#!/usr/bin/env lua
-- for osx
package.cpath = package.cpath .. ";?.dylib"
local signal = require "lsignal"
print(signal.SIGABRT)
