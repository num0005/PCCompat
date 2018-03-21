#pragma once
#include <string>

class Settings
{
public:
	Settings(const std::wstring &_file_path);

	// getters

	std::wstring GetString(const std::wstring &name);

	bool GetBoolean(const std::wstring &name);

	int GetInt(const std::wstring &name);

	double GetDouble(const std::wstring &name);


	// setters

	void SetString(const std::wstring &name, const std::wstring &value);

	void SetBoolean(const std::wstring &name, bool value);

	void SetInt(const std::wstring &name, int value);

	void SetDouble(const std::wstring &name, double value);

private:
	std::wstring file_path;
};

