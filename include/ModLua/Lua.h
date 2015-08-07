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
#include <lua.h>

#include <stdlib.h>

typedef struct
{

} Mlua_Lua;

typedef struct
{
    lua_State* luaState;
} Mlua_LuaInstance;

/**
    Construct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being created.
**/
void Mlua_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    Mlua_LuaInstance* instance = Mdr_GetModuleInstanceData(moduleId, instanceId);
    instance->luaState = luaL_newstate();
    printf("created lua state");
}

/**
    Destruct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mlua_Destruct(Mdr_ModuleId module, Mdr_InstanceId instance)
{
}

#endif // MLUA_LUA_H
