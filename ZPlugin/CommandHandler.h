#ifndef __ZPLUGIN_COMMAND_HANDLER_H__
#define __ZPLUGIN_COMMAND_HANDLER_H__


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

namespace PhoneDirect3DXamlAppComponent {

/** 
* @brief zplugin interface for platform command handler.
* this interface declare methods for handle comunication between platform native code and cocos2dx.
*/
[Windows::Foundation::Metadata::WebHostHidden]
public interface class IPlatformCommandHandler
{
public:

	/** virtual function for implement in platform command handler for execute platform code
	* @param _className Class name in platform code with the function to execute
	* @param _funcName Function name in the class to execute
	* @param _params parameters to invoke the function, for complex objects can use json string.
	*/
	virtual void exec(Platform::String^ _className, Platform::String^ _funcName, Platform::String^ _params);
};

/** 
* @brief class for interop with native code
* this class handle comunication cocos2dx -> platform native.
*/
[Windows::Foundation::Metadata::WebHostHidden]
public ref class CommandHandler sealed
{ 
public: 

	/** function for set platform command handler for interop with platform code
	* @param _platformCommandHandler Object with platform command handler
	*/
	static void setPlatformCommandHandler(IPlatformCommandHandler^ _platformCommandHandler);

	/** function for execute platform code using the input parameters
	* @param _className Class name in platform code with the function to execute
	* @param _funcName Function name in the class to execute
	* @param _params parameters to invoke the function, for complex objects can use json string.
	*/
	static void execPlatformCommand(Platform::String^ _className, Platform::String^ _funcName, Platform::String^ _params);

};

} // namespace PhoneDirect3DXamlAppComponent

#endif // CC_PLATFORM_WP8

#endif /* __ZPLUGIN_COMMAND_HANDLER_H__ */