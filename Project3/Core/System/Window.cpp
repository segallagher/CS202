#include "Project3/gapspch.hpp"
#include "Project3/Core/System/Window.hpp"

namespace gaps
{
	Window::Window(WindowDescriptor desc) noexcept :
		desc{ std::move(desc) } 
	{
	}

	int32_t Window::Create()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		/*
		pInternal = glfwCreateWindow
		{
			desc.width,
			desc.height,
			desc.title.c_str(),
			nullptr,
			nullptr
		};
		*/
		if (pInternal == nullptr)
		{
			std::cout << "Failed to open GLFW Window!\n";
			Destroy();
			return EXIT_FAILURE;
		}

		glfwMakeContextCurrent(pInternal);

		return EXIT_SUCCESS;
	}

	const WindowDescriptor& Window::GetDescriptor() const noexcept 
	{
		return desc;
	}
}


