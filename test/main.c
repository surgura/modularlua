#include <Modular/Modular.h>
#include <Mlua/Mlua.h>

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId luaId;
    Mdr_Register(&factory, &luaId, sizeof(Mlua_Lua), sizeof(Mlua_LuaInstance), Mlua_Construct, Mlua_Destruct);

    Mdr_InstanceId instanceId;
    Mdr_Instantiate(&factory, &instanceId);
    Mlua_LuaInstance* luaInstance = Mdr_GetModuleInstanceData(luaId, instanceId);
    if (Mlua_ExecuteString(luaInstance, "print(\"test\");") == MLUA_EXECUTE_ERROR)
        printf("%s", Mlua_GetErrorMessage(luaInstance));

    Mdr_Destroy(&factory, instanceId);

    Mdr_Cleanup(&factory);

    while(1){}

    return 0;
}
