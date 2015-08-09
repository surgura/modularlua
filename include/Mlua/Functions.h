/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Header guard
**/
#ifndef MLUA_FUNCTIONS_H
#define MLUA_FUNCTIONS_H

/**
    Include files
**/
#include "Lua.h"

#include <stdio.h>
#include <string.h>

/**
    Get the error message for the last error that occurred.

    @param  instance        The instance to request the last error for.
    @return                 The error message, or 0 if this call is not valid.
*/
const char* Mlua_GetErrorMessage(Mlua_LuaInstance* instance);

/**
    Execute a string at a lua instance.

    @param  instance        The instance to execute at.
    @param  string          The string to execute.
    @return                 How executing the function went.
            MLUA_SUCCESS    Everything went as expected.
            MLUA_ERRMEM     Allocating memory failed.
            MLUA_ERRSYNTAX  A syntax error occurred.
            MLUA_ERRRUN     A runtime error occurred.
**/
// @todo other errors
Mlua_Result Mlua_ExecuteString(Mlua_LuaInstance* instance, const char* string);

/**
    Register a function at the lua instance.

    @param  instance        The instance to register the functio nat.
    @param  name            The name of the function.
    @param  function        The function to register.
                            arg0    The user data provided in this function
                            return  The amount of values pushed on the stack by this function.
    @param  userData        Data that is passed to the registered function when it is called.
**/
void Mlua_RegisterFunction(Mlua_LuaInstance* instance, const char* name, int (*function) (void*), void* userData);

#endif // MLUA_FUNCTIONS_H
