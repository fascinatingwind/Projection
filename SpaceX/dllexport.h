#pragma once
#ifdef SPACE_X_EXPORT
#define SpaceX_ExportDll __declspec(dllexport)
#else
#define SpaceX_ExportDll __declspec(dllimport) 
#endif 
