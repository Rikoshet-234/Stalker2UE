#include "XRayDevice.h"

XRayDevice::XRayDevice()
{
	psDeviceFlags.assign(0);
	// default initialization
	dwMaximized = 0;
	dwWidth = dwHeight = 256;
	fWidth_2 = fHeight_2 = 128;
	mProject.identity();
	mFullTransform.identity();
	mView.identity();

	b_is_Ready = FALSE;
	b_is_Active = FALSE;

	// Engine flow-control
	fTimeDelta = 0;
	fTimeGlobal = 0;
	dwTimeDelta = 0;
	dwTimeGlobal = 0;

	fASPECT = 1.f;
	fFOV = 60.f;
	dwPrecacheFrame = 0;
}

bool XRayDevice::IsEditorMode()
{
	return GIsEditor;
}

bool XRayDevice::Paused() const
{
	return false;
}

void XRayDevice::Reset(bool precache /*= false*/)
{
}

void XRayDevice::Pause(BOOL bOn, BOOL bTimer, BOOL bSound, LPCSTR reason)
{
}

void XRayDevice::PreCache(u32 amount, bool b_draw_loadscreen, bool b_wait_user_input)
{
}

void XRayDevice::Clear()
{
}

bool XRayDevice::Begin()
{	
	return true;
}

void XRayDevice::End()
{
}

CStatsPhysics* _BCL XRayDevice::StatPhysics()
{
	return nullptr;
}

void _BCL XRayDevice::AddSeqFrame(pureFrame* f, bool mt)
{
	seqFrame.Add(f, REG_PRIORITY_LOW);
}

void _BCL XRayDevice::RemoveSeqFrame(pureFrame* f)
{
	seqFrame.Remove(f);
}

