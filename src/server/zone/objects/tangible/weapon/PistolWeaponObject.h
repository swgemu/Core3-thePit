/*
 *	server/zone/objects/tangible/weapon/PistolWeaponObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef PISTOLWEAPONOBJECT_H_
#define PISTOLWEAPONOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "server/zone/objects/tangible/weapon/RangedWeaponObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class PistolWeaponObject : public RangedWeaponObject {
public:
	PistolWeaponObject();

	void initializeTransientMembers();

protected:
	PistolWeaponObject(DummyConstructorParameter* param);

	virtual ~PistolWeaponObject();

	TransactionalObject* clone();

	friend class PistolWeaponObjectHelper;
	friend class TransactionalObjectHandle<PistolWeaponObject>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class PistolWeaponObjectImplementation : public RangedWeaponObjectImplementation {

public:
	PistolWeaponObjectImplementation();

	PistolWeaponObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	PistolWeaponObject* _this;

	operator const PistolWeaponObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PistolWeaponObjectImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class PistolWeaponObject;
};

class PistolWeaponObjectAdapter : public RangedWeaponObjectAdapter {
public:
	PistolWeaponObjectAdapter(PistolWeaponObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

};

class PistolWeaponObjectHelper : public DistributedObjectClassHelper, public Singleton<PistolWeaponObjectHelper> {
	static PistolWeaponObjectHelper* staticInitializer;

public:
	PistolWeaponObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PistolWeaponObjectHelper>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

#endif /*PISTOLWEAPONOBJECT_H_*/
