#pragma once
#define RUNNING_WINDOWS
#include <iostream>
#include <string>
#include <algorithm>

namespace Utils {
#ifdef RUNNING_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <Shlwapi.h>
	inline std::string GetWorkingDirectory() {
		HMODULE hModule = GetModuleHandleA(nullptr);
		if (hModule) {
			char path[256];
			GetModuleFileNameA(hModule, path, sizeof(path));
			PathRemoveFileSpecA(path);
			strcat_s(path, "\\"); // new
			return std::string(path); // new
		}
		return "";
	}
#elif defined RUNNING_LINUX
#include <unistd.h>
	inline std::string GetWorkingDirectory() {
		char cwd[1024];
		if (getcwd(cwd, sizeof(cwd)) != nullptr) {
			return std::string(cwd) + std::string("/");
		}
		return "";
	}
#endif

	inline std::string GetResourceDirectory() {
		return std::string("Resources/");
	}

	inline void ReadQuotedString(std::stringstream& l_stream, std::string& l_string) {
		l_stream >> l_string;
		if (l_string.at(0) == '"') {
			while (l_string.at(l_string.length() - 1) != '"' || !l_stream.eof()) {
				std::string str;
				l_stream >> str;
				l_string.append(" " + str);
			}
		}
		l_string.erase(std::remove(l_string.begin(), l_string.end(), '"'), l_string.end());
	}
}
