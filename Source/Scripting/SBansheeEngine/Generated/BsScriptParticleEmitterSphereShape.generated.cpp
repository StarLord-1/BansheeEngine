#include "BsScriptParticleEmitterSphereShape.generated.h"
#include "BsMonoMethod.h"
#include "BsMonoClass.h"
#include "BsMonoUtil.h"
#include "../../../bsf/Source/Foundation/bsfCore/Particles/BsParticleEmitter.h"
#include "BsScriptPARTICLE_SPHERE_SHAPE_DESC.generated.h"
#include "BsScriptParticleEmitterSphereShape.generated.h"

namespace bs
{
	ScriptParticleEmitterSphereShape::ScriptParticleEmitterSphereShape(MonoObject* managedInstance, const SPtr<ParticleEmitterSphereShape>& value)
		:ScriptObject(managedInstance)
	{
		mInternal = value;
	}

	SPtr<ParticleEmitterSphereShape> ScriptParticleEmitterSphereShape::getInternal() const 
	{
		return std::static_pointer_cast<ParticleEmitterSphereShape>(mInternal);
	}

	void ScriptParticleEmitterSphereShape::initRuntimeData()
	{
		metaData.scriptClass->addInternalCall("Internal_setOptions", (void*)&ScriptParticleEmitterSphereShape::Internal_setOptions);
		metaData.scriptClass->addInternalCall("Internal_getOptions", (void*)&ScriptParticleEmitterSphereShape::Internal_getOptions);
		metaData.scriptClass->addInternalCall("Internal_create", (void*)&ScriptParticleEmitterSphereShape::Internal_create);

	}

	MonoObject* ScriptParticleEmitterSphereShape::create(const SPtr<ParticleEmitterSphereShape>& value)
	{
		if(value == nullptr) return nullptr; 

		bool dummy = false;
		void* ctorParams[1] = { &dummy };

		MonoObject* managedInstance = metaData.scriptClass->createInstance("bool", ctorParams);
		new (bs_alloc<ScriptParticleEmitterSphereShape>()) ScriptParticleEmitterSphereShape(managedInstance, value);
		return managedInstance;
	}
	void ScriptParticleEmitterSphereShape::Internal_setOptions(ScriptParticleEmitterSphereShape* thisPtr, PARTICLE_SPHERE_SHAPE_DESC* options)
	{
		thisPtr->getInternal()->setOptions(*options);
	}

	void ScriptParticleEmitterSphereShape::Internal_getOptions(ScriptParticleEmitterSphereShape* thisPtr, PARTICLE_SPHERE_SHAPE_DESC* __output)
	{
		PARTICLE_SPHERE_SHAPE_DESC tmp__output;
		tmp__output = thisPtr->getInternal()->getOptions();

		*__output = tmp__output;
	}

	void ScriptParticleEmitterSphereShape::Internal_create(MonoObject* managedInstance, PARTICLE_SPHERE_SHAPE_DESC* desc)
	{
		SPtr<ParticleEmitterSphereShape> instance = ParticleEmitterSphereShape::create(*desc);
		new (bs_alloc<ScriptParticleEmitterSphereShape>())ScriptParticleEmitterSphereShape(managedInstance, instance);
	}
}
