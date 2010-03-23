/*
 *	server/chat/ChatManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "ChatManager.h"

#include "server/zone/ZoneServer.h"

#include "server/chat/room/ChatRoom.h"

#include "server/chat/room/ChatRoomMap.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/managers/player/PlayerMap.h"

#include "server/zone/managers/player/PlayerManager.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/packets/chat/ChatRoomList.h"

#include "server/zone/packets/chat/ChatInstantMessageToCharacter.h"

/*
 *	ChatManagerStub
 */

ChatManager::ChatManager(ZoneServer* serv, int initsize) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new ChatManagerImplementation(serv, initsize);
	_impl->_setStub(this);
}

ChatManager::ChatManager(DummyConstructorParameter* param) : ManagedObject(param) {
}

ChatManager::~ChatManager() {
}


TransactionalObject* ChatManager::clone() {
	ChatManager* objectCopy = new ChatManager(DummyConstructorParameter::instance());
	objectCopy->_impl = new ChatManagerImplementation(DummyConstructorParameter::instance());
	*(objectCopy->_impl) = *_impl;
	return (TransactionalObject*) objectCopy;
}


void ChatManager::initiateRooms() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->initiateRooms();
}

void ChatManager::destroyRooms() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->destroyRooms();
}

ChatRoom* ChatManager::createRoom(const String& roomName, ChatRoom* parent) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addAsciiParameter(roomName);
		method.addObjectParameter(parent);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->createRoom(roomName, parent);
}

void ChatManager::addRoom(ChatRoom* channel) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(channel);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->addRoom(channel);
}

void ChatManager::removeRoom(ChatRoom* channel) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addObjectParameter(channel);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->removeRoom(channel);
}

void ChatManager::populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(channel);
		method.addObjectParameter(msg);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->populateRoomListMessage(channel, msg);
}

void ChatManager::sendRoomList(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->sendRoomList(player);
}

void ChatManager::addPlayer(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->addPlayer(player);
}

PlayerCreature* ChatManager::getPlayer(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addAsciiParameter(name);

		return (PlayerCreature*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getPlayer(name);
}

PlayerCreature* ChatManager::removePlayer(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);
		method.addAsciiParameter(name);

		return (PlayerCreature*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->removePlayer(name);
}

void ChatManager::broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target, unsigned int moodid, unsigned int mood2) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);
		method.addObjectParameter(player);
		method.addUnicodeParameter(message);
		method.addUnsignedLongParameter(target);
		method.addUnsignedIntParameter(moodid);
		method.addUnsignedIntParameter(mood2);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->broadcastMessage(player, message, target, moodid, mood2);
}

void ChatManager::handleSpatialChatInternalMessage(PlayerCreature* player, const UnicodeString& args) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);
		method.addObjectParameter(player);
		method.addUnicodeParameter(args);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->handleSpatialChatInternalMessage(player, args);
}

void ChatManager::handleGroupChat(PlayerCreature* player, const UnicodeString& message) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(player);
		method.addUnicodeParameter(message);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->handleGroupChat(player, message);
}

ChatRoom* ChatManager::createRoomByFullPath(const String& path) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addAsciiParameter(path);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->createRoomByFullPath(path);
}

ChatRoom* ChatManager::getChatRoomByFullPath(const String& path) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);
		method.addAsciiParameter(path);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getChatRoomByFullPath(path);
}

ChatRoom* ChatManager::getChatRoomByGamePath(ChatRoom* game, const String& path) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);
		method.addObjectParameter(game);
		method.addAsciiParameter(path);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getChatRoomByGamePath(game, path);
}

void ChatManager::handleChatRoomMessage(PlayerCreature* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);
		method.addObjectParameter(sender);
		method.addUnicodeParameter(message);
		method.addUnsignedIntParameter(roomID);
		method.addUnsignedIntParameter(counter);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->handleChatRoomMessage(sender, message, roomID, counter);
}

void ChatManager::handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);
		method.addObjectParameter(sender);
		method.addUnicodeParameter(arguments);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->handleSocialInternalMessage(sender, arguments);
}

void ChatManager::handleChatInstantMessageToCharacter(ChatInstantMessageToCharacter* message) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ChatManagerImplementation*) _impl)->handleChatInstantMessageToCharacter(message);
}

void ChatManager::destroyRoom(ChatRoom* room) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addObjectParameter(room);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->destroyRoom(room);
}

ChatRoom* ChatManager::createGroupRoom(unsigned long long groupID, PlayerCreature* creator) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addUnsignedLongParameter(groupID);
		method.addObjectParameter(creator);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->createGroupRoom(groupID, creator);
}

void ChatManager::loadMail(PlayerCreature* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->loadMail(player);
}

