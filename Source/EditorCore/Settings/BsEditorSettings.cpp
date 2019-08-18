//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "Settings/BsEditorSettings.h"
#include "Private/RTTI/BsEditorSettingsRTTI.h"

namespace bs
{
	RTTITypeBase* EditorSettings::getRTTIStatic()
	{
		return EditorSettingsRTTI::instance();
	}

	RTTITypeBase* EditorSettings::getRTTI() const
	{
		return EditorSettings::getRTTIStatic();
	}
}