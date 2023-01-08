#include "ExportPython.h"

int main()
{
	ExportPython pythonExport;

	// test.py - function body as string
	pythonExport.addCodeLine("dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files");
	pythonExport.addCodeLine("loadedNodeIDs = []  # this list will contain the list of all loaded node IDs");
	
	pythonExport.addFunction("helloWorld",
		"from DICOMLib import DICOMUtils\nwith DICOMUtils.TemporaryDICOMDatabase() as db:\n  DICOMUtils.importDicom(dicomDataDir, db)\n  patientUIDs = db.patients()\n  for patientUID in patientUIDs:\n    loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))");

	pythonExport.addCodeLine("\nhelloWorld()");
	pythonExport.writeFile("test.py");

	// test1.py - function body as vector
	pythonExport.addCodeLine("dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files");
	pythonExport.addCodeLine("loadedNodeIDs = []  # this list will contain the list of all loaded node IDs");

	pythonExport.addFunction("helloWorld",
		{ "from DICOMLib import DICOMUtils",
		  "with DICOMUtils.TemporaryDICOMDatabase() as db: ",
		  "  DICOMUtils.importDicom(dicomDataDir, db)",
		  "  patientUIDs = db.patients()","  for patientUID in patientUIDs: ",
		  "    loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))" });

	pythonExport.addCodeLine("\nhelloWorld()");
	pythonExport.writeFile("test1.py");

	// test2.py - code as string
	ExportPython::writeCodeToFile("test2.py",
		"dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files\nloadedNodeIDs = []  # this list will contain the list of all loaded node IDs\ndef helloWorld():\n from DICOMLib import DICOMUtils\n with DICOMUtils.TemporaryDICOMDatabase() as db:\n   DICOMUtils.importDicom(dicomDataDir, db)\n   patientUIDs = db.patients()\n   for patientUID in patientUIDs:\n     loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))\n\nhelloWorld()");

	// test3.py - code as vector
	ExportPython::writeCodeToFile("test3.py",
		{ "dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files",
		  "loadedNodeIDs = []  # this list will contain the list of all loaded node IDs",
		  "def helloWorld():",
		  " from DICOMLib import DICOMUtils",
		  " with DICOMUtils.TemporaryDICOMDatabase() as db:",
		  "   DICOMUtils.importDicom(dicomDataDir, db)",
		  "   patientUIDs = db.patients()",
		  "   for patientUID in patientUIDs:",
		  "     loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))",
		  "\nhelloWorld()" });

	// test4.py - function body as string - with parameters
	pythonExport.addFunction("pathFromNode",
		"storageNode = node.GetStorageNode()\nif storageNode is not None: # loaded via drag-drop\n  filepath = storageNode.GetFullNameFromFileName()\nelse: # Loaded via DICOM browser\n  instanceUIDs = node.GetAttribute(\"DICOM.instanceUIDs\").split()\n  filepath = slicer.dicomDatabase.fileForInstance(instUids[0])\nreturn filepath",
		{ "node", "node2", "node3" });

	pythonExport.addCodeLine("# Example:");
	pythonExport.addCodeLine("node = slicer.util.getNode(\"volume1\")");
	pythonExport.addCodeLine("path = self.pathFromNode(node)");
	pythonExport.addCodeLine("print(\"DICOM path=%s\" % path)");


	pythonExport.writeFile("test4.py");

	// test5.py - function body as vector - with parameters
	pythonExport.addFunction("pathFromNode",
		"storageNode = node.GetStorageNode()\nif storageNode is not None: # loaded via drag-drop\n  filepath = storageNode.GetFullNameFromFileName()\nelse: # Loaded via DICOM browser\n  instanceUIDs = node.GetAttribute(\"DICOM.instanceUIDs\").split()\n  filepath = slicer.dicomDatabase.fileForInstance(instUids[0])\nreturn filepath",
		{ "node", "node2", "node3" });

	pythonExport.addCodeLine("# Example:");
	pythonExport.addCodeLine("node = slicer.util.getNode(\"volume1\")");
	pythonExport.addCodeLine("path = self.pathFromNode(node)");
	pythonExport.addCodeLine("print(\"DICOM path=%s\" % path)");


	pythonExport.writeFile("test5.py");

	return 0;
}