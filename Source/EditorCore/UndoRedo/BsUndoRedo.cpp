//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#include "UndoRedo/BsUndoRedo.h"
#include "UndoRedo/BsEditorCommand.h"

namespace bs
{
	const UINT32 UndoRedo::MAX_STACK_ELEMENTS = 1000;

	UndoRedo::UndoRedo()
		: mUndoStack(nullptr), mRedoStack(nullptr), mUndoStackPtr(0), mUndoNumElements(0), mRedoStackPtr(0)
		, mRedoNumElements(0), mNextCommandId(0)
	{
		mUndoStack = bs_newN<SPtr<EditorCommand>>(MAX_STACK_ELEMENTS);
		mRedoStack = bs_newN<SPtr<EditorCommand>>(MAX_STACK_ELEMENTS);
	}

	UndoRedo::~UndoRedo()
	{
		clear();

		bs_deleteN(mUndoStack, MAX_STACK_ELEMENTS);
		bs_deleteN(mRedoStack, MAX_STACK_ELEMENTS);
	}

	void UndoRedo::undo()
	{
		if(mUndoNumElements == 0)
			return;

		SPtr<EditorCommand> command = removeLastFromUndoStack();
		if(!command)
			return;
		
		mRedoStackPtr = (mRedoStackPtr + 1) % MAX_STACK_ELEMENTS;
		mRedoStack[mRedoStackPtr] = command;
		mRedoNumElements = std::min(mRedoNumElements + 1, MAX_STACK_ELEMENTS);

		command->revert();
	}

	void UndoRedo::redo()
	{
		if(mRedoNumElements == 0)
			return;

		SPtr<EditorCommand> command = mRedoStack[mRedoStackPtr];
		mRedoStack[mRedoStackPtr] = SPtr<EditorCommand>();
		mRedoStackPtr = (mRedoStackPtr - 1) % MAX_STACK_ELEMENTS;
		mRedoNumElements--;

		addToUndoStack(command);

		command->commit();
	}

	void UndoRedo::pushGroup(const String& name)
	{
		mGroups.push_back(GroupData());
		GroupData& newGroup = mGroups.back();

		newGroup.name = name;
		newGroup.numEntries = 0;

		clearRedoStack();
	}

	void UndoRedo::popGroup(const String& name)
	{
		if(mGroups.empty())
			BS_EXCEPT(InvalidStateException, "Attempting to pop an UndoRedo group that doesn't exist: " + name);

		GroupData& topGroup = mGroups.back();
		if(topGroup.name != name)
			BS_EXCEPT(InvalidStateException, "Attempting to pop invalid UndoRedo group. Got: " + name + ". Expected: " + topGroup.name);

		for(UINT32 i = 0; i < topGroup.numEntries; i++)
		{
			if (mUndoStack[mUndoStackPtr] != nullptr)
				mUndoStack[mUndoStackPtr]->onCommandRemoved();

			mUndoStack[mUndoStackPtr] = SPtr<EditorCommand>();
			mUndoStackPtr = (mUndoStackPtr - 1) % MAX_STACK_ELEMENTS;
			mUndoNumElements--;
		}

		mGroups.pop_back();
		clearRedoStack();
	}

	void UndoRedo::registerCommand(const SPtr<EditorCommand>& command)
	{
		command->mId = mNextCommandId++;
		command->onCommandAdded();

		SPtr<EditorCommand> existingCommand = addToUndoStack(command);
		if (existingCommand != nullptr)
			existingCommand->onCommandRemoved();

		clearRedoStack();
	}

	UINT32 UndoRedo::getTopCommandId() const
	{
		if (mUndoNumElements > 0)
			return mUndoStack[mUndoStackPtr]->mId;

		return 0;
	}

