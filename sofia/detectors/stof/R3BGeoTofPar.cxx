//*-- AUTHOR : Jose Luis Rodriguez
//*-- Created : 21/08/2012

#include "R3BGeoTofPar.h"

#include "FairParamList.h"

#include "TObjArray.h"

#include <iostream>
#include <iomanip>

ClassImp(R3BGeoTofPar)

R3BGeoTofPar::R3BGeoTofPar(const char* name,const char* title,const char* context)
           : FairParGenericSet(name,title,context) {

               fGeoSensNodes = new TObjArray();
               fGeoPassNodes = new TObjArray();
}

R3BGeoTofPar::~R3BGeoTofPar(void) {
}

void R3BGeoTofPar::clear(void) {
    if(fGeoSensNodes) delete fGeoSensNodes;
    if(fGeoPassNodes) delete fGeoPassNodes;
}

void R3BGeoTofPar::putParams(FairParamList* l) {
  if (!l) return;
   l->addObject("FairGeoNodes Sensitive List", fGeoSensNodes);
   l->addObject("FairGeoNodes Passive List", fGeoPassNodes);
}

Bool_t R3BGeoTofPar::getParams(FairParamList* l) {
    if (!l) return kFALSE;
    if (!l->fillObject("FairGeoNodes Sensitive List", fGeoSensNodes)) return kFALSE;
    if (!l->fillObject("FairGeoNodes Passive List", fGeoPassNodes)) return kFALSE;

  return kTRUE;
}
