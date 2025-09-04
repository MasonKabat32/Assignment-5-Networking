#pragma once
#include "NetMsg.h"
#ifdef AFTR_CONFIG_USE_BOOST
namespace Aftr
{
	class SpawnWO : public NetMsg
	{
	public:
		NetMsgMacroDeclaration(SpawnWO);

		SpawnWO(); // constructor, not really sure if anything signifigant will have to be done here
		virtual ~SpawnWO(); //DO NOT FORGET ABOUT THIS IF YOU ALLOCATE ANYTHING
		virtual bool toStream(NetMessengerStreamBuffer& os); //This used to be const but we want to continuously update the x position
		virtual bool fromStream(NetMessengerStreamBuffer& is); //not sure what to do with this yet
		virtual void onMessageArrived(); //handles whatever we need to when a message is received
		virtual std::string toString() const; //Meant for debugging

		float xPos;
		float yPos;
		float zPos;
		float height;
		unsigned int size; //size of the data being sent in the message

	protected:
	};
}
#endif