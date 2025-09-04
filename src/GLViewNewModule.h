#pragma once

#include "GLView.h"
#include "AftrImGui_MenuBar.h"
#include "AftrImGui_WO_Editor.h"
#include "AftrImGui_NewModule.h"
#include "Messenger.h"
#include "MoveCam.h"
#include "SpawnWO.h"
#include "NetMessengerClient.h"

namespace Aftr
{
   class Camera;
   class WOImGui;

/**
   \class GLViewNewModule
   \author Scott Nykl 
   \brief A child of an abstract GLView. This class is the top-most manager of the module.

   Read \see GLView for important constructor and init information.

   \see GLView

    \{
*/

class GLViewNewModule : public GLView
{
public:
   static GLViewNewModule* New( const std::vector< std::string >& outArgs );
   virtual ~GLViewNewModule();
   virtual void updateWorld() override; ///< Called once per frame
   virtual void loadMap() override; ///< Called once at startup to build this module's scene
   virtual void createNewModuleWayPoints();
   virtual void onResizeWindow( GLsizei width, GLsizei height ) override;
   virtual void onMouseDown( const SDL_MouseButtonEvent& e ) override;
   virtual void onMouseUp( const SDL_MouseButtonEvent& e ) override;
   virtual void onMouseMove( const SDL_MouseMotionEvent& e ) override;
   virtual void onKeyDown( const SDL_KeyboardEvent& key ) override;
   virtual void onKeyUp( const SDL_KeyboardEvent& key ) override;

protected:
   GLViewNewModule( const std::vector< std::string >& args );
   virtual void onCreate();

   WOImGui* gui = nullptr; //The GUI which contains all ImGui widgets
   AftrImGui_MenuBar menu;      //The Menu bar at the top of the GUI window
   AftrImGui_WO_Editor wo_editor;//The WO Editor to mutate a selected WO
   AftrImGui_NewModule orbit_gui;
   WO* moon = nullptr;
   WO* gulfstream = nullptr;
   std::shared_ptr<NetMessengerClient> client = nullptr; //client to send messages
   Messenger* msg = nullptr;
   MoveCam* moveCam = nullptr;
   SpawnWO* spawnWO = nullptr;
   NetMessengerStreamBuffer* os = nullptr; //in and out streams for network messages
   NetMessengerStreamBuffer* is = nullptr;
   NetMessengerStreamBuffer* camOs = nullptr;
   NetMessengerStreamBuffer* camIs = nullptr;
   NetMessengerStreamBuffer* spawnOs = nullptr;
   NetMessengerStreamBuffer* spawnIs = nullptr;
   bool spawned = false;
};

/** \} */

} //namespace Aftr
