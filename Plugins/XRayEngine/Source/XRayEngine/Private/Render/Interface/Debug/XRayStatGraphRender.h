#pragma once
#include "XrRender/Public/StatGraphRender.h"

class XRayStatGraphRender:public IStatGraphRender
{
public:
	XRayStatGraphRender();
	virtual void Copy(IStatGraphRender &_in) ;

	virtual void OnDeviceCreate() ;
	virtual void OnDeviceDestroy() ;

	virtual void OnRender(CStatGraph &owner) ;
};
