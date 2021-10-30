#pragma once
#ifdef SPACE_T_EXPORT
#define SpaceT_ExportDll __declspec(dllexport)
#else
#define SpaceT_ExportDll __declspec(dllimport)
#endif 
