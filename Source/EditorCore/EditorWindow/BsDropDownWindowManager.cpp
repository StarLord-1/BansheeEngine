//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "EditorWindow/BsDropDownWindowManager.h"
#include "EditorWindow/BsDropDownWindow.h"

namespace bs
{
	DropDownWindowManager::DropDownWindowManager()
		:mOpenWindow(nullptr)
	{ }

	DropDownWindowManager::~DropDownWindowManager()
	{
		close();
	}

	void DropDownWindowManager::close()
	{
		if (mOpenWindow != nullptr)
		{
			bs_delete(mOpenWindow);
			mOpenWindow = nullptr;
		}
	}

	void DropDownWindowManager::update()
	{
		if (mOpenWindow != nullptr)
			mOpenWindow->update();
	}
}