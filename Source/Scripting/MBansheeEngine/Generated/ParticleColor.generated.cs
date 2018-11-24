using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace BansheeEngine
{
	/** @addtogroup Particles
	 *  @{
	 */

	/// <summary>Changes the color of the particles over the particle lifetime.</summary>
	public partial class ParticleColor : ParticleEvolver
	{
		private ParticleColor(bool __dummy0) { }
		protected ParticleColor() { }

		/// <summary>Creates a new particle color evolver.</summary>
		public ParticleColor(ParticleColorOptions desc)
		{
			Internal_create(this, ref desc);
		}

		/// <summary>Options describing the evolver.</summary>
		public ParticleColorOptions Options
		{
			get
			{
				ParticleColorOptions temp;
				Internal_getOptions(mCachedPtr, out temp);
				return temp;
			}
			set { Internal_setOptions(mCachedPtr, ref value); }
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void Internal_setOptions(IntPtr thisPtr, ref ParticleColorOptions options);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void Internal_getOptions(IntPtr thisPtr, out ParticleColorOptions __output);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void Internal_create(ParticleColor managedInstance, ref ParticleColorOptions desc);
	}

	/** @} */
}
