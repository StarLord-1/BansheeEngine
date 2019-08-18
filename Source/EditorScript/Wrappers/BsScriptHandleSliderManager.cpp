//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "Wrappers/BsScriptHandleSliderManager.h"
#include "Wrappers/BsScriptHandleSlider.h"

namespace bs
{
	ScriptHandleSliderManager::~ScriptHandleSliderManager()
	{
		for (auto& slider : mSliders)
			slider->destroyInternal();
	}

	void ScriptHandleSliderManager::registerSlider(ScriptHandleSliderBase* slider)
	{
		mSliders.insert(slider);
	}

	void ScriptHandleSliderManager::unregisterSlider(ScriptHandleSliderBase* slider)
	{
		mSliders.erase(slider);
	}
}