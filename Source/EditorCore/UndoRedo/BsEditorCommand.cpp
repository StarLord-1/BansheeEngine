//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "UndoRedo/BsEditorCommand.h"

namespace bs
{
	EditorCommand::EditorCommand(const String& description)
		:mDescription(description), mId(0)
	{ }
}