#pragma once
#include "4J_Render.h"

#define MAX_MIP_LEVELS 5

class Renderer
{
public:

	struct Texture
	{
		bool allocated;
		ID3D11Texture2D* texture;
		ID3D11ShaderResourceView* view;
		DWORD dword18;
		DWORD mip_levels;
		DWORD dword20;
		DWORD param;
	};

	struct TexgenCBuffer
	{
		DirectX::XMMATRIX unk0;
		DirectX::XMMATRIX unk1;
	};

	enum eCommandType
	{
		COMMAND_ADD_MATRIX,
		COMMAND_ADD_VERTICES,
		COMMAND_BIND_TEXTURE,
		COMMAND_SET_COLOR,
		COMMAND_SET_DEPTH_FUNC,
		COMMAND_SET_DEPTH_MASK,
		COMMAND_SET_DEPTH_TEST,
		COMMAND_SET_LIGHTING_ENABLE,
		COMMAND_SET_LIGHT_ENABLE,
		COMMAND_SET_LIGHT_DIRECTION,
		COMMAND_SET_LIGHT_COLOUR,
		COMMAND_SET_LIGHT_AMBIENT_COLOUR,
		COMMAND_SET_BLEND_ENABLE,
		COMMAND_SET_BLEND_FUNC,
		COMMAND_SET_BLEND_FACTOR,
		COMMAND_SET_FACE_CULL,
	};

	struct CommandBuffer
	{
		struct Command
		{
			Renderer::eCommandType m_command_type;
			BYTE gap4[12];

			union
			{
				BYTE data[64];

				struct
				{
					float m_matrix[16];
					//DirectX::XMMATRIX m_matrix;
				} add_matrix;

				struct
				{
					unsigned int m_vertex_index_start;
					unsigned int m_vertex_count;
				} add_vertices;

				struct
				{
					unsigned int m_texture_index;
				} bind_texture;

				struct
				{
					float m_color[4];
				} set_color;

				struct
				{
					int m_depth_func;
				} set_depth_func;

				struct
				{
					bool m_enable;
				} set_depth_mask;

				struct
				{
					bool m_enable;
				} set_depth_test;

				struct
				{
					bool m_enable;
				} set_lighting_enable;

				struct
				{
					int m_light_index;
					bool m_enable;
				} set_light_enable;

				struct
				{
					int m_light_index;
					float m_direction[3];
					//DirectX::XMVECTOR m_direction;
				} set_light_direction;

				struct
				{
					int m_light_index;
					float m_color[3];
				} set_light_colour;

				struct
				{
					float m_color[3];
				} set_light_ambient_colour;

				struct
				{
					bool m_enable;
				} set_blend_enable;

				struct
				{
					int m_src;
					int m_dst;
				} set_blend_func;

				struct
				{
					unsigned int m_blend_factor;
				} set_blend_factor;

				struct
				{
					bool m_enable;
				} set_face_cull;
			};
		};


	};

	struct DeferredCBuff
	{
		Renderer::CommandBuffer* m_command_buf;
		int m_vertex_index;
		int m_vertex_type;
		int m_primitive_type;
		DirectX::XMMATRIX m_matrix;
	};

