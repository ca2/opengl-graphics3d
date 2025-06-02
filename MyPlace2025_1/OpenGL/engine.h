#pragma once

#include <memory>
#include <vector>
#include "Core/Window.h"
#include "Core/Input.h"
#include "Renderer/Renderer.h"
#include "Renderer/Types/Mesh.h"
#include "Shader/Shader.h"
#include "Core/Camera.h" // Include the Camera header
#include "AppCore/Application.h"
#include "apex/platform/app_consumer.h"
#include "cube/gpu/render.h"


namespace opengl
{


	class engine :
		virtual public app_consumer < application, ::gpu::render >
	{
	public:


		::pointer < glc::GlContainer > m_pglcontainer;
		::pointer < glc::Renderer > m_prenderer;
		::pointer < glc::Camera > m_pcamera;
		::pointer < glc::Application > m_pglcapplication;  // Game object that manages the scenes
		::pointer < glc::Input > m_pinput;

		//double m_Δx;
		//double m_Δy;

		double m_dMouseLastX = 0.0;
		double m_dMouseLastY = 0.0;
		double m_Δx = 0.;
		double m_Δy = 0.;


		bool m_Running;

		bool m_bWireframeMode = false;


		::memory m_memoryBuffer;

		//::pointer<::gpu::context>             m_pgpucontext;

		engine();
		~engine();


		

		//void Init();

		void on_initialize_particle() override;

		bool render_step() override;

		//private:
		void ProcessInput(float deltaTime);
		//static void MouseCallback(glc::GlContainer* pglContainer, double xpos, double ypos);
		virtual void initialize_engine(glc::GlContainer* pglcontainer);

		virtual void handleMouseMove(double dCursorX, double dCursorY);

		
		virtual void resize(int cx, int cy);

	};



} // namespace opengl



