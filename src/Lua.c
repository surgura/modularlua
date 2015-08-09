/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Include files
**/
#include "Mlua/Lua.h"

void Mlua_Construct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    // get instance
    Mlua_LuaInstance* instance = Mdr_GetModuleInstanceData(moduleId, instanceId);

    // create lua instance
    instance->luaState = luaL_newstate();

    // initialize error message to 0 as there is no message
    instance->errorMessage = 0;

    printf("created lua state\n");
}

/**
    Destruct function for the lua module
    @param  module          The id of this module.
    @param  instance        The id of the instance being destroyed.
**/
void Mlua_Destruct(Mdr_ModuleId moduleId, Mdr_InstanceId instanceId)
{
    // get instance
    Mlua_LuaInstance* instance = Mdr_GetModuleInstanceData(moduleId, instanceId);

    // todo destroy lua

    // free error message
    free(instance->errorMessage);
}
