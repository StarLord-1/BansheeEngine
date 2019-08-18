//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
using System;

namespace bs.Editor
{
    /** @addtogroup Window
     *  @{
     */

    /// <summary>
    /// Can be placed on <see cref="EditorWindow"/> class to ensure the editor window uses a local undo/redo stack instead
    /// of the global one.
    /// </summary>
    [AttributeUsage(AttributeTargets.Class)]
    public sealed class UndoRedoLocal : Attribute
    {
        public UndoRedoLocal()
        { }
    }

    /** @} */
}
