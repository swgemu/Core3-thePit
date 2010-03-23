/*
 *	server/zone/objects/tangible/TangibleObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "TangibleObject.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/player/PlayerCreature.h"

/*
 *	TangibleObjectStub
 */

TangibleObject::TangibleObject() : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new TangibleObjectImplementation();
	_impl->_setStub(this);
}

TangibleObject::TangibleObject(DummyConstructorParameter* param) : SceneObject(param) {
}

TangibleObject::~TangibleObject() {
}


TransactionalObject* TangibleObject::clone() {
	TangibleObject* objectCopy = new TangibleObject(DummyConstructorParameter::instance());
	objectCopy->_impl = new TangibleObjectImplementation(DummyConstructorParameter::instance());
	*(objectCopy->_impl) = *_impl;
	return (TransactionalObject*) objectCopy;
}


void TangibleObject::loadTemplateData(LuaObject* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((TangibleObjectImplementation*) _impl)->loadTemplateData(templateData);
}

void TangibleObject::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->initializeTransientMembers();
}

void TangibleObject::sendBaselinesTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->sendBaselinesTo(player);
}

void TangibleObject::setDefender(SceneObject* defender) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->setDefender(defender);
}

void TangibleObject::addDefender(SceneObject* defender) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->addDefender(defender);
}

void TangibleObject::removeDefender(SceneObject* defender) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(defender);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->removeDefender(defender);
}

void TangibleObject::removeDefenders() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->removeDefenders();
}

void TangibleObject::setCombatState() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->setCombatState();
}

void TangibleObject::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((TangibleObjectImplementation*) _impl)->fillAttributeList(msg, object);
}

void TangibleObject::clearCombatState(bool clearDefenders) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addBooleanParameter(clearDefenders);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->clearCombatState(clearDefenders);
}

bool TangibleObject::hasDefender(SceneObject* defender) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(defender);

		return method.executeWithBooleanReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->hasDefender(defender);
}

byte TangibleObject::getUnknownByte() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithByteReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getUnknownByte();
}

CustomizationVariables* TangibleObject::getCustomizationVariables() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((TangibleObjectImplementation*) _impl)->getCustomizationVariables();
}

int TangibleObject::getObjectCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		return method.executeWithSignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getObjectCount();
}

int TangibleObject::getMaxCondition() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		return method.executeWithSignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getMaxCondition();
}

int TangibleObject::getConditionDamage() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);

		return method.executeWithSignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getConditionDamage();
}

int TangibleObject::getVolume() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);

		return method.executeWithSignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getVolume();
}

float TangibleObject::getComplexity() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		return method.executeWithFloatReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getComplexity();
}

unsigned int TangibleObject::getOptionsBitmask() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getOptionsBitmask();
}

unsigned int TangibleObject::getPvpStatusBitmask() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getPvpStatusBitmask();
}

bool TangibleObject::isTangibleObject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		return method.executeWithBooleanReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->isTangibleObject();
}

void TangibleObject::getCustomizationString(String& variables) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addAsciiParameter(variables);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->getCustomizationString(variables);
}

DeltaVector<ManagedReference<SceneObject > >* TangibleObject::getDefenderList() {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return ((TangibleObjectImplementation*) _impl)->getDefenderList();
}

unsigned int TangibleObject::getPlayerUseMask() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->getPlayerUseMask();
}

bool TangibleObject::isSliced() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);

		return method.executeWithBooleanReturn();
	} else
		return ((TangibleObjectImplementation*) _impl)->isSliced();
}

void TangibleObject::setCustomizationString(const String& vars) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addAsciiParameter(vars);

		method.executeWithVoidReturn();
	} else
		((TangibleObjectImplementation*) _impl)->setCustomizationString(vars);
}

/*
 *	TangibleObjectImplementation
 */

TangibleObjectImplementation::TangibleObjectImplementation(DummyConstructorParameter* param) : SceneObjectImplementation(param) {
	_initializeImplementation();
}

TangibleObjectImplementation::~TangibleObjectImplementation() {
}


void TangibleObjectImplementation::finalize() {
}

void TangibleObjectImplementation::_initializeImplementation() {
	_setClassHelper(TangibleObjectHelper::instance());

	_serializationHelperMethod();
}

void TangibleObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (TangibleObject*) stub;
	SceneObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TangibleObjectImplementation::_getStub() {
	return _this;
}

TangibleObjectImplementation::operator const TangibleObject*() {
	return _this;
}

void TangibleObjectImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void TangibleObjectImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void TangibleObjectImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void TangibleObjectImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void TangibleObjectImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void TangibleObjectImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void TangibleObjectImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void TangibleObjectImplementation::_serializationHelperMethod() {
	SceneObjectImplementation::_serializationHelperMethod();

	_setClassName("TangibleObject");

	addSerializableVariable("targetable", &targetable);
	addSerializableVariable("complexity", &complexity);
	addSerializableVariable("volume", &volume);
	addSerializableVariable("customizationVariables", &customizationVariables);
	addSerializableVariable("conditionDamage", &conditionDamage);
	addSerializableVariable("maxCondition", &maxCondition);
	addSerializableVariable("objectCount", &objectCount);
	addSerializableVariable("optionsBitmask", &optionsBitmask);
	addSerializableVariable("pvpStatusBitmask", &pvpStatusBitmask);
	addSerializableVariable("unknownByte", &unknownByte);
	addSerializableVariable("craftersName", &craftersName);
	addSerializableVariable("defenderList", &defenderList);
	addSerializableVariable("playerUseMask", &playerUseMask);
	addSerializableVariable("sliced", &sliced);
}

