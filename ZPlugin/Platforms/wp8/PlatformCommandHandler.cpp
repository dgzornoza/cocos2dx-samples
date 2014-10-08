#include "PlatformCommandHandler.h"

using namespace cocos2d;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

namespace PhoneDirect3DXamlAppComponent {

// anonimous namespace for global objects in cpp file
namespace
{
	// global object for the native command handler
	ICommandHandler^ g_nativeCommandHandler = nullptr;
}

/** function for set native command handler for interop with native code */
void PlatformCommandHandler::setCommandHandler(ICommandHandler^ _nativeCommandHandler)
{
	CCLog("SetCallback");
	g_nativeCommandHandler = _nativeCommandHandler;
}

/** function for execute native code using the input parameters */
void PlatformCommandHandler::execNativeCommand(Platform::String^ _className, Platform::String^ _funcName, Platform::String^ _params)
{
	CCLog("in CPP method");
	if (g_nativeCommandHandler != nullptr)
	{
		CCLog("Value not null");
		//Send your parameters from here 
		g_nativeCommandHandler->exec( _className, _funcName, _params);
	}
}

} // namespace PhoneDirect3DXamlAppComponent

#endif // CC_PLATFORM_WP8

