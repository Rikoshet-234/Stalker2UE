#pragma once
class XRayKinematics;
class XRaySkeletonVisual;

class XRaySkeletonX
{
protected:
	enum 
	{ 
		RM_SINGLE,
		RM_SKINNING_1B,
		RM_SKINNING_2B,
		RM_SKINNING_3B,
		RM_SKINNING_4B 
	};

	XRayKinematics* ParentKinematics;		// setted up by parent
	ref_smem<vertBoned1W>	Vertices1W;		// shared
	ref_smem<vertBoned2W>	Vertices2W;		// shared
	ref_smem<vertBoned3W>	Vertices3W;		// shared
	ref_smem<vertBoned4W>	Vertices4W;		// shared

	u16						RenderMode;
	u16						ChildIDX;

	// render-mode specifics
	union {
		struct {			// soft-skinning only
			u32				cache_DiscardID;
			size_t				cache_vCount;
			size_t				cache_vOffset;
		};
		u32					RMS_boneid;			// single-bone-rendering
	};

	void					_Copy(XRaySkeletonX* V);
	void					_Load(const char* N, IReader* data, size_t& dwVertCount);

	virtual void			_Load_hw(XRaySkeletonVisual& V, void* data) = 0;
	virtual void			_CollectBoneFaces(XRaySkeletonVisual* V, size_t iBase, size_t iCount) = 0;


	BOOL					_PickBoneSoft1W(IKinematics::pick_result& r, float range, const Fvector& S, const Fvector& D, u16* indices, CBoneData::FacesVec& faces);
	BOOL					_PickBoneSoft2W(IKinematics::pick_result& r, float range, const Fvector& S, const Fvector& D, u16* indices, CBoneData::FacesVec& faces);
	BOOL					_PickBoneSoft3W(IKinematics::pick_result& r, float range, const Fvector& S, const Fvector& D, u16* indices, CBoneData::FacesVec& faces);
	BOOL					_PickBoneSoft4W(IKinematics::pick_result& r, float range, const Fvector& S, const Fvector& D, u16* indices, CBoneData::FacesVec& faces);

	virtual BOOL			_PickBone(IKinematics::pick_result& r, float range, const Fvector& S, const Fvector& D, XRaySkeletonVisual* V, u16 bone_id, size_t iBase, size_t iCount) = 0;
public:
	XRaySkeletonX() { ParentKinematics = 0; ChildIDX = u16(-1); }

	virtual void			SetParent(XRayKinematics* K) { ParentKinematics = K; }
	virtual void			AfterLoad(XRayKinematics* parent, u16 child_idx) = 0;
	virtual void			EnumBoneVertices(SEnumVerticesCallback& C, u16 bone_id) = 0;
	virtual BOOL			PickBone(IKinematics::pick_result& r, float dist, const Fvector& start, const Fvector& dir, u16 bone_id) = 0;

	void			_DuplicateIndices(const char* N, IReader* data);
	//	Index buffer replica since we can't read from index buffer in DX10
	ref_smem<u16>			m_Indices;
};