	void UndoRedo::popCommand(UINT32 id)
	{
		UINT32 undoPtr = mUndoStackPtr;
		for (UINT32 i = 0; i < mUndoNumElements; i++)
		{
			if (mUndoStack[undoPtr]->mId == id)
			{
				if (mUndoStack[undoPtr] != nullptr)
					mUndoStack[undoPtr]->onCommandRemoved();

				mUndoStack[undoPtr] = SPtr<EditorCommand>();

				for (UINT32 j = mUndoNumElements - i; j < (mUndoNumElements - 1); j++)
				{
					UINT32 nextUndoPtr = (undoPtr + 1) % MAX_STACK_ELEMENTS;

					std::swap(mUndoStack[undoPtr], mUndoStack[nextUndoPtr]);
					undoPtr = nextUndoPtr;
				}

				mUndoStackPtr = (mUndoStackPtr - 1) % MAX_STACK_ELEMENTS;
				mUndoNumElements--;
				break;
			}

			undoPtr = (undoPtr - 1) % MAX_STACK_ELEMENTS;
		}

		UINT32 redoPtr = mRedoStackPtr;
		for (UINT32 i = 0; i < mRedoNumElements; i++)
		{
			if (mRedoStack[redoPtr]->mId == id)
			{
				if (mRedoStack[redoPtr] != nullptr)
					mRedoStack[redoPtr]->onCommandRemoved();

				mRedoStack[redoPtr] = SPtr<EditorCommand>();

				for (UINT32 j = mRedoNumElements - i; j < (mRedoNumElements - 1); j++)
				{
					UINT32 nextRedoPtr = (redoPtr + 1) % MAX_STACK_ELEMENTS;

					std::swap(mRedoStack[redoPtr], mRedoStack[nextRedoPtr]);
					redoPtr = nextRedoPtr;
				}

				mRedoStackPtr = (mRedoStackPtr - 1) % MAX_STACK_ELEMENTS;
				mRedoNumElements--;
				break;
			}

			redoPtr = (redoPtr - 1) % MAX_STACK_ELEMENTS;
		}
	}

	void UndoRedo::clear()
	{
		clearUndoStack();
		clearRedoStack();
	}

	SPtr<EditorCommand> UndoRedo::removeLastFromUndoStack()
	{
		SPtr<EditorCommand> command = mUndoStack[mUndoStackPtr];

		mUndoStack[mUndoStackPtr] = SPtr<EditorCommand>();
		mUndoStackPtr = (mUndoStackPtr - 1) % MAX_STACK_ELEMENTS;
		mUndoNumElements--;

		for(auto iter = mGroups.rbegin(); iter != mGroups.rend(); ++iter)
		{
			GroupData& group = *iter;

			if(group.numEntries > 0)
			{
				group.numEntries--;
				break;
			}
		}

		return command;
	}

	SPtr<EditorCommand> UndoRedo::addToUndoStack(const SPtr<EditorCommand>& command)
	{
		mUndoStackPtr = (mUndoStackPtr + 1) % MAX_STACK_ELEMENTS;

		SPtr<EditorCommand> existingCommand = mUndoStack[mUndoStackPtr];

		mUndoStack[mUndoStackPtr] = command;
		mUndoNumElements = std::min(mUndoNumElements + 1, MAX_STACK_ELEMENTS);

		if(!mGroups.empty())
		{
			GroupData& topGroup = mGroups.back();
			topGroup.numEntries = std::min(topGroup.numEntries + 1, MAX_STACK_ELEMENTS);
		}

		return existingCommand;
	}

	void UndoRedo::clearUndoStack()
	{
		while(mUndoNumElements > 0)
		{
			if (mUndoStack[mUndoStackPtr] != nullptr)
				mUndoStack[mUndoStackPtr]->onCommandRemoved();

			mUndoStack[mUndoStackPtr] = SPtr<EditorCommand>();
			mUndoStackPtr = (mUndoStackPtr - 1) % MAX_STACK_ELEMENTS;
			mUndoNumElements--;
		}

		mGroups.clear();
	}

	void UndoRedo::clearRedoStack()
	{
		while(mRedoNumElements > 0)
		{
			if (mRedoStack[mRedoStackPtr] != nullptr)
				mRedoStack[mRedoStackPtr]->onCommandRemoved();

			mRedoStack[mRedoStackPtr] = SPtr<EditorCommand>();
			mRedoStackPtr = (mRedoStackPtr - 1) % MAX_STACK_ELEMENTS;
			mRedoNumElements--;
		}
	}
}