#ifndef __ZPLUGIN_PLUGIN_WRAPPER_H__
#define __ZPLUGIN_PLUGIN_WRAPPER_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#include "ICommandHandler.h"
#endif




#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

namespace PhoneDirect3DXamlAppComponent {

[Windows::Foundation::Metadata::WebHostHidden]
public ref class PluginWrapper sealed
{ 
public: 

	static void SetCallback(ICommandHandler^ _callback);
	static void callCSharp();
};

} // namespace cocos2d { namespace zplugin

#endif // CC_PLATFORM_WP8

#endif /* __ZPLUGIN_PLUGIN_WRAPPER_H__ */