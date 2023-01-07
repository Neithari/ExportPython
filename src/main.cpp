#include "ExportPython.h"

int main()
{
	ExportPython pythonExport;

	pythonExport.addCodeLine("dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files");
	pythonExport.addCodeLine("loadedNodeIDs = []  # this list will contain the list of all loaded node IDs");
	
	pythonExport.addFunction("helloWorld",
		"from DICOMLib import DICOMUtils\nwith DICOMUtils.TemporaryDICOMDatabase() as db:\n  DICOMUtils.importDicom(dicomDataDir, db)\n  patientUIDs = db.patients()\n  for patientUID in patientUIDs:\n    loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))");

	pythonExport.addCodeLine("\nhelloWorld()");
	pythonExport.writeFile("test.py");

	ExportPython::writeCodeToFile("test1.py",
		"dicomDataDir = \"c: / my / folder / with / dicom - files\"  # input folder with DICOM files\nloadedNodeIDs = []  # this list will contain the list of all loaded node IDs\ndef helloWorld():\n from DICOMLib import DICOMUtils\n with DICOMUtils.TemporaryDICOMDatabase() as db:\n   DICOMUtils.importDicom(dicomDataDir, db)\n   patientUIDs = db.patients()\n   for patientUID in patientUIDs:\n     loadedNodeIDs.extend(DICOMUtils.loadPatientByUID(patientUID))\n\nhelloWorld()");

	pythonExport.addFunction("pathFromNode",
		"storageNode = node.GetStorageNode()\nif storageNode is not None: # loaded via drag-drop\n  filepath = storageNode.GetFullNameFromFileName()\nelse: # Loaded via DICOM browser\n  instanceUIDs = node.GetAttribute(\"DICOM.instanceUIDs\").split()\n  filepath = slicer.dicomDatabase.fileForInstance(instUids[0])\nreturn filepath",
		{ "node", "node2", "node3" });

	pythonExport.addCodeLine("# Example:");
	pythonExport.addCodeLine("node = slicer.util.getNode(\"volume1\")");
	pythonExport.addCodeLine("path = self.pathFromNode(node)");
	pythonExport.addCodeLine("print(\"DICOM path=%s\" % path)");


	pythonExport.writeFile("test3.py");

	return 0;
}