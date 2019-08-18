//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "Build/BsPlatformInfo.h"
#include "Private/RTTI/BsPlatformInfoRTTI.h"

namespace bs
{
	PlatformInfo::PlatformInfo()
		:type(PlatformType::Windows), fullscreen(true), windowedWidth(1280), windowedHeight(720),
#ifdef DEBUG
        debug(true)
#else
        debug(false)
#endif
	{ }

	PlatformInfo::~PlatformInfo()
	{ }

	RTTITypeBase* PlatformInfo::getRTTIStatic()
	{
		return PlatformInfoRTTI::instance();
	}

	RTTITypeBase* PlatformInfo::getRTTI() const
	{
		return PlatformInfo::getRTTIStatic();
	}

	WinPlatformInfo::WinPlatformInfo()
	{ }

	RTTITypeBase* WinPlatformInfo::getRTTIStatic()
	{
		return WinPlatformInfoRTTI::instance();
	}

	RTTITypeBase* WinPlatformInfo::getRTTI() const
	{
		return WinPlatformInfo::getRTTIStatic();
	}
}