	struct Context
	{
		ID3D11DeviceContext* m_pDeviceContext;
		ID3DUserDefinedAnnotation* pvoid8;
		DWORD dword10;
		BYTE gap14[12];
		DirectX::XMMATRIX arraymatrix20[4][16];
		bool bool1020;
		bool bool1021;
		bool bool1022;
		bool bool1023;
		DWORD arraydword1024[4];
		DWORD stackType;
		DWORD textureIdx;
		BYTE byte103C;
		BYTE byte103D;
		BYTE byte103E;
		float float1040;
		BYTE byte1044;
		BYTE byte1045;
		BYTE gap1046[14];
		DWORD dword1054;
		DWORD dword1058;
		DWORD dword105C;
		BYTE gap1060[4];
		BYTE byte1064;
		BYTE gap1065[2];
		BYTE byte1067;
		DWORD dword1068;
		BYTE gap106C[4];
		char char1070;
		BYTE gap1071[79];
		ID3D11Buffer* pid3d11buffer10C0;
		ID3D11Buffer* pid3d11buffer10C8;
		ID3D11Buffer* pid3d11buffer10D0;
		ID3D11Buffer* pid3d11buffer10D8;
		ID3D11Buffer* pid3d11buffer10E0;
		ID3D11Buffer* pid3d11buffer10E8;
		ID3D11Buffer* pid3d11buffer10F0;
		ID3D11Buffer* pid3d11buffer10F8;
		ID3D11Buffer* pid3d11buffer1100;
		ID3D11Buffer* pid3d11buffer1108;
		ID3D11Buffer* pid3d11buffer1110;
		ID3D11Buffer* pid3d11buffer1118;
		ID3D11Buffer* pid3d11buffer1120;
		ID3D11Buffer* pid3d11buffer1128;
		ID3D11Buffer* pid3d11buffer1130;
		ID3D11Buffer* pid3d11buffer1138;
		uint64_t qword1140;
		DWORD dword1148;
		BYTE gap114C[4];
		ID3D11Buffer* pid3d11buffer1150;
		BYTE gap1158[8];
		DirectX::XMMATRIX arraymatrix1160[2];
		Renderer::CommandBuffer* qword11E0;
		DWORD dword11E8;
		DWORD dword11EC;
		DWORD dword11F0;
		BYTE byte11F4;
		BYTE gap11F5[3];
		std::vector<DeferredCBuff> std__vector11F8;
		DWORD dword1218;
		DWORD dword121C;
		DWORD dword1220;
		DWORD dword1224;
		DWORD dword1228;
		DWORD dword122C;
		DWORD dword1230;
		DWORD dword1234;
		DWORD dword1238;
		BYTE byte123C;
		BYTE gap123D[227];
		DWORD dword1320;
		DWORD dword1324;
		DWORD dword1328;
		DWORD dword132C;
		BYTE byte1330;
		BYTE byte1331;
		DWORD dword1334;
		DWORD dword1338;
		DWORD dword133C;
		DWORD dword1340;
		DWORD dword1344;
		DWORD dword1348;
		DWORD dword134C;
		DWORD dword1350;
		DWORD dword1354;
		DWORD dword1358;
		DWORD dword135C;
		DWORD dword1360;
		DWORD dword1364;
		DWORD dword1368;
		DWORD dword136C;
		DWORD dword1370;
		DWORD dword1374;
		DWORD dword1378;
		DWORD dword137C;
		DWORD dword1380;
		DWORD dword1384;
		DWORD dword1388;
	};

	static DWORD tlsIdx;

	float m_fClearColor[4];
	ID3D11Device* m_pDevice;
	ID3D11DeviceContext* m_pDeviceContext;
	uint64_t qword20;
	ID3D11RenderTargetView* pid3d11rendertargetview28;
	ID3D11RenderTargetView* arrayqword30[4];
	ID3D11ShaderResourceView* pid3d11shaderresourceview50;
	ID3D11Resource* arrayqword58[4];
	ID3D11Texture2D* pid3d11texture2d78;
	BYTE gap80[24];
	ID3D11DepthStencilView* qword98;
	ID3D11VertexShader** qwordA0;
	BYTE gapA8[16];
	uint64_t qwordB8;
	BYTE gapC0[16];
	uint64_t qwordD0;
	ID3D11InputLayout** qwordD8;
	ID3D11Buffer* qwordE0;
	ID3D11Buffer* qwordE8;
	DWORD dwordF0;
	WORD wordF4;
	BYTE gapF6[2];
	DWORD dwordF8;
	BYTE byteFC;
	BYTE gapFD[3];
	_RTL_CRITICAL_SECTION rtl_critical_section100;
	DWORD dword128;
	DWORD dword12C;
	C4JRender::eViewportType m_ViewportType;
	BYTE byte134;
	BYTE gap135[3];
	Renderer::Texture m_textures[512];
	DWORD dword5138;
	DWORD dword513C;
	BYTE byte5140;
	BYTE gap5141[3];
	DWORD dword5144;
	void* pvoid5148;
	void* pvoid5150;
	uint64_t qword5158;
	void* pvoid5160;
	void* pvoid5168;
	void* pvoid5170;
	DWORD dword5178;
	DWORD dword517C;
	BYTE gap5180[328];
	BYTE m_bShouldScreenGrabNextFrame;
};

// Singleton
extern Renderer InternalRenderManager;