void ChatManager::sendMail(const String& sendername, UnicodeString& header, UnicodeString& body, const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addAsciiParameter(sendername);
		method.addUnicodeParameter(header);
		method.addUnicodeParameter(body);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->sendMail(sendername, header, body, name);
}

void ChatManager::handleRequestPersistentMsg(PlayerCreature* player, unsigned int mailID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(mailID);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->handleRequestPersistentMsg(player, mailID);
}

void ChatManager::deletePersistentMessage(PlayerCreature* player, unsigned int mailID) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(mailID);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->deletePersistentMessage(player, mailID);
}

void ChatManager::setPlayerManager(PlayerManager* manager) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);
		method.addObjectParameter(manager);

		method.executeWithVoidReturn();
	} else
		((ChatManagerImplementation*) _impl)->setPlayerManager(manager);
}

ChatRoom* ChatManager::getChatRoom(unsigned int id) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);
		method.addUnsignedIntParameter(id);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getChatRoom(id);
}

ChatRoom* ChatManager::getGameRoom(const String& game) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);
		method.addAsciiParameter(game);

		return (ChatRoom*) method.executeWithObjectReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getGameRoom(game);
}

unsigned int ChatManager::getNextRoomID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getNextRoomID();
}

int ChatManager::getPlayerCount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return method.executeWithSignedIntReturn();
	} else
		return ((ChatManagerImplementation*) _impl)->getPlayerCount();
}

/*
 *	ChatManagerImplementation
 */

ChatManagerImplementation::ChatManagerImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}

ChatManagerImplementation::~ChatManagerImplementation() {
	ChatManagerImplementation::finalize();
}


void ChatManagerImplementation::_initializeImplementation() {
	_setClassHelper(ChatManagerHelper::instance());

	_serializationHelperMethod();
}

void ChatManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ChatManager*) stub;
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ChatManagerImplementation::_getStub() {
	return _this;
}

ChatManagerImplementation::operator const ChatManager*() {
	return _this;
}

void ChatManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ChatManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ChatManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ChatManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ChatManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ChatManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ChatManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ChatManagerImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("ChatManager");

	addSerializableVariable("server", &server);
	addSerializableVariable("playerManager", &playerManager);
	addSerializableVariable("gameRooms", &gameRooms);
	addSerializableVariable("groupRoom", &groupRoom);
	addSerializableVariable("guildRoom", &guildRoom);
	addSerializableVariable("roomID", &roomID);
	addSerializableVariable("mute", &mute);
}

void ChatManagerImplementation::addRoom(ChatRoom* channel) {
	Locker _locker(_this);
	// server/chat/ChatManager.idl(97):  		roomMap.put(channel.getRoomID(), channel);
	roomMap->put(channel->getRoomID(), channel);
}

void ChatManagerImplementation::removeRoom(ChatRoom* channel) {
	Locker _locker(_this);
	// server/chat/ChatManager.idl(101):  		roomMap.remove(channel.getRoomID());
	roomMap->remove(channel->getRoomID());
}

void ChatManagerImplementation::setPlayerManager(PlayerManager* manager) {
	// server/chat/ChatManager.idl(171):  		playerManager = manager;
	playerManager = manager;
}

ChatRoom* ChatManagerImplementation::getChatRoom(unsigned int id) {
	Locker _locker(_this);
	// server/chat/ChatManager.idl(175):  		return roomMap.get(id);
	return roomMap->get(id);
}

ChatRoom* ChatManagerImplementation::getGameRoom(const String& game) {
	Locker _locker(_this);
	// server/chat/ChatManager.idl(179):  		return gameRooms.get(game);
	return (&gameRooms)->get(game);
}

unsigned int ChatManagerImplementation::getNextRoomID() {
	Locker _locker(_this);
	// server/chat/ChatManager.idl(183):  		return ++roomID;
	return  ++roomID;
}

int ChatManagerImplementation::getPlayerCount() {
	// server/chat/ChatManager.idl(187):  		return playerMap.size();
	return playerMap->size();
}

/*
 *	ChatManagerAdapter
 */

