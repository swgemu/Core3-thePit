/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.60
 */

#include "DraftSchematic.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/player/PlayerCreature.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "engine/util/Quaternion.h"

#include "system/lang/Time.h"

#include "system/util/SortedVector.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "system/util/Vector.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

/*
 *	DraftSchematicStub
 */

DraftSchematic::DraftSchematic() : IntangibleObject(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new DraftSchematicImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

DraftSchematic::DraftSchematic(DummyConstructorParameter* param) : IntangibleObject(param) {
}

DraftSchematic::~DraftSchematic() {
}


void DraftSchematic::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _getImplementation())->initializeTransientMembers();
}

void DraftSchematic::loadTemplateData(SharedObjectTemplate* templateData) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((DraftSchematicImplementation*) _getImplementation())->loadTemplateData(templateData);
}

void DraftSchematic::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((DraftSchematicImplementation*) _getImplementation())->fillAttributeList(msg, object);
}

void DraftSchematic::sendBaselinesTo(SceneObject* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _getImplementation())->sendBaselinesTo(player);
}

void DraftSchematic::sendDraftSlotsTo(PlayerCreature* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _getImplementation())->sendDraftSlotsTo(player);
}

void DraftSchematic::sendResourceWeightsTo(PlayerCreature* player) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _getImplementation())->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematic::createManufactureSchematic(SceneObject* craftingTool) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(craftingTool);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->createManufactureSchematic(craftingTool);
}

void DraftSchematic::setSchematicID(unsigned int id) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		((DraftSchematicImplementation*) _getImplementation())->setSchematicID(id);
}

unsigned int DraftSchematic::getSchematicID() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getSchematicID();
}

int DraftSchematic::getDraftSlotCount() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getDraftSlotCount();
}

DraftSlot* DraftSchematic::getDraftSlot(int i) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getDraftSlot(i);
}

int DraftSchematic::getResourceWeightCount() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getResourceWeightCount();
}

ResourceWeight* DraftSchematic::getResourceWeight(int i) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getResourceWeight(i);
}

float DraftSchematic::getComplexity() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getComplexity();
}

unsigned int DraftSchematic::getToolTab() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getToolTab();
}

float DraftSchematic::getSize() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithFloatReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getSize();
}

String DraftSchematic::getXpType() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		method.executeWithAsciiReturn(_return_getXpType);
		return _return_getXpType;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getXpType();
}

int DraftSchematic::getXpAmount() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithSignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getXpAmount();
}

String DraftSchematic::getAssemblySkill() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		method.executeWithAsciiReturn(_return_getAssemblySkill);
		return _return_getAssemblySkill;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getAssemblySkill();
}

String DraftSchematic::getExperimentationSkill() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		method.executeWithAsciiReturn(_return_getExperimentationSkill);
		return _return_getExperimentationSkill;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getExperimentationSkill();
}

String DraftSchematic::getCustomizationSkill() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		method.executeWithAsciiReturn(_return_getCustomizationSkill);
		return _return_getCustomizationSkill;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getCustomizationSkill();
}

Vector<byte>* DraftSchematic::getCustomizationOptions() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getCustomizationOptions();
}

Vector<String>* DraftSchematic::getCustomizationStringNames() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getCustomizationStringNames();
}

Vector<byte>* DraftSchematic::getCustomizationDefaultValues() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getCustomizationDefaultValues();
}

String DraftSchematic::getCustomName() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		method.executeWithAsciiReturn(_return_getCustomName);
		return _return_getCustomName;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getCustomName();
}

unsigned int DraftSchematic::getTanoCRC() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getTanoCRC();
}

String DraftSchematic::getGroupName() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return ((DraftSchematicImplementation*) _getImplementation())->getGroupName();
}

/*
 *	DraftSchematicImplementation
 */

DraftSchematicImplementation::DraftSchematicImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


DraftSchematicImplementation::~DraftSchematicImplementation() {
}


void DraftSchematicImplementation::finalize() {
}

void DraftSchematicImplementation::_initializeImplementation() {
	_setClassHelper(DraftSchematicHelper::instance());

	_serializationHelperMethod();
}

void DraftSchematicImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DraftSchematicImplementation::_getStub() {
	return _this;
}

DraftSchematicImplementation::operator const DraftSchematic*() {
	return _this;
}

TransactionalObject* DraftSchematicImplementation::clone() {
	return (TransactionalObject*) new DraftSchematicImplementation(*this);
}


void DraftSchematicImplementation::lock(bool doLock) {
}

void DraftSchematicImplementation::lock(ManagedObject* obj) {
}

void DraftSchematicImplementation::rlock(bool doLock) {
}

void DraftSchematicImplementation::wlock(bool doLock) {
}

void DraftSchematicImplementation::wlock(ManagedObject* obj) {
}

void DraftSchematicImplementation::unlock(bool doLock) {
}

void DraftSchematicImplementation::runlock(bool doLock) {
}

void DraftSchematicImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("DraftSchematic");

	addSerializableVariable("schematicID", &schematicID);
}

