#include "stdafx.h"
#include "MenuDesign.h"
#include "AbstractWindow.h"

MenuDesign::MenuDesign(scv::MenuBar * menubar) : scv::ContextMenu("InterfaceDesign") {
   m_menu = menubar;
   contMenu = 0;
   scv::ContextMenu * menu = new scv::ContextMenu("Add Menu");
   addMenu(menu);
   addMenu(new scv::ContextMenu("Remove Component"));
   m_menu->registerContextMenu(this);
}

void MenuDesign::onMouseClick(const scv::MouseEvent &evt, const std::deque<std::string> &address) {
   if (address.size() == 2) {
      if (address[1] == "Add Menu") {
         ContextMenu * cmenu = new scv::ContextMenu("menu " + scv::toString(contMenu));
         m_menu->addMenu(cmenu);
         contMenu++;
         /*AbstractWindow *win = new AbstractWindow(m_menu);
         win->setRelativePosition(scv::Point((scv::Kernel::getInstance()->getWidth() - win->getWidth())/2,(scv::Kernel::getInstance()->getHeight() - win->getHeight())/2));
         scv::Kernel::getInstance()->addWindow(win);*/
      }
	  else if (address[1] == "Remove Component") {
		  scv::Kernel::getInstance()->deleteObject(m_menu->shared_from_this());
	  }
   }
}



void MenuRename::onMouseClick(const scv::MouseEvent &evt, const std::deque<std::string> &address) {
   if (address.size() == 2) {
      if (address[1] == "Rename") {
         AbstractWindow *win = new AbstractWindow(m_component);
         win->setRelativePosition(scv::Point((scv::Kernel::getInstance()->getWidth() - win->getWidth())/2,(scv::Kernel::getInstance()->getHeight() - win->getHeight())/2));
         scv::Kernel::getInstance()->addWindow(win);
      }
      if (address[1] == "Remove Component") {
         scv::Kernel::getInstance()->deleteObject(m_component->shared_from_this());
      }
   }
}

void RemoveComponent::onMouseClick(const scv::MouseEvent &evt, const std::deque<std::string> &address) {
   if (address.size() == 2) {
      if (address[1] == "Remove Component") {
         scv::Kernel::getInstance()->deleteObject(m_component->shared_from_this());
      }
   }
}
