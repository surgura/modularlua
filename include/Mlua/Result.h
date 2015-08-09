/**
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

    @author Aart Stuurman
**/

/**
    Header guard
**/
#ifndef MLUA_RESULT_H
#define MLUA_RESULT_H

typedef enum
{
    MLUA_SUCCESS,
    MLUA_EXECUTE_ERROR,
    MLUA_ERROR_ALLOC_FAIL
} Mlua_Result;

#endif // MLUA_RESULT_H
