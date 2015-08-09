/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Include files
**/
#include "Mlua/Functions.h"

const char* Mlua_GetErrorMessage(Mlua_LuaInstance* instance)
{
    return instance->errorMessage;
}

Mlua_Result Mlua_ExecuteString(Mlua_LuaInstance* instance, const char* string)
{
    int result = luaL_dostring(instance->luaState, string);
    if (result != 0)
    {
        // free old error message
        free(instance->errorMessage);

        // allocate space for new error message
        const char* error = lua_tostring(instance->luaState, -1);

        instance->errorMessage = malloc(strlen(error) + 1);
        if (instance->errorMessage == 0)
            return MLUA_ERROR_ALLOC_FAIL;
        else
        {
            strcpy(instance->errorMessage, error);
            return MLUA_EXECUTE_ERROR;
        }
    }
    else
        return MLUA_SUCCESS;
}
