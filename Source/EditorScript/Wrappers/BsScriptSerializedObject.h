//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
#pragma once

#include "BsScriptEditorPrerequisites.h"
#include "BsScriptObject.h"

namespace bs
{
	/** @addtogroup ScriptInteropEditor
	 *  @{
	 */

	/**	Interop class between C++ & CLR for SerializedObject. */
	class BS_SCR_BED_EXPORT ScriptSerializedObject : public ScriptObject <ScriptSerializedObject>
	{
	public:
		SCRIPT_OBJ(EDITOR_ASSEMBLY, EDITOR_NS, "SerializedObject")

		/** Returns the serialized object wrapped by this object. */
		SPtr<IReflectable> getInternal() const { return mSerializedObject; }

	private:
		ScriptSerializedObject(MonoObject* instance, const SPtr<IReflectable>& obj);

		SPtr<IReflectable> mSerializedObject;

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static MonoObject* internal_Create(MonoObject* obj);
		static MonoObject* internal_Deserialize(ScriptSerializedObject* thisPtr);
	};

	/** @} */
}