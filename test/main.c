#include <Modular/Modular.h>
#include <Mlua/Mlua.h>
#include <stdio.h>
#include <lauxlib.h>

int Log(lua_State* luaState)
{
    printf("Test log");
    return 0;
}

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId luaId;
    Mdr_Register(&factory, &luaId, sizeof(Mlua_Lua), sizeof(Mlua_LuaInstance), Mlua_Construct, Mlua_Destruct);

    Mdr_InstanceId instanceId;
    Mdr_Instantiate(&factory, &instanceId);

    Mlua_LuaInstance* luaInstance = Mdr_GetModuleInstanceData(luaId, instanceId);
    lua_State* luaState = Mlua_GetLuaState(luaInstance);

    //lua_pushlightuserdata(luaState, 0);
    lua_pushcclosure(luaState, Log, 0);
    lua_setglobal(luaState, "log");

    if (luaL_dostring(luaState, "log(\"3\")"))
    {
        printf("%s", luaL_checkstring (luaState, -1));
    }

    Mdr_Destroy(&factory, instanceId);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
