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

/**
    Pop the error message from the lua stack, and copy it to the instance.
    @param  instance        The instance to do this for
    @return                 Whether it executed successfully.
            MLUA_SUCCESS    Everything went fine.
            MLUA_ERRMEM     Could not allocate memory for the string.
**/
Mlua_Result RetrieveErrorMessage(Mlua_LuaInstance* instance)
{
    // free old error message
    free(instance->errorMessage);

    // allocate space for new error message
    const char* error = lua_tostring(instance->luaState, -1);

    // allocate space for error message
    instance->errorMessage = malloc(strlen(error) + 1);

    // check if space was successfully allocated
    if (instance->errorMessage == 0)
        return MLUA_ERRMEM;
    else
    {
        // copy error message
        strcpy(instance->errorMessage, error);

        // pop error message from stack
        lua_pop(instance->luaState, 1);

        return MLUA_SUCCESS;
    }
}

const char* Mlua_GetErrorMessage(Mlua_LuaInstance* instance)
{
    return instance->errorMessage;
}

Mlua_Result Mlua_ExecuteString(Mlua_LuaInstance* instance, const char* string)
{
    // load the string into lua
    int loadResult = luaL_loadstring(instance->luaState, string);

    // check if an error occurred
    if (loadResult != 0)
    {
        // if a syntax error occurred
        if (loadResult == LUA_ERRSYNTAX)
        {
            // get error message from the stack
            if (RetrieveErrorMessage(instance) == MLUA_ERRMEM)
                return MLUA_ERRMEM; // there was not enough memory for the message
            return MLUA_ERRSYNTAX;
        }
        else
        {
            // it was a memory error
            return MLUA_ERRMEM;
        }
    }

    // call the function
    int runResult = lua_pcall(instance->luaState, 0, LUA_MULTRET, 0);

    // if it failed
    if (runResult != 0)
    {
        // is it a runtime error?
        if (runResult == LUA_ERRRUN)
        {
            if (RetrieveErrorMessage(instance) == MLUA_ERRMEM)
                return MLUA_ERRMEM;
            return MLUA_ERRRUN;
        }
        else
        {
            // it was a memory error
            return MLUA_ERRMEM;
        }
    }

    return MLUA_SUCCESS;
}

/**
    Is called when a user registered function is called.
    Expects the user defined function is the on the stack,
    next to the user data.
    @param  luaState        The lua state registered at.
**/
int OnFunctionCall(lua_State* luaState)
{
    // get user data
    int (*function) (void*) = lua_touserdata(luaState, lua_upvalueindex(1));

    // get the function
    void* userData = lua_touserdata(luaState, lua_upvalueindex(2));

    // call the function
    return function(userData);
}

void Mlua_RegisterFunction(Mlua_LuaInstance* instance, const char* name, int (*function) (void*), void* userData)
{
    // push the function on the stack
    lua_pushlightuserdata(instance->luaState, function);

    // push the user data on the stack
    lua_pushlightuserdata(instance->luaState, userData);

    // push a lua closure on the stack
    lua_pushcclosure(instance->luaState, OnFunctionCall, 2);

    // set the closure as a global variable
    lua_setglobal(instance->luaState, name);
}
