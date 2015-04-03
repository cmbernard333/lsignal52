#!/usr/bin/env lua
-- for osx
package.cpath = package.cpath .. ";?.dylib"
local signal = require "lsignal"
for k,v in pairs(signal) do
    print (k,v)
end
