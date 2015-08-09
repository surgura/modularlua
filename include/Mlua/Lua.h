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
#include <Modular/Modular.h>

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
**///@todo errors
void Mlua_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Destruct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**///@todo errors
void Mlua_Destruct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId);

/**
    Get the lua state from an instance
    @param  instance        The instance to get it from
    @return                 The lua state
**/
lua_State* Mlua_GetLuaState(Mlua_LuaInstance* instance);

#endif // MLUA_LUA_H
