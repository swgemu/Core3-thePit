/*
 *	server/zone/objects/area/DynamicSpawnArea.cpp generated by engine3 IDL compiler 0.60
 */

#include "DynamicSpawnArea.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/object/ObjectManager.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "system/lang/Time.h"

#include "engine/util/Quaternion.h"

#include "server/zone/ZoneClientSession.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	DynamicSpawnAreaStub
 */

DynamicSpawnArea::DynamicSpawnArea() : ActiveArea(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new DynamicSpawnAreaImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

DynamicSpawnArea::DynamicSpawnArea(DummyConstructorParameter* param) : ActiveArea(param) {
}

DynamicSpawnArea::~DynamicSpawnArea() {
}


void DynamicSpawnArea::spawnCreature(unsigned int templateCRC) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addUnsignedIntParameter(templateCRC);

		method.executeWithVoidReturn();
	} else
		((DynamicSpawnAreaImplementation*) _getImplementation())->spawnCreature(templateCRC);
}

void DynamicSpawnArea::notifyPositionUpdate(QuadTreeEntry* obj) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((DynamicSpawnAreaImplementation*) _getImplementation())->notifyPositionUpdate(obj);
}

void DynamicSpawnArea::notifyDissapear(QuadTreeEntry* entry) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((DynamicSpawnAreaImplementation*) _getImplementation())->notifyDissapear(entry);
}

void DynamicSpawnArea::setMaxCreaturesToSpawn(int num) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(num);

		method.executeWithVoidReturn();
	} else
		((DynamicSpawnAreaImplementation*) _getImplementation())->setMaxCreaturesToSpawn(num);
}

/*
 *	DynamicSpawnAreaImplementation
 */

DynamicSpawnAreaImplementation::DynamicSpawnAreaImplementation(DummyConstructorParameter* param) : ActiveAreaImplementation(param) {
	_initializeImplementation();
}


DynamicSpawnAreaImplementation::~DynamicSpawnAreaImplementation() {
}


void DynamicSpawnAreaImplementation::finalize() {
}

void DynamicSpawnAreaImplementation::_initializeImplementation() {
	_setClassHelper(DynamicSpawnAreaHelper::instance());

	_serializationHelperMethod();
}

void DynamicSpawnAreaImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DynamicSpawnArea*) stub;
	ActiveAreaImplementation::_setStub(stub);
}

DistributedObjectStub* DynamicSpawnAreaImplementation::_getStub() {
	return _this;
}

DynamicSpawnAreaImplementation::operator const DynamicSpawnArea*() {
	return _this;
}

TransactionalObject* DynamicSpawnAreaImplementation::clone() {
	return (TransactionalObject*) new DynamicSpawnAreaImplementation(*this);
}


void DynamicSpawnAreaImplementation::lock(bool doLock) {
}

void DynamicSpawnAreaImplementation::lock(ManagedObject* obj) {
}

void DynamicSpawnAreaImplementation::rlock(bool doLock) {
}

void DynamicSpawnAreaImplementation::wlock(bool doLock) {
}

void DynamicSpawnAreaImplementation::wlock(ManagedObject* obj) {
}

void DynamicSpawnAreaImplementation::unlock(bool doLock) {
}

void DynamicSpawnAreaImplementation::runlock(bool doLock) {
}

void DynamicSpawnAreaImplementation::_serializationHelperMethod() {
	ActiveAreaImplementation::_serializationHelperMethod();

	_setClassName("DynamicSpawnArea");

	addSerializableVariable("spawnCreatureTemplates", &spawnCreatureTemplates);
	addSerializableVariable("lastSpawnTime", &lastSpawnTime);
	addSerializableVariable("spawnedCreatures", &spawnedCreatures);
	addSerializableVariable("maxCreaturesToSpawn", &maxCreaturesToSpawn);
}

DynamicSpawnAreaImplementation::DynamicSpawnAreaImplementation() {
	_initializeImplementation();
	// server/zone/objects/area/DynamicSpawnArea.idl(64):  		spawnedCreatures = 0;
	spawnedCreatures = 0;
	// server/zone/objects/area/DynamicSpawnArea.idl(65):  		maxCreaturesToSpawn = 1;
	maxCreaturesToSpawn = 1;
}

void DynamicSpawnAreaImplementation::spawnCreature(unsigned int templateCRC) {
	// server/zone/objects/area/DynamicSpawnArea.idl(69):  		++spawnedCreatures;
	 ++spawnedCreatures;
}

void DynamicSpawnAreaImplementation::notifyPositionUpdate(QuadTreeEntry* obj) {
	// server/zone/objects/area/DynamicSpawnArea.idl(74):  		unsigned 
	if (spawnedCreatures + 1 > maxCreaturesToSpawn)	// server/zone/objects/area/DynamicSpawnArea.idl(75):  			return;
	return;
	// server/zone/objects/area/DynamicSpawnArea.idl(77):  int templateCRC = spawnCreatureTemplates.get(System.random(spawnCreatureTemplates.size() - 1));
	unsigned int templateCRC = (&spawnCreatureTemplates)->get(System::random((&spawnCreatureTemplates)->size() - 1));
	// server/zone/objects/area/DynamicSpawnArea.idl(79):  		spawnCreature(templateCRC);
	spawnCreature(templateCRC);
}

void DynamicSpawnAreaImplementation::notifyDissapear(QuadTreeEntry* entry) {
	// server/zone/objects/area/DynamicSpawnArea.idl(84):  	}
	if (spawnedCreatures == 0)	// server/zone/objects/area/DynamicSpawnArea.idl(85):  			return;
	return;
}

void DynamicSpawnAreaImplementation::setMaxCreaturesToSpawn(int num) {
	// server/zone/objects/area/DynamicSpawnArea.idl(91):  		maxCreaturesToSpawn = num;
	maxCreaturesToSpawn = num;
}

/*
 *	DynamicSpawnAreaAdapter
 */

DynamicSpawnAreaAdapter::DynamicSpawnAreaAdapter(DynamicSpawnAreaImplementation* obj) : ActiveAreaAdapter(obj) {
}

Packet* DynamicSpawnAreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		spawnCreature(inv->getUnsignedIntParameter());
		break;
	case 7:
		setMaxCreaturesToSpawn(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DynamicSpawnAreaAdapter::spawnCreature(unsigned int templateCRC) {
	((DynamicSpawnAreaImplementation*) impl)->spawnCreature(templateCRC);
}

void DynamicSpawnAreaAdapter::setMaxCreaturesToSpawn(int num) {
	((DynamicSpawnAreaImplementation*) impl)->setMaxCreaturesToSpawn(num);
}

/*
 *	DynamicSpawnAreaHelper
 */

DynamicSpawnAreaHelper* DynamicSpawnAreaHelper::staticInitializer = DynamicSpawnAreaHelper::instance();

DynamicSpawnAreaHelper::DynamicSpawnAreaHelper() {
	className = "DynamicSpawnArea";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DynamicSpawnAreaHelper::finalizeHelper() {
	DynamicSpawnAreaHelper::finalize();
}

DistributedObject* DynamicSpawnAreaHelper::instantiateObject() {
	return new DynamicSpawnArea(DummyConstructorParameter::instance());
}

DistributedObjectServant* DynamicSpawnAreaHelper::instantiateServant() {
	return new DynamicSpawnAreaImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DynamicSpawnAreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DynamicSpawnAreaAdapter((DynamicSpawnAreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

