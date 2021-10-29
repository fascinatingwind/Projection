#pragma once
#ifdef UTILITY_EXPORT
#define Utility_ExportDll __declspec(dllexport)
#else
#define Utility_ExportDll __declspec(dllimport) 
#endif 
