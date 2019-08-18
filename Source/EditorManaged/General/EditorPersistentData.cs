//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
using bs;
using System.Collections.Generic;

namespace bs.Editor
{
    /** @addtogroup Editor-General
     *  @{
     */

    /// <summary>
    /// Contains editor data that should persist assembly refresh.
    /// </summary>
    internal class EditorPersistentData : ManagedComponent
    {
        [SerializeField]
        internal Dictionary<UUID, Resource> dirtyResources = new Dictionary<UUID, Resource>();

        [SerializeField]
        internal Dictionary<UUID, EditorAnimClipInfo> dirtyAnimClips = new Dictionary<UUID, EditorAnimClipInfo>();

        [SerializeField]
        internal long lastCompileTime;

        [SerializeField]
        internal EditorSceneData editorSceneData;
    }

    /** @} */
}
