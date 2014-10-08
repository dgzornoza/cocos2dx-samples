#ifndef __ZPLUGIN_PLATFORM_COMMAND_HANDLER_H__
#define __ZPLUGIN_PLATFORM_COMMAND_HANDLER_H__


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

namespace PhoneDirect3DXamlAppComponent {

/** 
* @brief zplugin interface command handler for cocos2dx interop.
* this interface declare methods for handle comunication between platform native code and cocos2dx.
*/
[Windows::Foundation::Metadata::WebHostHidden]
public interface class ICommandHandler
{
public:

	//Exec(..) is the virtual method that will be implemented in your .cs file
	virtual void exec(Platform::String^ _className, Platform::String^ _funcName, Platform::String^ _params);
};

/** 
* @brief class for interop with native code
* this class handle comunication cocos2dx -> platform native.
*/
[Windows::Foundation::Metadata::WebHostHidden]
public ref class PlatformCommandHandler sealed
{ 
public: 

	/** function for set native command handler for interop with native code
	* @param _nativeCommandHandler Object with native command handler
	*/
	static void setCommandHandler(ICommandHandler^ _nativeCommandHandler);

	/** function for execute native code using the input parameters
	* @param _className Class name in native code with the function to execute
	* @param _funcName Function name in the class to execute
	* @param _params parameters to invoke the function, for complex objects can use json string.
	*/
	static void execNativeCommand(Platform::String^ _className, Platform::String^ _funcName, Platform::String^ _params);
};

} // namespace PhoneDirect3DXamlAppComponent

#endif // CC_PLATFORM_WP8

#endif /* __ZPLUGIN_PLATFORM_COMMAND_HANDLER_H__ */