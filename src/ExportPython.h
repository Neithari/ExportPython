#pragma once
#include <string>
#include <vector>

class ExportPython
{
public:
	ExportPython() = default;

	// Plain function name, without def,() or :
	// Function body without leading space
	// Plain parameters without , or ()
	void addFunction(std::string functionName, std::string functionBody, std::vector<std::string> parameters = std::vector<std::string>());
	void addFunction(std::string functionName, std::vector<std::string> functionBody, std::vector<std::string> parameters = std::vector<std::string>());
	void addCodeLine(std::string line);
	void addCodeLines(std::vector<std::string> lines);
	void writeFile(const std::string& fileName);
	static void writeCodeToFile(const std::string& fileName, std::string code);
	static void writeCodeToFile(const std::string& fileName, std::vector<std::string> code);

private:
	std::string prepareFunctionTitle(std::string functionName, const std::vector<std::string>& parameters);

private:
	std::vector<std::string> pythonCodeLines;
};

