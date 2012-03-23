/*

SCV - Simple Components for Visual
Developed at Federal University of Santa Maria - UFSM
LaCA - Computer Applied Laboratory - Laborat�rio de Computa��o Aplicada
www.inf.ufsm.br/~pozzer/scv/
2007-2012 

*/

#include <SCV/SCV.h>

#include "Application.h"
#include "Properties.h"
#include <SCV/GapSpring.h>


#include "GroupPanelWrapper.h"
#include "SequentialGroupPanel.h"
#include "ParallelGroupPanel.h"

int main(int argc, char* argv[]) {
   scv::Kernel::setInstance(new Application());
   Application *kernel = static_cast<Application*>(scv::Kernel::getInstance());
      
   kernel->init();

   kernel->run();
   return 0;
}
