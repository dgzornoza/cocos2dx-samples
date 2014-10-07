#ifndef __ZPLUGIN_ICOMMAND_HANDLER_H__
#define __ZPLUGIN_ICOMMAND_HANDLER_H__



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
	virtual void Exec( Platform::String ^Command, Platform::String ^Param); 
};

} // namespace cocos2d { namespace zplugin

#endif // CC_PLATFORM_WP8


#endif /* __ZPLUGIN_ICOMMAND_HANDLER_H__ */