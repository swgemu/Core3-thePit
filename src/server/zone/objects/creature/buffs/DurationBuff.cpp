/*
 *	server/zone/objects/creature/buffs/DurationBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "DurationBuff.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"

#include "server/zone/objects/creature/buffs/SpiceDownerBuff.h"


// Imported class dependencies

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/scene/variables/ParameterizedStringId.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "server/zone/objects/creature/buffs/BuffDurationEvent.h"

#include "system/lang/Time.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "system/util/SortedVector.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "system/util/Vector.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

/*
 *	DurationBuffStub
 */

DurationBuff::DurationBuff(CreatureObject* creo, unsigned int buffcrc, float duration) : Buff(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new DurationBuffImplementation(creo, buffcrc, duration));
	ManagedObject::_getImplementation()->_setStub(this);
}

DurationBuff::DurationBuff(DummyConstructorParameter* param) : Buff(param) {
}

DurationBuff::~DurationBuff() {
}


void DurationBuff::activate(bool applyModifiers) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		((DurationBuffImplementation*) _getImplementation())->activate(applyModifiers);
}

/*
 *	DurationBuffImplementation
 */

DurationBuffImplementation::DurationBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


DurationBuffImplementation::~DurationBuffImplementation() {
}


void DurationBuffImplementation::finalize() {
}

void DurationBuffImplementation::_initializeImplementation() {
	_setClassHelper(DurationBuffHelper::instance());

	_serializationHelperMethod();
}

void DurationBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DurationBuff*) stub;
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* DurationBuffImplementation::_getStub() {
	return _this;
}

DurationBuffImplementation::operator const DurationBuff*() {
	return _this;
}

TransactionalObject* DurationBuffImplementation::clone() {
	return (TransactionalObject*) new DurationBuffImplementation(*this);
}


void DurationBuffImplementation::lock(bool doLock) {
}

void DurationBuffImplementation::lock(ManagedObject* obj) {
}

void DurationBuffImplementation::rlock(bool doLock) {
}

void DurationBuffImplementation::wlock(bool doLock) {
}

void DurationBuffImplementation::wlock(ManagedObject* obj) {
}

void DurationBuffImplementation::unlock(bool doLock) {
}

void DurationBuffImplementation::runlock(bool doLock) {
}

void DurationBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("DurationBuff");

}

DurationBuffImplementation::DurationBuffImplementation(CreatureObject* creo, unsigned int buffcrc, float duration) : BuffImplementation(creo, buffcrc, duration, BuffType::FOOD) {
	_initializeImplementation();
}

void DurationBuffImplementation::activate(bool applyModifiers) {
	// server/zone/objects/creature/buffs/DurationBuff.idl(70):  		super.activate(false);
	BuffImplementation::activate(false);
}

/*
 *	DurationBuffAdapter
 */

DurationBuffAdapter::DurationBuffAdapter(DurationBuffImplementation* obj) : BuffAdapter(obj) {
}

Packet* DurationBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		activate(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DurationBuffAdapter::activate(bool applyModifiers) {
	((DurationBuffImplementation*) impl)->activate(applyModifiers);
}

/*
 *	DurationBuffHelper
 */

DurationBuffHelper* DurationBuffHelper::staticInitializer = DurationBuffHelper::instance();

DurationBuffHelper::DurationBuffHelper() {
	className = "DurationBuff";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DurationBuffHelper::finalizeHelper() {
	DurationBuffHelper::finalize();
}

DistributedObject* DurationBuffHelper::instantiateObject() {
	return new DurationBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* DurationBuffHelper::instantiateServant() {
	return new DurationBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DurationBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DurationBuffAdapter((DurationBuffImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

