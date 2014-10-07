#include "PluginWrapper.h"

using namespace cocos2d;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

namespace PhoneDirect3DXamlAppComponent {

// anonimous namespace for global objects in cpp file
namespace
{
	ICommandHandler^ g_commandHandler = nullptr;
}

void PluginWrapper::SetCallback(ICommandHandler^ _commandHandler)
{
	CCLog("SetCallback");
	g_commandHandler = _commandHandler;
}

void PluginWrapper::callCSharp()
{
	CCLog("in CPP method");
	if (g_commandHandler != nullptr)
	{
		CCLog("Value not null");
		//Send your parameters from here 
		g_commandHandler->Exec( "Hello", "Suveer Jacob" );
	}
}

} // namespace cocos2d { namespace zplugin

#endif // CC_PLATFORM_WP8

