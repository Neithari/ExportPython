#pragma once
#include <string>
#include <vector>

class ExportPython
{
public:
	ExportPython() = default;

	void addImports(std::vector<std::string> imports);
	void addFunction(std::string functionName, std::vector<std::string> parameters, std::string functionBody);
	void addCodeLine(std::string line);
	void addCodeLines(std::vector<std::string> lines);
	void writeFile(const std::string& fileName, const std::string& path);

private:
	std::vector<std::string> pythonCodeLines;
};

