// PCCompat.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include "PCCompat.h"

PCC_export PCC_Evaluate()
{
	return S_OK;
}

PCC_export PCC_GetBooleanProperty(const wchar_t *a1, DWORD *a2)
{
	if (a2) {
		return E_FAIL;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_GetFloatProperty(const wchar_t *a1, double *a2)
{
	if (a2) {
		return E_FAIL;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_GetIntegerProperty(const wchar_t *a1, DWORD *a2)
{
	if (a2) {
		return E_FAIL;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_GetMessage(int a1, wchar_t *Src)
{
	return E_INVALIDARG;
}

PCC_export PCC_GetMessageCount(int *count)
{
	if (count) {
		*count = 0;
		return S_OK;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_GetStringProperty(int a1, DWORD *a2)
{
	if (a2) {
		return E_FAIL;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_GetVersionProperty(int a1, DWORD *a2)
{
	if (a2) {
		return E_FAIL;
	}
	else {
		return E_POINTER;
	}
}

PCC_export PCC_Initialize(int a1, void *Src, void *a3, int a4, int a5, int a6)
{
	return S_OK;
}

PCC_export PCC_ResetState()
{
	return S_OK;
}

PCC_export PCC_SetBooleanProperty(const wchar_t *a1, int a2)
{
	return E_FAIL;
}

PCC_export PCC_SetFloatProperty(const wchar_t *a1, int a2)
{
	return E_FAIL;
}

PCC_export PCC_SetIntegerProperty(const wchar_t *a1, int a2)
{
	return E_FAIL;
}

PCC_export PCC_SetStringProperty(const wchar_t *a1, void *Src)
{
	return E_FAIL;
}

PCC_export PCC_SetVersionProperty(const wchar_t *a1, int a2, int a3, int a4, int a5)
{
	return E_FAIL;
}

PCC_export PCC_SetVinceOptions(int a1, int a2, void *Src)
{
	return S_OK;
}

PCC_export PCC_ShowConsentUI(int a1, int a2, HWND hWnd, int a4)
{
	return S_OK;
}

PCC_export PCC_ShowMessages(HWND a1, DWORD *a2)
{
	return S_OK;
}

PCC_export PCC_ShutdownCheckpoint()
{
	return S_OK;
}

PCC_export PCC_StartupCheckpoint()
{
	return S_OK;
}

PCC_export PCC_Uninitialize()
{
	return S_OK;
}

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD     fdwReason,
	LPVOID    lpvReserved
)
{
    return TRUE;
}

