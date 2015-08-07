#include <Modular/Modular.h>
#include <ModLua/ModLua.h>

#include "ModLua/ModLua.h"

int main()
{
    Mdr_Factory factory;
    Mdr_Initialize(&factory);

    Mdr_ModuleId luaId;
    Mdr_Register(&factory, &luaId, sizeof(Mlua_Lua), sizeof(Mlua_LuaInstance), Mlua_Construct, Mlua_Destruct);

    Mdr_InstanceId instance;
    Mdr_Instantiate(&factory, &instance);

    Mdr_Destroy(&factory, instance);

    Mdr_Cleanup(&factory);

    return 0;
}
