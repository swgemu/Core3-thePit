/*
 *	server/chat/room/ChatRoom.h generated by engine3 IDL compiler 0.60
 */

#ifndef CHATROOM_H_
#define CHATROOM_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "engine/core/ManagedObject.h"

#include "system/util/VectorMap.h"

#include "system/util/Vector.h"

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace chat {
namespace room {

class ChatRoom : public ManagedObject {
public:
	ChatRoom();

	void init(ZoneServer* serv, ChatRoom* par, const String& roomName, unsigned int channelID);

	void sendTo(PlayerCreature* player);

	void sendDestroyTo(PlayerCreature* player);

	void addSubRoom(ChatRoom* channel);

	void removeSubRoom(ChatRoom* channel);

	ChatRoom* getSubRoom(int i);

	ChatRoom* getSubRoom(const String& name);

	void addPlayer(PlayerCreature* player, bool doLock = true);

	void removePlayer(PlayerCreature* player, bool doLock = true);

	void removePlayer(const String& player);

	void broadcastMessage(BaseMessage* msg);

	void broadcastMessages(Vector<BaseMessage*>* messages);

	bool hasPlayer(PlayerCreature* player);

	bool hasPlayer(const String& name);

	void removeAllPlayers();

	void setPrivate();

	void setPublic();

	bool isPublic();

	bool isPrivate();

	PlayerCreature* getPlayer(int idx);

	int getPlayerSize();

	void setName(const String& Name);

	String getName();

	String getFullPath();

	String getOwner();

	String getCreator();

	UnicodeString getTitle();

	String getServerName();

	void setOwner(const String& Owner);

	void setCreator(const String& Creator);

	void setTitle(const String& Title);

	void setRoomID(int id);

	unsigned int getRoomID();

	int getSubRoomsSize();

	ChatRoom* getParent();

	int compareTo(ChatRoom* obj);

protected:
	ChatRoom(DummyConstructorParameter* param);

	virtual ~ChatRoom();

	TransactionalObject* clone();

	String _return_getCreator;
	String _return_getFullPath;
	String _return_getName;
	String _return_getOwner;
	String _return_getServerName;

	UnicodeString _return_getTitle;

	friend class ChatRoomHelper;
	friend class TransactionalObjectHandle<ChatRoom>;
};

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

namespace server {
namespace chat {
namespace room {

class ChatRoomImplementation : public ManagedObjectImplementation {
protected:
	ManagedReference<ZoneServer > server;

	String name;

	String fullPath;

	String owner;

	String creator;

	UnicodeString title;

	unsigned int roomID;

	ManagedReference<ChatRoom > parent;

	VectorMap<String, ManagedReference<PlayerCreature > > playerList;

	VectorMap<String, ManagedReference<ChatRoom > > subRooms;

	bool isPublicRoom;

public:
	ChatRoomImplementation();

	ChatRoomImplementation(DummyConstructorParameter* param);

	void init(ZoneServer* serv, ChatRoom* par, const String& roomName, unsigned int channelID);

	void sendTo(PlayerCreature* player);

	void sendDestroyTo(PlayerCreature* player);

	void addSubRoom(ChatRoom* channel);

	void removeSubRoom(ChatRoom* channel);

	ChatRoom* getSubRoom(int i);

	ChatRoom* getSubRoom(const String& name);

	void addPlayer(PlayerCreature* player, bool doLock = true);

	void removePlayer(PlayerCreature* player, bool doLock = true);

	void removePlayer(const String& player);

	void broadcastMessage(BaseMessage* msg);

	void broadcastMessages(Vector<BaseMessage*>* messages);

	bool hasPlayer(PlayerCreature* player);

	bool hasPlayer(const String& name);

	void removeAllPlayers();

	void setPrivate();

	void setPublic();

	bool isPublic();

	bool isPrivate();

	PlayerCreature* getPlayer(int idx);

	int getPlayerSize();

	void setName(const String& Name);

	String getName();

	String getFullPath();

	String getOwner();

	String getCreator();

	UnicodeString getTitle();

	String getServerName();

	void setOwner(const String& Owner);

	void setCreator(const String& Creator);

	void setTitle(const String& Title);

	void setRoomID(int id);

	unsigned int getRoomID();

	int getSubRoomsSize();

	ChatRoom* getParent();

	int compareTo(ChatRoom* obj);

	ChatRoom* _this;

	operator const ChatRoom*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~ChatRoomImplementation();

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

	friend class ChatRoom;
};

class ChatRoomAdapter : public ManagedObjectAdapter {
public:
	ChatRoomAdapter(ChatRoomImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void init(ZoneServer* serv, ChatRoom* par, const String& roomName, unsigned int channelID);

	void sendTo(PlayerCreature* player);

	void sendDestroyTo(PlayerCreature* player);

	void addSubRoom(ChatRoom* channel);

	void removeSubRoom(ChatRoom* channel);

	ChatRoom* getSubRoom(int i);

	ChatRoom* getSubRoom(const String& name);

	void addPlayer(PlayerCreature* player, bool doLock);

	void removePlayer(PlayerCreature* player, bool doLock);

	void removePlayer(const String& player);

	void broadcastMessage(BaseMessage* msg);

	bool hasPlayer(PlayerCreature* player);

	bool hasPlayer(const String& name);

	void removeAllPlayers();

	void setPrivate();

	void setPublic();

	bool isPublic();

	bool isPrivate();

	PlayerCreature* getPlayer(int idx);

	int getPlayerSize();

	void setName(const String& Name);

	String getName();

	String getFullPath();

	String getOwner();

	String getCreator();

	UnicodeString getTitle();

	String getServerName();

	void setOwner(const String& Owner);

	void setCreator(const String& Creator);

	void setTitle(const String& Title);

	void setRoomID(int id);

	unsigned int getRoomID();

	int getSubRoomsSize();

	ChatRoom* getParent();

	int compareTo(ChatRoom* obj);

protected:
	String _param2_init__ZoneServer_ChatRoom_String_int_;
	String _param0_getSubRoom__String_;
	String _param0_removePlayer__String_;
	String _param0_hasPlayer__String_;
	String _param0_setName__String_;
	String _param0_setOwner__String_;
	String _param0_setCreator__String_;
	String _param0_setTitle__String_;
};

class ChatRoomHelper : public DistributedObjectClassHelper, public Singleton<ChatRoomHelper> {
	static ChatRoomHelper* staticInitializer;

public:
	ChatRoomHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<ChatRoomHelper>;
};

} // namespace room
} // namespace chat
} // namespace server

using namespace server::chat::room;

#endif /*CHATROOM_H_*/
