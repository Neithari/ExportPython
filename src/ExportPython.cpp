#include "ExportPython.h"
#include <fstream>
#include <iostream>
#include <sstream>

void ExportPython::addFunction(std::string functionName, std::string functionBody, std::vector<std::string> parameters)
{
	using namespace std::string_literals;
	// Prepare function declaration
	functionName.insert(0, "def "s, 0, 4);
	functionName.push_back('(');
	size_t index{ 0 };
	for (auto& parameter : parameters) {
		functionName.insert(functionName.end(), std::begin(parameter), std::end(parameter));
		if (++index != parameters.size()) {
			functionName.push_back(',');
		}
	}
	functionName.insert(functionName.size(), "):"s);
	pythonCodeLines.push_back(std::move(functionName));

	// Prepare function body
	std::stringstream functionBodyStream{ functionBody };
	while (std::getline(functionBodyStream, functionBody))
	{
		functionBody.insert(0, " ");
		pythonCodeLines.push_back(std::move(functionBody));
	}
}

void ExportPython::addCodeLine(std::string line)
{
	pythonCodeLines.push_back(std::move(line));
}

void ExportPython::addCodeLines(std::vector<std::string> lines)
{
	for (auto& line : lines) {
		addCodeLine(line);
	}
}

void ExportPython::writeFile(const std::string& fileName)
{
	std::ofstream pythonFile{ fileName };

	if (!pythonFile) {
		std::cerr << fileName << " could not be opened for writing!\n";
		return;
	}

	for (auto& line : pythonCodeLines) {
		pythonFile << line << '\n';
	}

	pythonCodeLines.clear();
}

void ExportPython::writeCodeToFile(const std::string& fileName, std::string code)
{
	std::ofstream pythonFile{ fileName };

	if (!pythonFile) {
		std::cerr << fileName << " could not be opened for writing!\n";
		return;
	}

	pythonFile << code;
}
