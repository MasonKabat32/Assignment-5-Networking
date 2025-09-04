#include "SpawnWO.h"
#ifdef AFTR_CONFIG_USE_BOOST
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
namespace Aftr
{
	NetMsgMacroDefinition(SpawnWO);

	SpawnWO::SpawnWO() {
		this->xPos = 0;
		this->yPos = 0;
		this->zPos = 10;
		this->height = 5;
	}

	SpawnWO::~SpawnWO() {
	}

	bool SpawnWO::toStream(NetMessengerStreamBuffer& os) {

		os << this->xPos;
		os << this->yPos;
		os << this->zPos;
		return true;
	}

	bool SpawnWO::fromStream(NetMessengerStreamBuffer& is) {
		is >> this->xPos;
		is >> this->yPos;
		is >> this->zPos;
		return true;
	}

	std::string SpawnWO::toString() const {
		return "";
	}

	void SpawnWO::onMessageArrived() {
		auto wrldList = ManagerGLView::getGLView()->getWorldContainer();
		this->height += 5;
		Vector coords(0,30,this->height);
		WO* obj = WO::New(ManagerEnvironmentConfiguration::getSMM() + "models/cube4x4x4redShinyPlastic_pp.wrl");
		obj->setPosition(coords);
		obj->setLabel("cube num " + std::to_string(this->height));
		wrldList->push_back(obj);
	}
}
#endif