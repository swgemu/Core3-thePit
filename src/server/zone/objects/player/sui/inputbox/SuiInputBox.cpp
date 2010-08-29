/*
 *	server/zone/objects/player/sui/inputbox/SuiInputBox.cpp generated by engine3 IDL compiler 0.60
 */

#include "SuiInputBox.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/PlayerCreature.h"

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

#include "system/util/Vector.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	SuiInputBoxStub
 */

SuiInputBox::SuiInputBox(PlayerCreature* player, unsigned int windowType, int inputtype) : SuiBox(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new SuiInputBoxImplementation(player, windowType, inputtype));
	ManagedObject::_getImplementation()->_setStub(this);
}

SuiInputBox::SuiInputBox(DummyConstructorParameter* param) : SuiBox(param) {
}

SuiInputBox::~SuiInputBox() {
}


BaseMessage* SuiInputBox::generateMessage() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return (BaseMessage*) method.executeWithObjectReturn();
	} else
		return ((SuiInputBoxImplementation*) _getImplementation())->generateMessage();
}

void SuiInputBox::setMaxInputSize(int size) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addSignedIntParameter(size);

		method.executeWithVoidReturn();
	} else
		((SuiInputBoxImplementation*) _getImplementation())->setMaxInputSize(size);
}

void SuiInputBox::setDefaultInput(const String& text) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(text);

		method.executeWithVoidReturn();
	} else
		((SuiInputBoxImplementation*) _getImplementation())->setDefaultInput(text);
}

bool SuiInputBox::isFilterBox() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiInputBoxImplementation*) _getImplementation())->isFilterBox();
}

bool SuiInputBox::isInputBox() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return ((SuiInputBoxImplementation*) _getImplementation())->isInputBox();
}

/*
 *	SuiInputBoxImplementation
 */

SuiInputBoxImplementation::SuiInputBoxImplementation(DummyConstructorParameter* param) : SuiBoxImplementation(param) {
	_initializeImplementation();
}


SuiInputBoxImplementation::~SuiInputBoxImplementation() {
}


void SuiInputBoxImplementation::finalize() {
}

void SuiInputBoxImplementation::_initializeImplementation() {
	_setClassHelper(SuiInputBoxHelper::instance());

	_serializationHelperMethod();
}

void SuiInputBoxImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (SuiInputBox*) stub;
	SuiBoxImplementation::_setStub(stub);
}

DistributedObjectStub* SuiInputBoxImplementation::_getStub() {
	return _this;
}

SuiInputBoxImplementation::operator const SuiInputBox*() {
	return _this;
}

TransactionalObject* SuiInputBoxImplementation::clone() {
	return (TransactionalObject*) new SuiInputBoxImplementation(*this);
}


void SuiInputBoxImplementation::lock(bool doLock) {
}

void SuiInputBoxImplementation::lock(ManagedObject* obj) {
}

void SuiInputBoxImplementation::rlock(bool doLock) {
}

void SuiInputBoxImplementation::wlock(bool doLock) {
}

void SuiInputBoxImplementation::wlock(ManagedObject* obj) {
}

void SuiInputBoxImplementation::unlock(bool doLock) {
}

void SuiInputBoxImplementation::runlock(bool doLock) {
}

void SuiInputBoxImplementation::_serializationHelperMethod() {
	SuiBoxImplementation::_serializationHelperMethod();

	_setClassName("SuiInputBox");

	addSerializableVariable("maxInputSize", &maxInputSize);
	addSerializableVariable("defaultInput", &defaultInput);
	addSerializableVariable("inputType", &inputType);
}

SuiInputBoxImplementation::SuiInputBoxImplementation(PlayerCreature* player, unsigned int windowType, int inputtype) : SuiBoxImplementation(player, windowType, SuiBox::INPUTBOX) {
	_initializeImplementation();
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(66):  		maxInputSize = 25;
	maxInputSize = 25;
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(68):  		inputType = inputtype;
	inputType = inputtype;
}

void SuiInputBoxImplementation::setMaxInputSize(int size) {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(74):  		maxInputSize = size;
	maxInputSize = size;
}

void SuiInputBoxImplementation::setDefaultInput(const String& text) {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(78):  		defaultInput = text;
	defaultInput = text;
}

bool SuiInputBoxImplementation::isFilterBox() {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(82):  		return inputType == FILTER;
	return inputType == FILTER;
}

bool SuiInputBoxImplementation::isInputBox() {
	// server/zone/objects/player/sui/inputbox/SuiInputBox.idl(86):  		return true;
	return true;
}

/*
 *	SuiInputBoxAdapter
 */

SuiInputBoxAdapter::SuiInputBoxAdapter(SuiInputBoxImplementation* obj) : SuiBoxAdapter(obj) {
}

Packet* SuiInputBoxAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertLong(generateMessage()->_getObjectID());
		break;
	case 7:
		setMaxInputSize(inv->getSignedIntParameter());
		break;
	case 8:
		setDefaultInput(inv->getAsciiParameter(_param0_setDefaultInput__String_));
		break;
	case 9:
		resp->insertBoolean(isFilterBox());
		break;
	case 10:
		resp->insertBoolean(isInputBox());
		break;
	default:
		return NULL;
	}

	return resp;
}

BaseMessage* SuiInputBoxAdapter::generateMessage() {
	return ((SuiInputBoxImplementation*) impl)->generateMessage();
}

void SuiInputBoxAdapter::setMaxInputSize(int size) {
	((SuiInputBoxImplementation*) impl)->setMaxInputSize(size);
}

void SuiInputBoxAdapter::setDefaultInput(const String& text) {
	((SuiInputBoxImplementation*) impl)->setDefaultInput(text);
}

bool SuiInputBoxAdapter::isFilterBox() {
	return ((SuiInputBoxImplementation*) impl)->isFilterBox();
}

bool SuiInputBoxAdapter::isInputBox() {
	return ((SuiInputBoxImplementation*) impl)->isInputBox();
}

/*
 *	SuiInputBoxHelper
 */

SuiInputBoxHelper* SuiInputBoxHelper::staticInitializer = SuiInputBoxHelper::instance();

SuiInputBoxHelper::SuiInputBoxHelper() {
	className = "SuiInputBox";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SuiInputBoxHelper::finalizeHelper() {
	SuiInputBoxHelper::finalize();
}

DistributedObject* SuiInputBoxHelper::instantiateObject() {
	return new SuiInputBox(DummyConstructorParameter::instance());
}

DistributedObjectServant* SuiInputBoxHelper::instantiateServant() {
	return new SuiInputBoxImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SuiInputBoxHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SuiInputBoxAdapter((SuiInputBoxImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

