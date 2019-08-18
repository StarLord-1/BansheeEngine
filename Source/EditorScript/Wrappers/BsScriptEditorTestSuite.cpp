//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "Wrappers/BsScriptEditorTestSuite.h"
#include "Wrappers/BsScriptUnitTests.h"

namespace bs
{
	ScriptEditorTestSuite::ScriptEditorTestSuite()
	{
		BS_ADD_TEST(ScriptEditorTestSuite::runManagedTests);
	}

	void ScriptEditorTestSuite::runManagedTests()
	{
		ScriptUnitTests::runTests();
	}
}