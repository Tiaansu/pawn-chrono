#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"

logprintf_t logprintf;

AMX_NATIVE_INFO nativeList[] = {
    { "Now", Natives::Now },
    { "TimeFormat", Natives::TimeFormat },
    { "TimeParse", Natives::TimeParse },
    { "DurationParse", Natives::DurationParse },
    { "DurationParseSeconds", Natives::DurationParseSeconds },
    { 0, 0 }
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
    return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, nativeList, -1);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    logprintf("Chrono plugin unloaded.");
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
    return AMX_ERR_NONE;
}
