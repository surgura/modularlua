/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Header guard
**/
#ifndef MLUA_LUA_H
#define MLUA_LUA_H
/**
    Include files
**/
#include <lua.h>
#include <lauxlib.h>
#include <stdlib.h>
#include <Modular/Modular.h>
#include "Result.h"

#include <stdio.h>

typedef struct
{

} Mlua_Lua;

typedef struct
{
    /**
        The lua state for this instance.
    **/
    lua_State* luaState;

    /**
        The description of the last error that occurred.
    **/
    char* errorMessage;
} Mlua_LuaInstance;

/**
    Construct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being created.
**/
void Mlua_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Destruct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mlua_Destruct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

#endif // MLUA_LUA_H
