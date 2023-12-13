/*
 * He's going crazy! What the hell is wrong with that guy!
 * Copyright (c) sh0estr1ng, 2023. The license is the same as the one in the root.
 */

#pragma once

#include <cstdio>
#include <cstdint>

#define UInt8 uint8_t
#define UInt16 uint16_t
#define UInt32 uint32_t

#include <nvse/nvse_version.h>

#include <nvse/PluginAPI.h>
#include <nvse_memory_kit/SafeWrite.h>

/*
 * The patch to enable disc caching.
 */
void CreateFileWPatch();
