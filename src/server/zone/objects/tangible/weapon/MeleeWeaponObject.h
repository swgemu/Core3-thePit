/*
 *	server/zone/objects/tangible/weapon/MeleeWeaponObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef MELEEWEAPONOBJECT_H_
#define MELEEWEAPONOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "server/zone/objects/tangible/weapon/WeaponObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace weapon {

class MeleeWeaponObject : public WeaponObject {
public:
	MeleeWeaponObject();

	void initializeTransientMembers();

protected:
	MeleeWeaponObject(DummyConstructorParameter* param);

	virtual ~MeleeWeaponObject();

	TransactionalObject* clone();

	friend class MeleeWeaponObjectHelper;
	friend class TransactionalObjectHandle<MeleeWeaponObject>;
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

class MeleeWeaponObjectImplementation : public WeaponObjectImplementation {

public:
	MeleeWeaponObjectImplementation();

	MeleeWeaponObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	MeleeWeaponObject* _this;

	operator const MeleeWeaponObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~MeleeWeaponObjectImplementation();

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

	friend class MeleeWeaponObject;
};

class MeleeWeaponObjectAdapter : public WeaponObjectAdapter {
public:
	MeleeWeaponObjectAdapter(MeleeWeaponObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

};

class MeleeWeaponObjectHelper : public DistributedObjectClassHelper, public Singleton<MeleeWeaponObjectHelper> {
	static MeleeWeaponObjectHelper* staticInitializer;

public:
	MeleeWeaponObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<MeleeWeaponObjectHelper>;
};

} // namespace weapon
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::weapon;

#endif /*MELEEWEAPONOBJECT_H_*/
