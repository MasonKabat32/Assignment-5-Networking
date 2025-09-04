#include "MoveCam.h"


#ifdef AFTR_CONFIG_USE_BOOST
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include <cstdlib>
#include <ctime>
namespace Aftr
{
	NetMsgMacroDefinition(MoveCam);

	MoveCam::MoveCam() {
		this->xPos = 0;
		this->yPos = 0;
		this->zPos = 10;
	}

	MoveCam::~MoveCam() {
	}

	bool MoveCam::toStream(NetMessengerStreamBuffer& os) {
		os << this->xPos;
		os << this->yPos;
		os << this->zPos;
		return true;
	}

	bool MoveCam::fromStream(NetMessengerStreamBuffer& is) {
		is >> this->xPos;
		is >> this->yPos;
		is >> this->zPos;
		return true;
	}

	void MoveCam::onMessageArrived() {
		auto cam = ManagerGLView::getGLView()->getCamera();
		Vector coords;
		std::srand(std::time(0));
		coords.x = static_cast<float>(5 + std::rand() % 46);
		coords.y = static_cast<float>(5 + std::rand() % 46);
		coords.z = static_cast<float>(5 + std::rand() % 46);
		cam->setPosition(coords);
	}

	std::string MoveCam::toString() const {
		
		return "";
	}
}
#endif