TangibleObjectImplementation::TangibleObjectImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/TangibleObject.idl(130):  		Logger.setLoggingName("TangibleObject");
	Logger::setLoggingName("TangibleObject");
}

void TangibleObjectImplementation::setCombatState() {
}

void TangibleObjectImplementation::clearCombatState(bool clearDefenders) {
	// server/zone/objects/tangible/TangibleObject.idl(214):  	}
	if (clearDefenders)	// server/zone/objects/tangible/TangibleObject.idl(215):  			removeDefenders();
	removeDefenders();
}

bool TangibleObjectImplementation::hasDefender(SceneObject* defender) {
	// server/zone/objects/tangible/TangibleObject.idl(225):  
	for (	// server/zone/objects/tangible/TangibleObject.idl(225):  		for (int i = 0;
	int i = 0;
	i < (&defenderList)->size();
 ++i) {
	// server/zone/objects/tangible/TangibleObject.idl(226):  		}
	if ((&defenderList)->get(i) == defender)	// server/zone/objects/tangible/TangibleObject.idl(227):  				return true;
	return true;
}
	// server/zone/objects/tangible/TangibleObject.idl(230):  		return false;
	return false;
}

byte TangibleObjectImplementation::getUnknownByte() {
	// server/zone/objects/tangible/TangibleObject.idl(234):  		return unknownByte;
	return unknownByte;
}

CustomizationVariables* TangibleObjectImplementation::getCustomizationVariables() {
	// server/zone/objects/tangible/TangibleObject.idl(240):  		return customizationVariables;
	return (&customizationVariables);
}

int TangibleObjectImplementation::getObjectCount() {
	// server/zone/objects/tangible/TangibleObject.idl(244):  		return objectCount;
	return objectCount;
}

int TangibleObjectImplementation::getMaxCondition() {
	// server/zone/objects/tangible/TangibleObject.idl(248):  		return maxCondition;
	return maxCondition;
}

int TangibleObjectImplementation::getConditionDamage() {
	// server/zone/objects/tangible/TangibleObject.idl(252):  		return conditionDamage;
	return conditionDamage;
}

int TangibleObjectImplementation::getVolume() {
	// server/zone/objects/tangible/TangibleObject.idl(256):  		return volume;
	return volume;
}

float TangibleObjectImplementation::getComplexity() {
	// server/zone/objects/tangible/TangibleObject.idl(260):  		return complexity;
	return complexity;
}

unsigned int TangibleObjectImplementation::getOptionsBitmask() {
	// server/zone/objects/tangible/TangibleObject.idl(264):  		return optionsBitmask;
	return optionsBitmask;
}

unsigned int TangibleObjectImplementation::getPvpStatusBitmask() {
	// server/zone/objects/tangible/TangibleObject.idl(268):  		return pvpStatusBitmask;
	return pvpStatusBitmask;
}

bool TangibleObjectImplementation::isTangibleObject() {
	// server/zone/objects/tangible/TangibleObject.idl(272):  		return true;
	return true;
}

void TangibleObjectImplementation::getCustomizationString(String& variables) {
	// server/zone/objects/tangible/TangibleObject.idl(276):  		customizationVariables.getData(variables);
	(&customizationVariables)->getData(variables);
}

DeltaVector<ManagedReference<SceneObject > >* TangibleObjectImplementation::getDefenderList() {
	// server/zone/objects/tangible/TangibleObject.idl(281):  		return defenderList;
	return (&defenderList);
}

unsigned int TangibleObjectImplementation::getPlayerUseMask() {
	// server/zone/objects/tangible/TangibleObject.idl(285):  		return playerUseMask;
	return playerUseMask;
}

bool TangibleObjectImplementation::isSliced() {
	// server/zone/objects/tangible/TangibleObject.idl(289):  		return sliced;
	return sliced;
}

void TangibleObjectImplementation::setCustomizationString(const String& vars) {
	// server/zone/objects/tangible/TangibleObject.idl(293):  		customizationVariables.parseFromClientString(vars);
	(&customizationVariables)->parseFromClientString(vars);
}

/*
 *	TangibleObjectAdapter
 */

