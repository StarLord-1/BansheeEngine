//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "Settings/BsProjectSettings.h"
#include "Private/RTTI/BsProjectSettingsRTTI.h"

namespace bs
{
	ProjectSettings::ProjectSettings()
	{ }

	RTTITypeBase* ProjectSettings::getRTTIStatic()
	{
		return ProjectSettingsRTTI::instance();
	}

	RTTITypeBase* ProjectSettings::getRTTI() const
	{
		return ProjectSettings::getRTTIStatic();
	}
}