//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Jonathan Harrison (harrison.j@banshee3d.com). All rights reserved. **********************//
using bs;

namespace bs.Editor
{
    /** @addtogroup Inspectors
     *  @{
     */

    /// <summary>
    /// Renders an inspector for the <see cref="SliderJoint"/> component.
    /// </summary>
    [CustomInspector(typeof(SliderJoint))]
    internal class SliderJointInspector : JointInspector
    {
        /// <inheritdoc/>
        protected internal override void Initialize()
        {
            SliderJoint joint = (SliderJoint)InspectedObject;
            BuildGUI(joint, true);

            drawer.AddDefault(joint, typeof(SliderJoint));
            drawer.AddField("Enable limit",
                () => joint.HasFlag(SliderJointFlag.Limit),
                x => joint.SetFlag(SliderJointFlag.Limit, x));
            drawer.AddConditional("Limit", () => joint.HasFlag(SliderJointFlag.Limit));
        }
    }

    /** @} */
}