TangibleObjectAdapter::TangibleObjectAdapter(TangibleObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* TangibleObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case 8:
		setDefender((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		addDefender((SceneObject*) inv->getObjectParameter());
		break;
	case 10:
		removeDefender((SceneObject*) inv->getObjectParameter());
		break;
	case 11:
		removeDefenders();
		break;
	case 12:
		setCombatState();
		break;
	case 13:
		clearCombatState(inv->getBooleanParameter());
		break;
	case 14:
		resp->insertBoolean(hasDefender((SceneObject*) inv->getObjectParameter()));
		break;
	case 15:
		resp->insertByte(getUnknownByte());
		break;
	case 16:
		resp->insertSignedInt(getObjectCount());
		break;
	case 17:
		resp->insertSignedInt(getMaxCondition());
		break;
	case 18:
		resp->insertSignedInt(getConditionDamage());
		break;
	case 19:
		resp->insertSignedInt(getVolume());
		break;
	case 20:
		resp->insertFloat(getComplexity());
		break;
	case 21:
		resp->insertInt(getOptionsBitmask());
		break;
	case 22:
		resp->insertInt(getPvpStatusBitmask());
		break;
	case 23:
		resp->insertBoolean(isTangibleObject());
		break;
	case 24:
		getCustomizationString(inv->getAsciiParameter(_param0_getCustomizationString__String_));
		break;
	case 25:
		resp->insertInt(getPlayerUseMask());
		break;
	case 26:
		resp->insertBoolean(isSliced());
		break;
	case 27:
		setCustomizationString(inv->getAsciiParameter(_param0_setCustomizationString__String_));
		break;
	default:
		return NULL;
	}

	return resp;
}

void TangibleObjectAdapter::initializeTransientMembers() {
	((TangibleObjectImplementation*) impl)->initializeTransientMembers();
}

void TangibleObjectAdapter::sendBaselinesTo(SceneObject* player) {
	((TangibleObjectImplementation*) impl)->sendBaselinesTo(player);
}

void TangibleObjectAdapter::setDefender(SceneObject* defender) {
	((TangibleObjectImplementation*) impl)->setDefender(defender);
}

void TangibleObjectAdapter::addDefender(SceneObject* defender) {
	((TangibleObjectImplementation*) impl)->addDefender(defender);
}

void TangibleObjectAdapter::removeDefender(SceneObject* defender) {
	((TangibleObjectImplementation*) impl)->removeDefender(defender);
}

void TangibleObjectAdapter::removeDefenders() {
	((TangibleObjectImplementation*) impl)->removeDefenders();
}

void TangibleObjectAdapter::setCombatState() {
	((TangibleObjectImplementation*) impl)->setCombatState();
}

void TangibleObjectAdapter::clearCombatState(bool clearDefenders) {
	((TangibleObjectImplementation*) impl)->clearCombatState(clearDefenders);
}

bool TangibleObjectAdapter::hasDefender(SceneObject* defender) {
	return ((TangibleObjectImplementation*) impl)->hasDefender(defender);
}

byte TangibleObjectAdapter::getUnknownByte() {
	return ((TangibleObjectImplementation*) impl)->getUnknownByte();
}

int TangibleObjectAdapter::getObjectCount() {
	return ((TangibleObjectImplementation*) impl)->getObjectCount();
}

int TangibleObjectAdapter::getMaxCondition() {
	return ((TangibleObjectImplementation*) impl)->getMaxCondition();
}

int TangibleObjectAdapter::getConditionDamage() {
	return ((TangibleObjectImplementation*) impl)->getConditionDamage();
}

int TangibleObjectAdapter::getVolume() {
	return ((TangibleObjectImplementation*) impl)->getVolume();
}

float TangibleObjectAdapter::getComplexity() {
	return ((TangibleObjectImplementation*) impl)->getComplexity();
}

unsigned int TangibleObjectAdapter::getOptionsBitmask() {
	return ((TangibleObjectImplementation*) impl)->getOptionsBitmask();
}

unsigned int TangibleObjectAdapter::getPvpStatusBitmask() {
	return ((TangibleObjectImplementation*) impl)->getPvpStatusBitmask();
}

bool TangibleObjectAdapter::isTangibleObject() {
	return ((TangibleObjectImplementation*) impl)->isTangibleObject();
}

void TangibleObjectAdapter::getCustomizationString(String& variables) {
	((TangibleObjectImplementation*) impl)->getCustomizationString(variables);
}

unsigned int TangibleObjectAdapter::getPlayerUseMask() {
	return ((TangibleObjectImplementation*) impl)->getPlayerUseMask();
}

bool TangibleObjectAdapter::isSliced() {
	return ((TangibleObjectImplementation*) impl)->isSliced();
}

void TangibleObjectAdapter::setCustomizationString(const String& vars) {
	((TangibleObjectImplementation*) impl)->setCustomizationString(vars);
}

/*
 *	TangibleObjectHelper
 */

TangibleObjectHelper* TangibleObjectHelper::staticInitializer = TangibleObjectHelper::instance();

TangibleObjectHelper::TangibleObjectHelper() {
	className = "TangibleObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void TangibleObjectHelper::finalizeHelper() {
	TangibleObjectHelper::finalize();
}

DistributedObject* TangibleObjectHelper::instantiateObject() {
	return new TangibleObject(DummyConstructorParameter::instance());
}

DistributedObjectServant* TangibleObjectHelper::instantiateServant() {
	return new TangibleObjectImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TangibleObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TangibleObjectAdapter((TangibleObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

