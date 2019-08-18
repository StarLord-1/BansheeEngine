//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
using bs;

namespace bs.Editor
{
    /** @addtogroup Inspectors
     *  @{
     */

    /// <summary>
    /// Renders an inspector for the <see cref="FixedJoint"/> component.
    /// </summary>
    [CustomInspector(typeof(FixedJoint))]
    internal class FixedJointInspector : JointInspector
    {
        /// <inheritdoc/>
        protected internal override void Initialize()
        {
            FixedJoint joint = (FixedJoint) InspectedObject;
            BuildGUI(joint, false);
        }
    }

    /** @} */
}