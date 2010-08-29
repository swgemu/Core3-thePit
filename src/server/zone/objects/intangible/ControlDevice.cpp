/*
 *	server/zone/objects/intangible/ControlDevice.cpp generated by engine3 IDL compiler 0.60
 */

#include "ControlDevice.h"

#include "server/zone/objects/creature/VehicleObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/ZoneServer.h"

#include "system/lang/Time.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "engine/util/Quaternion.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/ZoneClientSession.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

/*
 *	ControlDeviceStub
 */

ControlDevice::ControlDevice() : IntangibleObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new ControlDeviceImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

ControlDevice::ControlDevice(DummyConstructorParameter* param) : IntangibleObject(param) {
}

ControlDevice::~ControlDevice() {
}


void ControlDevice::updateToDatabaseAllObjects(bool startTask) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(startTask);

		method.executeWithVoidReturn();
	} else
		((ControlDeviceImplementation*) _getImplementation())->updateToDatabaseAllObjects(startTask);
}

void ControlDevice::storeObject(PlayerCreature* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ControlDeviceImplementation*) _getImplementation())->storeObject(player);
}

void ControlDevice::generateObject(PlayerCreature* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ControlDeviceImplementation*) _getImplementation())->generateObject(player);
}

void ControlDevice::setControlledObject(CreatureObject* object) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(object);

		method.executeWithVoidReturn();
	} else
		((ControlDeviceImplementation*) _getImplementation())->setControlledObject(object);
}

CreatureObject* ControlDevice::getControlledObject() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return (CreatureObject*) method.executeWithObjectReturn();
	} else
		return ((ControlDeviceImplementation*) _getImplementation())->getControlledObject();
}

bool ControlDevice::isControlDevice() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithBooleanReturn();
	} else
		return ((ControlDeviceImplementation*) _getImplementation())->isControlDevice();
}

/*
 *	ControlDeviceImplementation
 */

ControlDeviceImplementation::ControlDeviceImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


ControlDeviceImplementation::~ControlDeviceImplementation() {
}


void ControlDeviceImplementation::finalize() {
}

void ControlDeviceImplementation::_initializeImplementation() {
	_setClassHelper(ControlDeviceHelper::instance());

	_serializationHelperMethod();
}

void ControlDeviceImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ControlDevice*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ControlDeviceImplementation::_getStub() {
	return _this;
}

ControlDeviceImplementation::operator const ControlDevice*() {
	return _this;
}

TransactionalObject* ControlDeviceImplementation::clone() {
	return (TransactionalObject*) new ControlDeviceImplementation(*this);
}


void ControlDeviceImplementation::lock(bool doLock) {
}

void ControlDeviceImplementation::lock(ManagedObject* obj) {
}

void ControlDeviceImplementation::rlock(bool doLock) {
}

void ControlDeviceImplementation::wlock(bool doLock) {
}

void ControlDeviceImplementation::wlock(ManagedObject* obj) {
}

void ControlDeviceImplementation::unlock(bool doLock) {
}

void ControlDeviceImplementation::runlock(bool doLock) {
}

void ControlDeviceImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("ControlDevice");

	addSerializableVariable("controlledObject", &controlledObject);
}

ControlDeviceImplementation::ControlDeviceImplementation() {
	_initializeImplementation();
	// server/zone/objects/intangible/ControlDevice.idl(61):  		controlledObject = null;
	controlledObject = NULL;
	// server/zone/objects/intangible/ControlDevice.idl(63):  		Logger.setLoggingName("ControlDevice");
	Logger::setLoggingName("ControlDevice");
	// server/zone/objects/intangible/ControlDevice.idl(64):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/intangible/ControlDevice.idl(65):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
}

void ControlDeviceImplementation::updateToDatabaseAllObjects(bool startTask) {
	// server/zone/objects/intangible/ControlDevice.idl(75):  		controlledObject.updateToDatabaseWithoutChildren();
	controlledObject->updateToDatabaseWithoutChildren();
	// server/zone/objects/intangible/ControlDevice.idl(77):  		super.updateToDatabaseAllObjects(startTask);
	IntangibleObjectImplementation::updateToDatabaseAllObjects(startTask);
}

void ControlDeviceImplementation::storeObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl(81):  		Logger.error("called storeObject on an abstract method");
	Logger::error("called storeObject on an abstract method");
}

void ControlDeviceImplementation::generateObject(PlayerCreature* player) {
	// server/zone/objects/intangible/ControlDevice.idl(85):  		Logger.error("called generateObject on an abstract method");
	Logger::error("called generateObject on an abstract method");
}

void ControlDeviceImplementation::setControlledObject(CreatureObject* object) {
	// server/zone/objects/intangible/ControlDevice.idl(89):  		controlledObject = object;
	controlledObject = object;
}

CreatureObject* ControlDeviceImplementation::getControlledObject() {
	// server/zone/objects/intangible/ControlDevice.idl(93):  		return controlledObject;
	return controlledObject;
}

bool ControlDeviceImplementation::isControlDevice() {
	// server/zone/objects/intangible/ControlDevice.idl(97):  		return true;
	return true;
}

/*
 *	ControlDeviceAdapter
 */

ControlDeviceAdapter::ControlDeviceAdapter(ControlDeviceImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* ControlDeviceAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		updateToDatabaseAllObjects(inv->getBooleanParameter());
		break;
	case 7:
		storeObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 8:
		generateObject((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		setControlledObject((CreatureObject*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(getControlledObject()->_getObjectID());
		break;
	case 11:
		resp->insertBoolean(isControlDevice());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ControlDeviceAdapter::updateToDatabaseAllObjects(bool startTask) {
	((ControlDeviceImplementation*) impl)->updateToDatabaseAllObjects(startTask);
}

void ControlDeviceAdapter::storeObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->storeObject(player);
}

void ControlDeviceAdapter::generateObject(PlayerCreature* player) {
	((ControlDeviceImplementation*) impl)->generateObject(player);
}

void ControlDeviceAdapter::setControlledObject(CreatureObject* object) {
	((ControlDeviceImplementation*) impl)->setControlledObject(object);
}

CreatureObject* ControlDeviceAdapter::getControlledObject() {
	return ((ControlDeviceImplementation*) impl)->getControlledObject();
}

bool ControlDeviceAdapter::isControlDevice() {
	return ((ControlDeviceImplementation*) impl)->isControlDevice();
}

/*
 *	ControlDeviceHelper
 */

ControlDeviceHelper* ControlDeviceHelper::staticInitializer = ControlDeviceHelper::instance();

ControlDeviceHelper::ControlDeviceHelper() {
	className = "ControlDevice";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ControlDeviceHelper::finalizeHelper() {
	ControlDeviceHelper::finalize();
}

DistributedObject* ControlDeviceHelper::instantiateObject() {
	return new ControlDevice(DummyConstructorParameter::instance());
}

DistributedObjectServant* ControlDeviceHelper::instantiateServant() {
	return new ControlDeviceImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ControlDeviceHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ControlDeviceAdapter((ControlDeviceImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

