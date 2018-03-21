#include "Settings.h"
#include <windows.h>
#include <algorithm>
#include <cwctype>
#include <Shlwapi.h>

Settings::Settings(const std::wstring &_file_path) :
	file_path(_file_path)
{
}

/*
*
* Util
*
*/

std::wstring &tolower(std::wstring &string)
{
	std::transform(
		string.begin(), string.end(),
		string.begin(),
		std::towlower);
	return string;
}

/*
*
* Getters
*
*/

std::wstring Settings::GetString(const std::wstring &name)
{
	wchar_t value_buffer[0x1000];
	GetPrivateProfileStringW(L"PCC_Properties", name.c_str(), NULL, value_buffer, ARRAYSIZE(value_buffer), file_path.c_str());
	return value_buffer;
}

bool Settings::GetBoolean(const std::wstring &name)
{
	std::wstring value_string = tolower(GetString(name));
	if (value_string.empty())
	{
		SetString(name, L"false");
		return false;
	}
	return value_string == L"true" || value_string == L"yes" || value_string == L"on";
}

int Settings::GetInt(const std::wstring &name)
{
	std::wstring value_string = GetString(name);

	int value;
	bool is_number_valid = true;

	try {
		value = std::stoi(value_string);
	}
	catch (std::invalid_argument)
	{
		is_number_valid = false;
		value = 0;
	}
	catch (std::out_of_range)
	{
		is_number_valid = false;
		value = 0;
	}

	if (!is_number_valid || value_string.empty())
		SetString(name, L"0");

	return value;
}

double Settings::GetDouble(const std::wstring &name)
{
	std::wstring value_string = GetString(name);

	double value;
	bool is_number_valid = true;

	try {
		value = std::stod(value_string);
	}
	catch (std::invalid_argument)
	{
		is_number_valid = false;
		value = 0.0;
	}
	catch (std::out_of_range)
	{
		is_number_valid = false;
		value = 0.0;
	}

	if (!is_number_valid || value_string.empty())
		SetString(name, L"0.0");

	return value;
}

/*
 *
 * Setters
 *
 */

void Settings::SetString(const std::wstring &name, const std::wstring &value)
{
	WritePrivateProfileStringW(L"PCC_Properties", name.c_str(), value.c_str(), file_path.c_str());
}

void Settings::SetBoolean(const std::wstring &name, bool value)
{
	SetString(name, (value ? L"true" : L"false"));
}

void Settings::SetInt(const std::wstring &name, int value)
{
	SetString(name, std::to_wstring(value));
}

void Settings::SetDouble(const std::wstring &name, double value)
{
	SetString(name, std::to_wstring(value));
}
