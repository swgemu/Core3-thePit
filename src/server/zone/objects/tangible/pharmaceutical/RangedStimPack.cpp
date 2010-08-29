/*
 *	server/zone/objects/tangible/pharmaceutical/RangedStimPack.cpp generated by engine3 IDL compiler 0.60
 */

#include "RangedStimPack.h"

#include "server/zone/objects/tangible/TangibleObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"


// Imported class dependencies

#include "server/zone/ZoneProcessServerImplementation.h"

#include "server/zone/managers/planet/MapLocationTable.h"

#include "system/thread/atomic/AtomicInteger.h"

#include "engine/core/ObjectUpdateToDatabaseTask.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/creature/variables/CooldownTimerMap.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/managers/object/ObjectMap.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/creature/damageovertime/DamageOverTimeList.h"

#include "server/zone/objects/scene/variables/PendingTasksMap.h"

#include "server/zone/managers/mission/MissionManager.h"

#include "server/zone/managers/radial/RadialManager.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "engine/service/proto/BasePacketHandler.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/area/ActiveArea.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "system/util/VectorMap.h"

#include "server/zone/objects/group/GroupObject.h"

#include "server/zone/objects/creature/variables/SkillBoxList.h"

#include "server/zone/objects/tangible/tool/CraftingTool.h"

#include "engine/util/Quaternion.h"

#include "system/util/SortedVector.h"

#include "server/zone/objects/manufactureschematic/IngredientSlots.h"

#include "system/util/Vector.h"

#include "engine/core/TaskManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/player/events/PlayerRecoveryEvent.h"

#include "server/zone/objects/scene/variables/CustomizationVariables.h"

#include "server/zone/objects/tangible/tool/SurveyTool.h"

#include "server/zone/managers/crafting/CraftingManager.h"

#include "server/zone/managers/minigames/FishingManager.h"

#include "system/lang/Time.h"

#include "server/chat/ChatManager.h"

#include "server/zone/objects/scene/variables/StringId.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/managers/planet/HeightMap.h"

#include "server/zone/managers/bazaar/BazaarManager.h"

#include "server/zone/objects/player/TradeContainer.h"

#include "server/zone/objects/player/events/PlayerDisconnectEvent.h"

#include "server/zone/managers/resource/ResourceManager.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/objects/intangible/ControlDevice.h"

#include "server/zone/managers/planet/PlanetManager.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/ZoneClientSession.h"

#include "server/zone/objects/creature/buffs/BuffList.h"

#include "server/zone/Zone.h"

#include "server/zone/objects/scene/ObserverEventMap.h"

#include "server/zone/objects/player/badges/Badges.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/managers/creature/CreatureManager.h"

#include "server/zone/objects/tangible/TangibleObject.h"

/*
 *	RangedStimPackStub
 */

RangedStimPack::RangedStimPack() : StimPack(DummyConstructorParameter::instance()) {
	ManagedObject::_setImplementation(new RangedStimPackImplementation());
	ManagedObject::_getImplementation()->_setStub(this);
}

RangedStimPack::RangedStimPack(DummyConstructorParameter* param) : StimPack(param) {
}

RangedStimPack::~RangedStimPack() {
}


void RangedStimPack::updateCraftingValues(ManufactureSchematic* schematic) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((RangedStimPackImplementation*) _getImplementation())->updateCraftingValues(schematic);
}

void RangedStimPack::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((RangedStimPackImplementation*) _getImplementation())->fillAttributeList(msg, object);
}

void RangedStimPack::loadTemplateData(SharedObjectTemplate* templateData) {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		((RangedStimPackImplementation*) _getImplementation())->loadTemplateData(templateData);
}

unsigned int RangedStimPack::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(healer);
		method.addObjectParameter(patient);
		method.addBooleanParameter(applyBattleFatigue);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->calculatePower(healer, patient, applyBattleFatigue);
}

float RangedStimPack::getRange(CreatureObject* creature) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(creature);

		return method.executeWithFloatReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->getRange(creature);
}

float RangedStimPack::getEffectiveness() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithFloatReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->getEffectiveness();
}

float RangedStimPack::getArea() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->getArea();
}

bool RangedStimPack::isArea() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);

		return method.executeWithBooleanReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->isArea();
}

float RangedStimPack::getRangeMod() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		return method.executeWithFloatReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->getRangeMod();
}

bool RangedStimPack::isRangedStimPack() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return ((RangedStimPackImplementation*) _getImplementation())->isRangedStimPack();
}

/*
 *	RangedStimPackImplementation
 */

RangedStimPackImplementation::RangedStimPackImplementation(DummyConstructorParameter* param) : StimPackImplementation(param) {
	_initializeImplementation();
}


RangedStimPackImplementation::~RangedStimPackImplementation() {
}


