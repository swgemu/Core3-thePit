/*
 *	server/zone/objects/creature/buffs/SpiceBuff.cpp generated by engine3 IDL compiler 0.60
 */

#include "SpiceBuff.h"

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
 *	SpiceBuffStub
 */

SpiceBuff::SpiceBuff(CreatureObject* creo, const String& name, unsigned int buffCRC, int duration) : Buff(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new SpiceBuffImplementation(creo, name, buffCRC, duration));
	ManagedObject::_getImplementation()->_setStub(this);
}

SpiceBuff::SpiceBuff(DummyConstructorParameter* param) : Buff(param) {
}

SpiceBuff::~SpiceBuff() {
}


void SpiceBuff::activate(bool applyModifiers) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(applyModifiers);

		method.executeWithVoidReturn();
	} else
		((SpiceBuffImplementation*) _getImplementation())->activate(applyModifiers);
}

void SpiceBuff::deactivate(bool removeModifiers) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addBooleanParameter(removeModifiers);

		method.executeWithVoidReturn();
	} else
		((SpiceBuffImplementation*) _getImplementation())->deactivate(removeModifiers);
}

void SpiceBuff::setDownerAttributes(CreatureObject* creature, Buff* buff) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(creature);
		method.addObjectParameter(buff);

		method.executeWithVoidReturn();
	} else
		((SpiceBuffImplementation*) _getImplementation())->setDownerAttributes(creature, buff);
}

/*
 *	SpiceBuffImplementation
 */

SpiceBuffImplementation::SpiceBuffImplementation(DummyConstructorParameter* param) : BuffImplementation(param) {
	_initializeImplementation();
}


SpiceBuffImplementation::~SpiceBuffImplementation() {
}


void SpiceBuffImplementation::finalize() {
}

void SpiceBuffImplementation::_initializeImplementation() {
	_setClassHelper(SpiceBuffHelper::instance());

	_serializationHelperMethod();
}

void SpiceBuffImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SpiceBuff*) stub;
	BuffImplementation::_setStub(stub);
}

DistributedObjectStub* SpiceBuffImplementation::_getStub() {
	return _this;
}

SpiceBuffImplementation::operator const SpiceBuff*() {
	return _this;
}

TransactionalObject* SpiceBuffImplementation::clone() {
	return (TransactionalObject*) new SpiceBuffImplementation(*this);
}


void SpiceBuffImplementation::lock(bool doLock) {
}

void SpiceBuffImplementation::lock(ManagedObject* obj) {
}

void SpiceBuffImplementation::rlock(bool doLock) {
}

void SpiceBuffImplementation::wlock(bool doLock) {
}

void SpiceBuffImplementation::wlock(ManagedObject* obj) {
}

void SpiceBuffImplementation::unlock(bool doLock) {
}

void SpiceBuffImplementation::runlock(bool doLock) {
}

void SpiceBuffImplementation::_serializationHelperMethod() {
	BuffImplementation::_serializationHelperMethod();

	_setClassName("SpiceBuff");

}

SpiceBuffImplementation::SpiceBuffImplementation(CreatureObject* creo, const String& name, unsigned int buffCRC, int duration) : BuffImplementation(creo, buffCRC, duration, BuffType::SPICE) {
	_initializeImplementation();
	// server/zone/objects/creature/buffs/SpiceBuff.idl(67):  		super.buffName = name;
	BuffImplementation::buffName = name;
}

void SpiceBuffImplementation::activate(bool applyModifiers) {
	// server/zone/objects/creature/buffs/SpiceBuff.idl(71):  		super.creature.sendSystemMessage("spice/spice", super.buffName + "_consume");
	BuffImplementation::creature->sendSystemMessage("spice/spice", BuffImplementation::buffName + "_consume");
	// server/zone/objects/creature/buffs/SpiceBuff.idl(73):  		super.activate(true);
	BuffImplementation::activate(true);
}

/*
 *	SpiceBuffAdapter
 */

SpiceBuffAdapter::SpiceBuffAdapter(SpiceBuffImplementation* obj) : BuffAdapter(obj) {
}

Packet* SpiceBuffAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		activate(inv->getBooleanParameter());
		break;
	case 7:
		deactivate(inv->getBooleanParameter());
		break;
	case 8:
		setDownerAttributes((CreatureObject*) inv->getObjectParameter(), (Buff*) inv->getObjectParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void SpiceBuffAdapter::activate(bool applyModifiers) {
	((SpiceBuffImplementation*) impl)->activate(applyModifiers);
}

void SpiceBuffAdapter::deactivate(bool removeModifiers) {
	((SpiceBuffImplementation*) impl)->deactivate(removeModifiers);
}

void SpiceBuffAdapter::setDownerAttributes(CreatureObject* creature, Buff* buff) {
	((SpiceBuffImplementation*) impl)->setDownerAttributes(creature, buff);
}

/*
 *	SpiceBuffHelper
 */

SpiceBuffHelper* SpiceBuffHelper::staticInitializer = SpiceBuffHelper::instance();

SpiceBuffHelper::SpiceBuffHelper() {
	className = "SpiceBuff";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SpiceBuffHelper::finalizeHelper() {
	SpiceBuffHelper::finalize();
}

DistributedObject* SpiceBuffHelper::instantiateObject() {
	return new SpiceBuff(DummyConstructorParameter::instance());
}

DistributedObjectServant* SpiceBuffHelper::instantiateServant() {
	return new SpiceBuffImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SpiceBuffHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SpiceBuffAdapter((SpiceBuffImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