ChatManagerAdapter::ChatManagerAdapter(ChatManagerImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* ChatManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		finalize();
		break;
	case 7:
		initiateRooms();
		break;
	case 8:
		destroyRooms();
		break;
	case 9:
		resp->insertLong(createRoom(inv->getAsciiParameter(_param0_createRoom__String_ChatRoom_), (ChatRoom*) inv->getObjectParameter())->_getObjectID());
		break;
	case 10:
		addRoom((ChatRoom*) inv->getObjectParameter());
		break;
	case 11:
		removeRoom((ChatRoom*) inv->getObjectParameter());
		break;
	case 12:
		populateRoomListMessage((ChatRoom*) inv->getObjectParameter(), (ChatRoomList*) inv->getObjectParameter());
		break;
	case 13:
		sendRoomList((PlayerCreature*) inv->getObjectParameter());
		break;
	case 14:
		addPlayer((PlayerCreature*) inv->getObjectParameter());
		break;
	case 15:
		resp->insertLong(getPlayer(inv->getAsciiParameter(_param0_getPlayer__String_))->_getObjectID());
		break;
	case 16:
		resp->insertLong(removePlayer(inv->getAsciiParameter(_param0_removePlayer__String_))->_getObjectID());
		break;
	case 17:
		broadcastMessage((CreatureObject*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_broadcastMessage__CreatureObject_UnicodeString_long_int_int_), inv->getUnsignedLongParameter(), inv->getUnsignedIntParameter(), inv->getUnsignedIntParameter());
		break;
	case 18:
		handleSpatialChatInternalMessage((PlayerCreature*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_handleSpatialChatInternalMessage__PlayerCreature_UnicodeString_));
		break;
	case 19:
		handleGroupChat((PlayerCreature*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_handleGroupChat__PlayerCreature_UnicodeString_));
		break;
	case 20:
		resp->insertLong(createRoomByFullPath(inv->getAsciiParameter(_param0_createRoomByFullPath__String_))->_getObjectID());
		break;
	case 21:
		resp->insertLong(getChatRoomByFullPath(inv->getAsciiParameter(_param0_getChatRoomByFullPath__String_))->_getObjectID());
		break;
	case 22:
		resp->insertLong(getChatRoomByGamePath((ChatRoom*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_getChatRoomByGamePath__ChatRoom_String_))->_getObjectID());
		break;
	case 23:
		handleChatRoomMessage((PlayerCreature*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_handleChatRoomMessage__PlayerCreature_UnicodeString_int_int_), inv->getUnsignedIntParameter(), inv->getUnsignedIntParameter());
		break;
	case 24:
		handleSocialInternalMessage((CreatureObject*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_handleSocialInternalMessage__CreatureObject_UnicodeString_));
		break;
	case 25:
		destroyRoom((ChatRoom*) inv->getObjectParameter());
		break;
	case 26:
		resp->insertLong(createGroupRoom(inv->getUnsignedLongParameter(), (PlayerCreature*) inv->getObjectParameter())->_getObjectID());
		break;
	case 27:
		loadMail((PlayerCreature*) inv->getObjectParameter());
		break;
	case 28:
		sendMail(inv->getAsciiParameter(_param0_sendMail__String_UnicodeString_UnicodeString_String_), inv->getUnicodeParameter(_param1_sendMail__String_UnicodeString_UnicodeString_String_), inv->getUnicodeParameter(_param2_sendMail__String_UnicodeString_UnicodeString_String_), inv->getAsciiParameter(_param3_sendMail__String_UnicodeString_UnicodeString_String_));
		break;
	case 29:
		handleRequestPersistentMsg((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedIntParameter());
		break;
	case 30:
		deletePersistentMessage((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedIntParameter());
		break;
	case 31:
		setPlayerManager((PlayerManager*) inv->getObjectParameter());
		break;
	case 32:
		resp->insertLong(getChatRoom(inv->getUnsignedIntParameter())->_getObjectID());
		break;
	case 33:
		resp->insertLong(getGameRoom(inv->getAsciiParameter(_param0_getGameRoom__String_))->_getObjectID());
		break;
	case 34:
		resp->insertInt(getNextRoomID());
		break;
	case 35:
		resp->insertSignedInt(getPlayerCount());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ChatManagerAdapter::finalize() {
	((ChatManagerImplementation*) impl)->finalize();
}

void ChatManagerAdapter::initiateRooms() {
	((ChatManagerImplementation*) impl)->initiateRooms();
}

void ChatManagerAdapter::destroyRooms() {
	((ChatManagerImplementation*) impl)->destroyRooms();
}

ChatRoom* ChatManagerAdapter::createRoom(const String& roomName, ChatRoom* parent) {
	return ((ChatManagerImplementation*) impl)->createRoom(roomName, parent);
}

void ChatManagerAdapter::addRoom(ChatRoom* channel) {
	((ChatManagerImplementation*) impl)->addRoom(channel);
}

void ChatManagerAdapter::removeRoom(ChatRoom* channel) {
	((ChatManagerImplementation*) impl)->removeRoom(channel);
}

void ChatManagerAdapter::populateRoomListMessage(ChatRoom* channel, ChatRoomList* msg) {
	((ChatManagerImplementation*) impl)->populateRoomListMessage(channel, msg);
}

void ChatManagerAdapter::sendRoomList(PlayerCreature* player) {
	((ChatManagerImplementation*) impl)->sendRoomList(player);
}

void ChatManagerAdapter::addPlayer(PlayerCreature* player) {
	((ChatManagerImplementation*) impl)->addPlayer(player);
}

PlayerCreature* ChatManagerAdapter::getPlayer(const String& name) {
	return ((ChatManagerImplementation*) impl)->getPlayer(name);
}

PlayerCreature* ChatManagerAdapter::removePlayer(const String& name) {
	return ((ChatManagerImplementation*) impl)->removePlayer(name);
}

void ChatManagerAdapter::broadcastMessage(CreatureObject* player, const UnicodeString& message, unsigned long long target, unsigned int moodid, unsigned int mood2) {
	((ChatManagerImplementation*) impl)->broadcastMessage(player, message, target, moodid, mood2);
}

void ChatManagerAdapter::handleSpatialChatInternalMessage(PlayerCreature* player, const UnicodeString& args) {
	((ChatManagerImplementation*) impl)->handleSpatialChatInternalMessage(player, args);
}

void ChatManagerAdapter::handleGroupChat(PlayerCreature* player, const UnicodeString& message) {
	((ChatManagerImplementation*) impl)->handleGroupChat(player, message);
}

ChatRoom* ChatManagerAdapter::createRoomByFullPath(const String& path) {
	return ((ChatManagerImplementation*) impl)->createRoomByFullPath(path);
}

ChatRoom* ChatManagerAdapter::getChatRoomByFullPath(const String& path) {
	return ((ChatManagerImplementation*) impl)->getChatRoomByFullPath(path);
}

ChatRoom* ChatManagerAdapter::getChatRoomByGamePath(ChatRoom* game, const String& path) {
	return ((ChatManagerImplementation*) impl)->getChatRoomByGamePath(game, path);
}

void ChatManagerAdapter::handleChatRoomMessage(PlayerCreature* sender, const UnicodeString& message, unsigned int roomID, unsigned int counter) {
	((ChatManagerImplementation*) impl)->handleChatRoomMessage(sender, message, roomID, counter);
}

void ChatManagerAdapter::handleSocialInternalMessage(CreatureObject* sender, const UnicodeString& arguments) {
	((ChatManagerImplementation*) impl)->handleSocialInternalMessage(sender, arguments);
}

void ChatManagerAdapter::destroyRoom(ChatRoom* room) {
	((ChatManagerImplementation*) impl)->destroyRoom(room);
}

ChatRoom* ChatManagerAdapter::createGroupRoom(unsigned long long groupID, PlayerCreature* creator) {
	return ((ChatManagerImplementation*) impl)->createGroupRoom(groupID, creator);
}

void ChatManagerAdapter::loadMail(PlayerCreature* player) {
	((ChatManagerImplementation*) impl)->loadMail(player);
}

void ChatManagerAdapter::sendMail(const String& sendername, UnicodeString& header, UnicodeString& body, const String& name) {
	((ChatManagerImplementation*) impl)->sendMail(sendername, header, body, name);
}

void ChatManagerAdapter::handleRequestPersistentMsg(PlayerCreature* player, unsigned int mailID) {
	((ChatManagerImplementation*) impl)->handleRequestPersistentMsg(player, mailID);
}

void ChatManagerAdapter::deletePersistentMessage(PlayerCreature* player, unsigned int mailID) {
	((ChatManagerImplementation*) impl)->deletePersistentMessage(player, mailID);
}

void ChatManagerAdapter::setPlayerManager(PlayerManager* manager) {
	((ChatManagerImplementation*) impl)->setPlayerManager(manager);
}

ChatRoom* ChatManagerAdapter::getChatRoom(unsigned int id) {
	return ((ChatManagerImplementation*) impl)->getChatRoom(id);
}

ChatRoom* ChatManagerAdapter::getGameRoom(const String& game) {
	return ((ChatManagerImplementation*) impl)->getGameRoom(game);
}

unsigned int ChatManagerAdapter::getNextRoomID() {
	return ((ChatManagerImplementation*) impl)->getNextRoomID();
}

int ChatManagerAdapter::getPlayerCount() {
	return ((ChatManagerImplementation*) impl)->getPlayerCount();
}

/*
 *	ChatManagerHelper
 */

ChatManagerHelper* ChatManagerHelper::staticInitializer = ChatManagerHelper::instance();

ChatManagerHelper::ChatManagerHelper() {
	className = "ChatManager";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ChatManagerHelper::finalizeHelper() {
	ChatManagerHelper::finalize();
}

DistributedObject* ChatManagerHelper::instantiateObject() {
	return new ChatManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* ChatManagerHelper::instantiateServant() {
	return new ChatManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ChatManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ChatManagerAdapter((ChatManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

