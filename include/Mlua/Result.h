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
    /**
        Everything went as expected.
    **/
    MLUA_SUCCESS,
    /**
        Allocing memory was needed but it failed.
    **/
    MLUA_ERRMEM,
    /**
        Syntax error in provided code.
        An error message is available.
    **/
    MLUA_ERRSYNTAX,
    /**
        Runtime error.
        An error message is available.
    **/
    MLUA_ERRRUN
} Mlua_Result;

#endif // MLUA_RESULT_H
