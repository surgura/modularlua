#include <Modular/Modular.h>
#include <Mlua/Mlua.h>

int Log(void* userData)
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

    Mlua_RegisterFunction(luaInstance, "log", Log, 0);

    Mlua_Result result = Mlua_ExecuteString(luaInstance, "log(\"tsest\");");
    if (result != MLUA_SUCCESS)
    {
        if (result == MLUA_ERRMEM)
            printf("A memory error occurred.");
        else
            printf("An error occurred. %s", Mlua_GetErrorMessage(luaInstance));
    }

    Mdr_Destroy(&factory, instanceId);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