void RangedStimPackImplementation::finalize() {
}

void RangedStimPackImplementation::_initializeImplementation() {
	_setClassHelper(RangedStimPackHelper::instance());

	_serializationHelperMethod();
}

void RangedStimPackImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (RangedStimPack*) stub;
	StimPackImplementation::_setStub(stub);
}

DistributedObjectStub* RangedStimPackImplementation::_getStub() {
	return _this;
}

RangedStimPackImplementation::operator const RangedStimPack*() {
	return _this;
}

TransactionalObject* RangedStimPackImplementation::clone() {
	return (TransactionalObject*) new RangedStimPackImplementation(*this);
}


void RangedStimPackImplementation::lock(bool doLock) {
}

void RangedStimPackImplementation::lock(ManagedObject* obj) {
}

void RangedStimPackImplementation::rlock(bool doLock) {
}

void RangedStimPackImplementation::wlock(bool doLock) {
}

void RangedStimPackImplementation::wlock(ManagedObject* obj) {
}

void RangedStimPackImplementation::unlock(bool doLock) {
}

void RangedStimPackImplementation::runlock(bool doLock) {
}

void RangedStimPackImplementation::_serializationHelperMethod() {
	StimPackImplementation::_serializationHelperMethod();

	_setClassName("RangedStimPack");

	addSerializableVariable("effectiveness", &effectiveness);
	addSerializableVariable("range", &range);
	addSerializableVariable("area", &area);
	addSerializableVariable("rangeMod", &rangeMod);
}

RangedStimPackImplementation::RangedStimPackImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(68):  		setLoggingName("RangedStimPack");
	setLoggingName("RangedStimPack");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(70):  		effectiveness = 0;
	effectiveness = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(71):  		area = 0;
	area = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(72):  		range = 0;
	range = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(73):  		rangeMod = 0;
	rangeMod = 0;
}

void RangedStimPackImplementation::updateCraftingValues(ManufactureSchematic* schematic) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(78):  		CraftingValues craftingValues = schematic.getCraftingValues();
	CraftingValues* craftingValues = schematic->getCraftingValues();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(80):  		effectiveness = craftingValues.getCurrentValue("power");
	effectiveness = craftingValues->getCurrentValue("power");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(81):  		super.medicineUseRequired = craftingValues.getCurrentValue("skillmodmin");
	StimPackImplementation::medicineUseRequired = craftingValues->getCurrentValue("skillmodmin");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(82):  		super.useCount = craftingValues.getCurrentValue("charges");
	StimPackImplementation::useCount = craftingValues->getCurrentValue("charges");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(84):  		range = craftingValues.getCurrentValue("range");
	range = craftingValues->getCurrentValue("range");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(86):  	}
	if (craftingValues->hasProperty("area")){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(87):  			area = craftingValues.getCurrentValue("area");
	area = craftingValues->getCurrentValue("area");
}
}

void RangedStimPackImplementation::fillAttributeList(AttributeListMessage* msg, PlayerCreature* object) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(100):  		super.fillAttributeList(msg, object);
	StimPackImplementation::fillAttributeList(msg, object);
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(102):  		msg.insertAttribute("examine_heal_damage_health", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_health", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(103):  		msg.insertAttribute("examine_heal_damage_action", Math.getPrecision(effectiveness, 0));
	msg->insertAttribute("examine_heal_damage_action", Math::getPrecision(effectiveness, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(104):  		msg.insertAttribute("examine_heal_range", Math.getPrecision(range, 0));
	msg->insertAttribute("examine_heal_range", Math::getPrecision(range, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(106):  
	if (isArea()){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(107):  			msg.insertAttribute("examine_heal_area", Math.getPrecision(area, 0));
	msg->insertAttribute("examine_heal_area", Math::getPrecision(area, 0));
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(108):  			msg.insertAttribute("combat_healing_ability", super.medicineUseRequired);
	msg->insertAttribute("combat_healing_ability", StimPackImplementation::medicineUseRequired);
}

	else {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(110):  			msg.insertAttribute("combat_healing_ability", super.medicineUseRequired);
	msg->insertAttribute("combat_healing_ability", StimPackImplementation::medicineUseRequired);
}
}

void RangedStimPackImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(122):  		super.loadTemplateData(templateData);
	StimPackImplementation::loadTemplateData(templateData);
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(124):  		RangedStimPackTemplate 
	if (!templateData->isRangedStimPackTemplate())	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(125):  			return;
	return;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(127):  stimPackTemplate = (RangedStimPackTemplate) templateData;
	RangedStimPackTemplate* stimPackTemplate = (RangedStimPackTemplate*) templateData;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(129):  		effectiveness = stimPackTemplate.getEffectiveness();
	effectiveness = stimPackTemplate->getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(130):  		super.medicineUseRequired = stimPackTemplate.getMedicineUse();
	StimPackImplementation::medicineUseRequired = stimPackTemplate->getMedicineUse();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(131):  		area = stimPackTemplate.getArea();
	area = stimPackTemplate->getArea();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(132):  		range = stimPackTemplate.getRange();
	range = stimPackTemplate->getRange();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(133):  		rangeMod = stimPackTemplate.getRangeMod();
	rangeMod = stimPackTemplate->getRangeMod();
}

unsigned int RangedStimPackImplementation::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(137):  		float power = getEffectiveness();
	float power = getEffectiveness();
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(139):  		float 
	if (applyBattleFatigue){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(140):  			power = power - power * patient.calculateBFRatio();
	power = power - power * patient->calculateBFRatio();
}
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(143):  modSkill = (float) healer.getSkillMod("combat_medic_effectiveness");
	float modSkill = (float) healer->getSkillMod("combat_medic_effectiveness");
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(145):  		return (100 + modSkill) / 100 * power;
	return (100 + modSkill) / 100 * power;
}

float RangedStimPackImplementation::getRange(CreatureObject* creature) {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(149):  		float modSkill = 0;
	float modSkill = 0;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(151):  		float 
	if (creature != NULL){
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(152):  			modSkill = creature.getSkillMod("healing_range");
	modSkill = creature->getSkillMod("healing_range");
}
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(155):  value = (100 + rangeMod * modSkill) / 100 * range;
	float value = (100 + rangeMod * modSkill) / 100 * range;
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(157):  		return value;
	return value;
}

float RangedStimPackImplementation::getEffectiveness() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(161):  		return effectiveness;
	return effectiveness;
}

float RangedStimPackImplementation::getArea() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(165):  		return area;
	return area;
}

