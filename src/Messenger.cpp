#include "Messenger.h"
#ifdef AFTR_CONFIG_USE_BOOST
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
namespace Aftr
{

	NetMsgMacroDefinition(Messenger); //macro definition to use netmsg

	Messenger::Messenger()
	{
		this->xPos = 0;
		this->yPos = 0;
		this->zPos = 10;
		this->xRot = 1.57; //always want a contsant rotation
	}

	Messenger::~Messenger() //Most likely will not need anything here
	{

	}

	bool Messenger::toStream(NetMessengerStreamBuffer& os)
	{
		this->xPos += 5.0f; //slide the plane along the x axis just a bit at a time
		std::cout << "coords after increment going into buffer: " << this->xPos << std::endl;
		os << this->xPos;
		os << this->yPos;
		os << this->zPos;
		os << this->xRot;
		return true;
	}

	bool Messenger::fromStream(NetMessengerStreamBuffer& is)
	{
		std::cout << "Reading in the coords before reading in from buffer: " << this->xPos << "\n";
		is >> this->xPos;
		is >> this->yPos;
		is >> this->zPos;
		is >> this->xRot;
		return true;
	}

	void Messenger::onMessageArrived()
	{
		//where the update magic will happen
		auto wrldList = ManagerGLView::getGLView()->getWorldContainer();
		Vector coords;
		for (size_t i = 0; i < wrldList->size(); i++)
		{
			if (wrldList->at(i)->getLabel() == "Gulfstream GIII") //find the plane and update the position
			{
				coords = wrldList->at(i)->getPosition();
				coords.x += 5;
				wrldList->at(i)->setPosition(coords);
				wrldList->at(i)->rotateAboutRelX(1.57);
				break;
			}
		}
	}

	std::string Messenger::toString() const //might need to come back and actually implement this
	{
		std::stringstream ss;
		ss << NetMsg::toString();
		ss << "   Payload: " << this->xPos << ", " << this->yPos << ", " << this->zPos << "...\n";
		return ss.str();
	}



}

#endif