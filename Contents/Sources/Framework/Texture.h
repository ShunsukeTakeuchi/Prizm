#pragma once

#include<vector>
#include<string>
#include<memory>

#include<wrl\client.h>
#include<d3d11_4.h>

#include<DirectXTK/SimpleMath.h>

namespace Prizm
{
	enum TextureUsage : unsigned
	{
		RESOURCE = D3D11_BIND_SHADER_RESOURCE,
		RENDER_TARGET = D3D11_BIND_RENDER_TARGET,
		RENDER_TARGET_RW = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET,
		DEPTH_TARGET = D3D11_BIND_DEPTH_STENCIL,
	};

	enum ImageFormat
	{
		// RGBA
		RGBA32F = DXGI_FORMAT_R32G32B32A32_FLOAT,
		RGBA16F = DXGI_FORMAT_R16G16B16A16_FLOAT,
		RGBA8UN = DXGI_FORMAT_R8G8B8A8_UNORM,

		// RGB
		RGB32F = DXGI_FORMAT_R32G32B32_FLOAT,

		// R
		R32F = DXGI_FORMAT_R32_FLOAT,
		R32U = DXGI_FORMAT_R32_UINT,

		R8U = DXGI_FORMAT_R8_UINT,
		R8UN = DXGI_FORMAT_R8_UNORM,

		// Typeless
		R32 = DXGI_FORMAT_R32_TYPELESS,
		R24G8 = DXGI_FORMAT_R24G8_TYPELESS,

		// 
		R24_UNORM_X8_TYPELESS = DXGI_FORMAT_R24_UNORM_X8_TYPELESS,

		// Depth
		D32F = DXGI_FORMAT_D32_FLOAT,
		D24UNORM_S8U = DXGI_FORMAT_D24_UNORM_S8_UINT,

		IMAGE_FORMAT_UNKNOWN
	};

	class Texture
	{
	private:
		class Impl;
		std::unique_ptr<Impl> impl_;

	public:
		Texture(void);
		~Texture(void);

		void LoadTexture(Microsoft::WRL::ComPtr<ID3D11Device>&, const std::string&);
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& GetSRV(void);

		const DirectX::SimpleMath::Vector2 GetTextureSize(void);
	};
}