/*
 * He's going crazy! What the hell is wrong with that guy!
 * Copyright (c) sh0estr1ng, 2023. The license is the same as the one in the root.
 */

#include "plugin.hpp"

void CreateFileWPatch(DWORD dwFlagsAndAttributes)
{
	// Overwrite the relevant addresses with the given flags.

	SafeWriteAddr(0xEE5305, dwFlagsAndAttributes, 1);
	SafeWriteAddr(0xEE5344, dwFlagsAndAttributes, 1);
	SafeWriteAddr(0xEE579C, dwFlagsAndAttributes, 1);
}

extern "C" __declspec(dllexport) bool NVSEPlugin_Query(const NVSEInterface* nvseInterface, PluginInfo* pluginInfo)
{
	pluginInfo->infoVersion = PluginInfo::kInfoVersion;
	pluginInfo->name = "Disc Cache Enabler";
	pluginInfo->version = 1;

	freopen("disc_cache_enabler.log", "w", stdout);

	if (nvseInterface->runtimeVersion != RUNTIME_VERSION_1_4_0_525)
	{
		printf_s("Incorrect runtime version (got %08X need at least %08X)!", nvseInterface->runtimeVersion,
				RUNTIME_VERSION_1_4_0_525);
		return false;
	}

	if (nvseInterface->isNogore)
	{
		printf_s("NoGore is not supported!");
		return false;
	}

	return true;
}

extern "C" __declspec(dllexport) bool NVSEPlugin_Load([[maybe_unused]] const NVSEInterface* nvseInterface)
{
	puts("Disc Cache Enabler loaded properly! Trying to patch game...");
	CreateFileWPatch(FILE_FLAG_OVERLAPPED | FILE_FLAG_RANDOM_ACCESS | FILE_FLAG_SEQUENTIAL_SCAN);

	return true;
}
