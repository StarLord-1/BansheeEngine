//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#pragma once

#include "BsEditorPrerequisites.h"

namespace bs
{
	/** @addtogroup Utility-Editor
	 *  @{
	 */

	/**	Displays a splash screen with Banshee Engine logo. */
	class BS_ED_EXPORT SplashScreen
	{
	public:
		/**	Displays a splash screen with Banshee Engine logo. */
		static void show();

		/**	Hides the splash screen. */
		static void hide();

	private:
		/** Creates the splash screen window. */
		static void create();

		/** Destroys the splash screen window. */
		static void destroy();

		struct Pimpl;
		static Pimpl* m;
	};

	/** @} */
}