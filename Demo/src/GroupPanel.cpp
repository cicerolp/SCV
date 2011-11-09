#include "stdafx.h"
#include "GroupPanel.h"

#include "ParallelGroup.h"
#include "SequentialGroup.h"

GroupPanel::GroupPanel(GroupType type) : scv::Panel(scv::Point(0,0), scv::Point(200,200)) {
   _layout = new scv::GroupLayout(this);
   setLayout(_layout);   
}

GroupPanel::~GroupPanel(void) {
   if (_layout != NULL) {
      delete _layout;
   }
}

void GroupPanel::addChild(scv::Component *object) {
   Panel::addChild(object);
   _verticalGroup->addComponent(object);
   _horizontalGroup->addComponent(object);
}

void GroupPanel::removeChild(scv::Component *object) {
   if (dynamic_cast<GroupPanel*>(object)) {
      std::cout << "HERE" << std::endl;
   }
}

void GroupPanel::display(void) {
   static scv::Kernel *kernel = scv::Kernel::getInstance();
   static scv::Scissor *scissor = scv::Scissor::getInstance();

   if (_cTexture == NULL || _isVisible == false) return;

   scv::Point currPosition = getAbsolutePosition();

   scissor->pushScissor(getScissor());

   _cTexture->enable();
   applyColor();
   
   // middle
   _cTexture->display(currPosition.x + 1, currPosition.y + 1, 0, getWidth() - 2, getHeight() - 2);

   // corners
   _cTexture->display(currPosition.x, currPosition.y + 1, 0, 1, getHeight() - 2);
   _cTexture->display(currPosition.x + getWidth() - 1, currPosition.y + 1, 0, 1, getHeight() - 2);
   _cTexture->display(currPosition.x + 1, currPosition.y, 0, getWidth() - 2, 1);
   _cTexture->display(currPosition.x + 1, currPosition.y + getHeight() - 1, 0, getWidth() - 2, 1);

   _cTexture->disable();

   if (_layout != NULL) {
      _layout->layoutContainer();
   }

   for (List::const_iterator iter = getChildren().begin(); iter != getChildren().end(); ++iter) {
      if (kernel->willAppearOnScreen(*iter))
         (*iter)->display();
   }

   scissor->popScissor();
}

scv::Point GroupPanel::getMinimumSize(void) const {
   return Component::getMinimumSize();
}

scv::Point GroupPanel::getPreferredSize(void) const {
   return Component::getPreferredSize();
}

scv::Point GroupPanel::getMaximumSize(void) const {
   return Component::getMaximumSize();
}

GroupContextMenu::GroupContextMenu(GroupPanel *panel) : scv::ContextMenu("Group") {
   _panel = panel;
}

GroupContextMenu::~GroupContextMenu(void) {

}

void GroupContextMenu::onMenuAccessed(const std::deque<std::string> &address) {
   /*
   GroupPanel *group = NULL;
   if (address[1] == "Parallel Group") {
      group = new GroupPanel(new scv::ParallelGroup(scv::Spring::LEADING, true));
   } else if (address[1] == "Sequential Group") {
      group = new GroupPanel(new scv::SequentialGroup());
   }

   _panel->addChild(group);
   _panel->getGroup()->addGroup(group->getGroup());
   */
}