#pragma once


#include "app-cube/cube/graphics3d/engine.h"


#include <memory>
#include <vector>
//#include "Core/Window.h"
#include "input.h"
#include "renderer.h"
#include "mesh.h"
#include "shader.h"
#include "camera.h" // Include the Camera header
//#include "application.h"
//#include "apex/platform/app_consumer.h"
#include "aura/graphics/gpu/render.h"


namespace graphics3d_opengl
{


	class engine :
		virtual public ::graphics3d::engine
	{
	public:


		::pointer < ::cube::impact > m_pimpact;
		::pointer < glc::renderer > m_prenderer;
		::pointer < glc::Camera > m_pcamera;
		::pointer < glc::Application > m_pglcapplication;  // Game object that manages the scenes
		::pointer < glc::input > m_pinput;

		//double m_Δx;
		//double m_Δy;

		double m_dMouseLastX = 0.0;
		double m_dMouseLastY = 0.0;
		double m_Δx = 0.;
		double m_Δy = 0.;


		bool m_Running;

		bool m_bWireframeMode = false;


		::memory m_memoryBuffer;



		::pointer<render_data> m_prenderdataCurrentScene;

		bool m_bInitRenderData;


		//::pointer<::gpu::context>             m_pgpucontext;

		engine();
		~engine();



		//Application();
		//~Application();

		void Init();       // Initialize the game and load the first scene
		void Update(float deltaTime, Camera* pcamera);  // Update game logic
		void Render(Renderer* prenderer, Camera* pcamera);

		//void run_application() override;
		void resize(int cx, int cy) override;


		//void Init();

		void on_initialize_particle() override;

		bool render_step() override;

		//private:
		void ProcessInput(float deltaTime);
		//static void MouseCallback(::cube::impact* pglContainer, double xpos, double ypos);
		virtual void initialize_engine(::cube::impact* pimpact);

		virtual void handleMouseMove(double dCursorX, double dCursorY);

		
		virtual void resize(int cx, int cy);

	};



} // namespace graphics3d_opengl



