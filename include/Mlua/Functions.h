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

    @param                  The instance to request the last error for.
    @reutrn                 The error message, or 0 if this call is not valid.
*/
const char* Mlua_GetErrorMessage(Mlua_LuaInstance* instance);

/**
    Execute a string at a lua instance.

    @param  instance        The instance to execute at.
    @param  string          The string to execute.
    @return                 How executing the function went.
            MDR_SUCCESS     Everything went as expected.
            MDR_EXECUTE_ERROR
                            An error has occurred while executing the string.
                            Parts of the execution string might have been processed.
                            However, there is no damage, and the instance can still be used.
                            To get the error message for this error, call Mlua_GetErrorMessage.
            MDR_EXECUTE_ERROR_ALLOC_FAIL
                            Everything is the same as with MDR_EXECUTE_ERROR, except allocating
                            memory for the error message failed.
                            The message can not be requested.
**/
// @todo other errors
Mlua_Result Mlua_ExecuteString(Mlua_LuaInstance* instance, const char* string);

#endif // MLUA_FUNCTIONS_H
