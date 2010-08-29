/*
 *	server/zone/objects/creature/Creature.cpp generated by engine3 IDL compiler 0.60
 */

#include "Creature.h"

#include "server/zone/objects/creature/CreatureObject.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/creature/events/DespawnCreatureOnPlayerDissappear.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "system/lang/Time.h"

#include "server/zone/objects/creature/events/AiMoveEvent.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/templates/tangible/NonPlayerCreatureObjectTemplate.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "engine/util/Quaternion.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/PatrolPoint.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/objects/creature/events/AiThinkEvent.h"

#include "server/zone/objects/creature/PatrolPointsVector.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

/*
 *	CreatureStub
 */

Creature::Creature() : AiAgent(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new CreatureImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

Creature::Creature(DummyConstructorParameter* param) : AiAgent(param) {
}

Creature::~Creature() {
}


bool Creature::isCreature() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _getImplementation())->isCreature();
}

/*
 *	CreatureImplementation
 */

CreatureImplementation::CreatureImplementation(DummyConstructorParameter* param) : AiAgentImplementation(param) {
	_initializeImplementation();
}


CreatureImplementation::~CreatureImplementation() {
}


void CreatureImplementation::finalize() {
}

void CreatureImplementation::_initializeImplementation() {
	_setClassHelper(CreatureHelper::instance());

	_serializationHelperMethod();
}

void CreatureImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Creature*) stub;
	AiAgentImplementation::_setStub(stub);
}

DistributedObjectStub* CreatureImplementation::_getStub() {
	return _this;
}

CreatureImplementation::operator const Creature*() {
	return _this;
}

TransactionalObject* CreatureImplementation::clone() {
	return (TransactionalObject*) new CreatureImplementation(*this);
}


void CreatureImplementation::lock(bool doLock) {
}

void CreatureImplementation::lock(ManagedObject* obj) {
}

void CreatureImplementation::rlock(bool doLock) {
}

void CreatureImplementation::wlock(bool doLock) {
}

void CreatureImplementation::wlock(ManagedObject* obj) {
}

void CreatureImplementation::unlock(bool doLock) {
}

void CreatureImplementation::runlock(bool doLock) {
}

void CreatureImplementation::_serializationHelperMethod() {
	AiAgentImplementation::_serializationHelperMethod();

	_setClassName("Creature");

}

CreatureImplementation::CreatureImplementation() {
	_initializeImplementation();
	// server/zone/objects/creature/Creature.idl(54):  		Logger.setLoggingName("Creature");
	Logger::setLoggingName("Creature");
	// server/zone/objects/creature/Creature.idl(55):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/creature/Creature.idl(56):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

bool CreatureImplementation::isCreature() {
	// server/zone/objects/creature/Creature.idl(60):  		return true;
	return true;
}

/*
 *	CreatureAdapter
 */

CreatureAdapter::CreatureAdapter(CreatureImplementation* obj) : AiAgentAdapter(obj) {
}

Packet* CreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(isCreature());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool CreatureAdapter::isCreature() {
	return ((CreatureImplementation*) impl)->isCreature();
}

/*
 *	CreatureHelper
 */

CreatureHelper* CreatureHelper::staticInitializer = CreatureHelper::instance();

CreatureHelper::CreatureHelper() {
	className = "Creature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureHelper::finalizeHelper() {
	CreatureHelper::finalize();
}

DistributedObject* CreatureHelper::instantiateObject() {
	return new Creature(DummyConstructorParameter::instance());
}

DistributedObjectServant* CreatureHelper::instantiateServant() {
	return new CreatureImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CreatureAdapter((CreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

