//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
using bs;

namespace bs.Editor
{
    /** @addtogroup Inspectors
     *  @{
     */

    /// <summary>
    /// Renders an inspector for the <see cref="PhysicsMesh"/> resource.
    /// </summary>
    [CustomInspector(typeof(PhysicsMesh))]
    internal class PhysicsMeshInspector : Inspector
    {
        /// <inheritdoc/>
        protected internal override void Initialize()
        {
            // No GUI for physics mesh resource
        }

        /// <inheritdoc/>
        protected internal override InspectableState Refresh(bool force = false)
        {
            return InspectableState.NotModified;
        }
    }

    /** @} */
}