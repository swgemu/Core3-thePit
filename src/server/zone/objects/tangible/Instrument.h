/*
 *	server/zone/objects/tangible/Instrument.h generated by engine3 IDL compiler 0.60
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class Instrument : public TangibleObject {
public:
	Instrument();

	void initializeTransientMembers();

protected:
	Instrument(DummyConstructorParameter* param);

	virtual ~Instrument();

	TransactionalObject* clone();

	friend class InstrumentHelper;
	friend class TransactionalObjectHandle<Instrument>;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class InstrumentImplementation : public TangibleObjectImplementation {

public:
	InstrumentImplementation();

	InstrumentImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	Instrument* _this;

	operator const Instrument*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~InstrumentImplementation();

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

	friend class Instrument;
};

class InstrumentAdapter : public TangibleObjectAdapter {
public:
	InstrumentAdapter(InstrumentImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

};

class InstrumentHelper : public DistributedObjectClassHelper, public Singleton<InstrumentHelper> {
	static InstrumentHelper* staticInitializer;

public:
	InstrumentHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<InstrumentHelper>;
};

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

#endif /*INSTRUMENT_H_*/
