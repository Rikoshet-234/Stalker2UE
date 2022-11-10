#pragma once
#include "XrRender/Public/LensFlareRender.h"
class XRayFlareRender:public IFlareRender
{
public:
	XRayFlareRender();
	virtual ~XRayFlareRender();
	virtual void Copy(IFlareRender &_in) ;

	virtual void CreateShader(LPCSTR sh_name, LPCSTR tex_name);
	virtual void DestroyShader() ;
};