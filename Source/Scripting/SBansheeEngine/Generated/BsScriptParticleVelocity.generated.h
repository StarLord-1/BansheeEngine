#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"
#include "BsScriptParticleEvolver.generated.h"

namespace bs
{
	struct __PARTICLE_VELOCITY_DESCInterop;
	class ParticleVelocity;

	class BS_SCR_BE_EXPORT ScriptParticleVelocity : public ScriptObject<ScriptParticleVelocity, ScriptParticleEvolverBase>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "ParticleVelocity")

		ScriptParticleVelocity(MonoObject* managedInstance, const SPtr<ParticleVelocity>& value);

		SPtr<ParticleVelocity> getInternal() const;
		static MonoObject* create(const SPtr<ParticleVelocity>& value);

	private:
		static void Internal_setOptions(ScriptParticleVelocity* thisPtr, __PARTICLE_VELOCITY_DESCInterop* options);
		static void Internal_getOptions(ScriptParticleVelocity* thisPtr, __PARTICLE_VELOCITY_DESCInterop* __output);
		static void Internal_create(MonoObject* managedInstance, __PARTICLE_VELOCITY_DESCInterop* desc);
	};
}
