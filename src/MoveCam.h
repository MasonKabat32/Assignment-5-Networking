#pragma once
#include "NetMsg.h"
#ifdef AFTR_CONFIG_USE_BOOST
namespace Aftr
{
	class MoveCam : public NetMsg
	{
	public:
		NetMsgMacroDeclaration(MoveCam);
		MoveCam();
		virtual ~MoveCam();
		virtual bool toStream(NetMessengerStreamBuffer& os);
		virtual bool fromStream(NetMessengerStreamBuffer& is);
		virtual void onMessageArrived();
		virtual std::string toString() const;
		float xPos;
		float yPos;
		float zPos;
		unsigned int size;
	protected:
	};
}


#endif