bool RangedStimPackImplementation::isArea() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(169):  		return area != 0;
	return area != 0;
}

float RangedStimPackImplementation::getRangeMod() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(173):  		return rangeMod;
	return rangeMod;
}

bool RangedStimPackImplementation::isRangedStimPack() {
	// server/zone/objects/tangible/pharmaceutical/RangedStimPack.idl(177):  		return true;
	return true;
}

/*
 *	RangedStimPackAdapter
 */

RangedStimPackAdapter::RangedStimPackAdapter(RangedStimPackImplementation* obj) : StimPackAdapter(obj) {
}

Packet* RangedStimPackAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertInt(calculatePower((CreatureObject*) inv->getObjectParameter(), (CreatureObject*) inv->getObjectParameter(), inv->getBooleanParameter()));
		break;
	case 7:
		resp->insertFloat(getRange((CreatureObject*) inv->getObjectParameter()));
		break;
	case 8:
		resp->insertFloat(getEffectiveness());
		break;
	case 9:
		resp->insertFloat(getArea());
		break;
	case 10:
		resp->insertBoolean(isArea());
		break;
	case 11:
		resp->insertFloat(getRangeMod());
		break;
	case 12:
		resp->insertBoolean(isRangedStimPack());
		break;
	default:
		return NULL;
	}

	return resp;
}

unsigned int RangedStimPackAdapter::calculatePower(CreatureObject* healer, CreatureObject* patient, bool applyBattleFatigue) {
	return ((RangedStimPackImplementation*) impl)->calculatePower(healer, patient, applyBattleFatigue);
}

float RangedStimPackAdapter::getRange(CreatureObject* creature) {
	return ((RangedStimPackImplementation*) impl)->getRange(creature);
}

float RangedStimPackAdapter::getEffectiveness() {
	return ((RangedStimPackImplementation*) impl)->getEffectiveness();
}

float RangedStimPackAdapter::getArea() {
	return ((RangedStimPackImplementation*) impl)->getArea();
}

bool RangedStimPackAdapter::isArea() {
	return ((RangedStimPackImplementation*) impl)->isArea();
}

float RangedStimPackAdapter::getRangeMod() {
	return ((RangedStimPackImplementation*) impl)->getRangeMod();
}

bool RangedStimPackAdapter::isRangedStimPack() {
	return ((RangedStimPackImplementation*) impl)->isRangedStimPack();
}

/*
 *	RangedStimPackHelper
 */

RangedStimPackHelper* RangedStimPackHelper::staticInitializer = RangedStimPackHelper::instance();

RangedStimPackHelper::RangedStimPackHelper() {
	className = "RangedStimPack";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void RangedStimPackHelper::finalizeHelper() {
	RangedStimPackHelper::finalize();
}

DistributedObject* RangedStimPackHelper::instantiateObject() {
	return new RangedStimPack(DummyConstructorParameter::instance());
}

DistributedObjectServant* RangedStimPackHelper::instantiateServant() {
	return new RangedStimPackImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* RangedStimPackHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new RangedStimPackAdapter((RangedStimPackImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