DraftSchematicImplementation::DraftSchematicImplementation() {
	_initializeImplementation();
	// server/zone/objects/draftschematic/DraftSchematic.idl(68):  		Logger.setLoggingName("DraftSchematic");
	Logger::setLoggingName("DraftSchematic");
}

void DraftSchematicImplementation::setSchematicID(unsigned int id) {
	// server/zone/objects/draftschematic/DraftSchematic.idl(126):  		schematicID = id;
	schematicID = id;
}

unsigned int DraftSchematicImplementation::getSchematicID() {
	// server/zone/objects/draftschematic/DraftSchematic.idl(134):  		return schematicID;
	return schematicID;
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		sendDraftSlotsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 9:
		sendResourceWeightsTo((PlayerCreature*) inv->getObjectParameter());
		break;
	case 10:
		resp->insertLong(createManufactureSchematic((SceneObject*) inv->getObjectParameter())->_getObjectID());
		break;
	case 11:
		setSchematicID(inv->getUnsignedIntParameter());
		break;
	case 12:
		resp->insertInt(getSchematicID());
		break;
	case 13:
		resp->insertSignedInt(getDraftSlotCount());
		break;
	case 14:
		resp->insertSignedInt(getResourceWeightCount());
		break;
	case 15:
		resp->insertFloat(getComplexity());
		break;
	case 16:
		resp->insertInt(getToolTab());
		break;
	case 17:
		resp->insertFloat(getSize());
		break;
	case 18:
		resp->insertAscii(getXpType());
		break;
	case 19:
		resp->insertSignedInt(getXpAmount());
		break;
	case 20:
		resp->insertAscii(getAssemblySkill());
		break;
	case 21:
		resp->insertAscii(getExperimentationSkill());
		break;
	case 22:
		resp->insertAscii(getCustomizationSkill());
		break;
	case 23:
		resp->insertAscii(getCustomName());
		break;
	case 24:
		resp->insertInt(getTanoCRC());
		break;
	case 25:
		resp->insertAscii(getGroupName());
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicAdapter::initializeTransientMembers() {
	((DraftSchematicImplementation*) impl)->initializeTransientMembers();
}

void DraftSchematicAdapter::sendBaselinesTo(SceneObject* player) {
	((DraftSchematicImplementation*) impl)->sendBaselinesTo(player);
}

void DraftSchematicAdapter::sendDraftSlotsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendDraftSlotsTo(player);
}

void DraftSchematicAdapter::sendResourceWeightsTo(PlayerCreature* player) {
	((DraftSchematicImplementation*) impl)->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematicAdapter::createManufactureSchematic(SceneObject* craftingTool) {
	return ((DraftSchematicImplementation*) impl)->createManufactureSchematic(craftingTool);
}

void DraftSchematicAdapter::setSchematicID(unsigned int id) {
	((DraftSchematicImplementation*) impl)->setSchematicID(id);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

int DraftSchematicAdapter::getDraftSlotCount() {
	return ((DraftSchematicImplementation*) impl)->getDraftSlotCount();
}

int DraftSchematicAdapter::getResourceWeightCount() {
	return ((DraftSchematicImplementation*) impl)->getResourceWeightCount();
}

float DraftSchematicAdapter::getComplexity() {
	return ((DraftSchematicImplementation*) impl)->getComplexity();
}

unsigned int DraftSchematicAdapter::getToolTab() {
	return ((DraftSchematicImplementation*) impl)->getToolTab();
}

float DraftSchematicAdapter::getSize() {
	return ((DraftSchematicImplementation*) impl)->getSize();
}

String DraftSchematicAdapter::getXpType() {
	return ((DraftSchematicImplementation*) impl)->getXpType();
}

int DraftSchematicAdapter::getXpAmount() {
	return ((DraftSchematicImplementation*) impl)->getXpAmount();
}

String DraftSchematicAdapter::getAssemblySkill() {
	return ((DraftSchematicImplementation*) impl)->getAssemblySkill();
}

String DraftSchematicAdapter::getExperimentationSkill() {
	return ((DraftSchematicImplementation*) impl)->getExperimentationSkill();
}

String DraftSchematicAdapter::getCustomizationSkill() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationSkill();
}

String DraftSchematicAdapter::getCustomName() {
	return ((DraftSchematicImplementation*) impl)->getCustomName();
}

unsigned int DraftSchematicAdapter::getTanoCRC() {
	return ((DraftSchematicImplementation*) impl)->getTanoCRC();
}

String DraftSchematicAdapter::getGroupName() {
	return ((DraftSchematicImplementation*) impl)->getGroupName();
}

/*
 *	DraftSchematicHelper
 */

DraftSchematicHelper* DraftSchematicHelper::staticInitializer = DraftSchematicHelper::instance();

DraftSchematicHelper::DraftSchematicHelper() {
	className = "DraftSchematic";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void DraftSchematicHelper::finalizeHelper() {
	DraftSchematicHelper::finalize();
}

DistributedObject* DraftSchematicHelper::instantiateObject() {
	return new DraftSchematic(DummyConstructorParameter::instance());
}

DistributedObjectServant* DraftSchematicHelper::instantiateServant() {
	return new DraftSchematicImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

