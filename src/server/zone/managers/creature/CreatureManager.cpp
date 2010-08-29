/*
 *	server/zone/managers/creature/CreatureManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "CreatureManager.h"

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/packets/MessageCallback.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/creature/NonPlayerCreatureObject.h"

#include "server/zone/objects/creature/AiAgent.h"

#include "server/zone/Zone.h"

#include "server/zone/managers/objectcontroller/ObjectController.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "server/zone/objects/creature/events/DespawnCreatureOnPlayerDissappear.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "server/zone/objects/creature/events/AiMoveEvent.h"

#include "system/lang/Time.h"

#include "server/chat/ChatManager.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/managers/objectcontroller/command/CommandList.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/templates/tangible/NonPlayerCreatureObjectTemplate.h"

#include "server/zone/managers/bazaar/BazaarManager.h"

#include "server/zone/objects/tangible/DamageMap.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/objects/creature/PatrolPoint.h"

#include "engine/core/TaskManager.h"

#include "system/util/Vector.h"

#include "server/zone/objects/creature/events/AiThinkEvent.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/creature/PatrolPointsVector.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/managers/objectcontroller/command/CommandConfigManager.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

/*
 *	CreatureManagerStub
 */

CreatureManager::CreatureManager(Zone* planet, ZoneProcessServerImplementation* impl) : ManagedObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new CreatureManagerImplementation(planet, impl));
	ManagedObject::_getImplementation()->_setStub(this);
}

CreatureManager::CreatureManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

CreatureManager::~CreatureManager() {
}


void CreatureManager::initialize() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _getImplementation())->initialize();
}

CreatureObject* CreatureManager::spawnCreature(unsigned int templateCRC, float x, float z, float y, unsigned long long parentID) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addUnsignedIntParameter(templateCRC);
		method.addFloatParameter(x);
		method.addFloatParameter(z);
		method.addFloatParameter(y);
		method.addUnsignedLongParameter(parentID);

		return (CreatureObject*) method.executeWithObjectReturn();
	} else
		return ((CreatureManagerImplementation*) _getImplementation())->spawnCreature(templateCRC, x, z, y, parentID);
}

int CreatureManager::notifyDestruction(TangibleObject* destructor, AiAgent* destructedObject, int condition) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((CreatureManagerImplementation*) _getImplementation())->notifyDestruction(destructor, destructedObject, condition);
}

void CreatureManager::loadDynamicSpawnAreas() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _getImplementation())->loadDynamicSpawnAreas();
}

void CreatureManager::loadSingleSpawns() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _getImplementation())->loadSingleSpawns();
}

void CreatureManager::loadTrainers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		method.executeWithVoidReturn();
	} else
		((CreatureManagerImplementation*) _getImplementation())->loadTrainers();
}

/*
 *	CreatureManagerImplementation
 */

CreatureManagerImplementation::CreatureManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


CreatureManagerImplementation::~CreatureManagerImplementation() {
}


void CreatureManagerImplementation::finalize() {
}

void CreatureManagerImplementation::_initializeImplementation() {
	_setClassHelper(CreatureManagerHelper::instance());

	_serializationHelperMethod();
}

void CreatureManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (CreatureManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* CreatureManagerImplementation::_getStub() {
	return _this;
}

CreatureManagerImplementation::operator const CreatureManager*() {
	return _this;
}

TransactionalObject* CreatureManagerImplementation::clone() {
	return (TransactionalObject*) new CreatureManagerImplementation(*this);
}


void CreatureManagerImplementation::lock(bool doLock) {
}

void CreatureManagerImplementation::lock(ManagedObject* obj) {
}

void CreatureManagerImplementation::rlock(bool doLock) {
}

void CreatureManagerImplementation::wlock(bool doLock) {
}

void CreatureManagerImplementation::wlock(ManagedObject* obj) {
}

void CreatureManagerImplementation::unlock(bool doLock) {
}

void CreatureManagerImplementation::runlock(bool doLock) {
}

void CreatureManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("CreatureManager");

	addSerializableVariable("server", &server);
	addSerializableVariable("zone", &zone);
}

CreatureManagerImplementation::CreatureManagerImplementation(Zone* planet, ZoneProcessServerImplementation* impl) {
	_initializeImplementation();
	// server/zone/managers/creature/CreatureManager.idl(30):  		server = planet.getZoneServer();
	server = planet->getZoneServer();
	// server/zone/managers/creature/CreatureManager.idl(31):  		processor = impl;
	processor = impl;
	// server/zone/managers/creature/CreatureManager.idl(32):  		zone = planet;
	zone = planet;
	// server/zone/managers/creature/CreatureManager.idl(34):  		Logger.setLoggingName("CreatureManager");
	Logger::setLoggingName("CreatureManager");
	// server/zone/managers/creature/CreatureManager.idl(35):  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
	// server/zone/managers/creature/CreatureManager.idl(36):  		Logger.setLogging(false);
	Logger::setLogging(false);
}

void CreatureManagerImplementation::initialize() {
}

/*
 *	CreatureManagerAdapter
 */

CreatureManagerAdapter::CreatureManagerAdapter(CreatureManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* CreatureManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initialize();
		break;
	case 7:
		resp->insertLong(spawnCreature(inv->getUnsignedIntParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getUnsignedLongParameter())->_getObjectID());
		break;
	case 8:
		loadDynamicSpawnAreas();
		break;
	case 9:
		loadSingleSpawns();
		break;
	case 10:
		loadTrainers();
		break;
	default:
		return NULL;
	}

	return resp;
}

void CreatureManagerAdapter::initialize() {
	((CreatureManagerImplementation*) impl)->initialize();
}

CreatureObject* CreatureManagerAdapter::spawnCreature(unsigned int templateCRC, float x, float z, float y, unsigned long long parentID) {
	return ((CreatureManagerImplementation*) impl)->spawnCreature(templateCRC, x, z, y, parentID);
}

void CreatureManagerAdapter::loadDynamicSpawnAreas() {
	((CreatureManagerImplementation*) impl)->loadDynamicSpawnAreas();
}

void CreatureManagerAdapter::loadSingleSpawns() {
	((CreatureManagerImplementation*) impl)->loadSingleSpawns();
}

void CreatureManagerAdapter::loadTrainers() {
	((CreatureManagerImplementation*) impl)->loadTrainers();
}

/*
 *	CreatureManagerHelper
 */

CreatureManagerHelper* CreatureManagerHelper::staticInitializer = CreatureManagerHelper::instance();

CreatureManagerHelper::CreatureManagerHelper() {
	className = "CreatureManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureManagerHelper::finalizeHelper() {
	CreatureManagerHelper::finalize();
}

DistributedObject* CreatureManagerHelper::instantiateObject() {
	return new CreatureManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* CreatureManagerHelper::instantiateServant() {
	return new CreatureManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CreatureManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CreatureManagerAdapter((CreatureManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

