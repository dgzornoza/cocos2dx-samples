#ifndef __ZPLUGIN_WRAPPER_H__
#define __ZPLUGIN_WRAPPER_H__

namespace cocos2d { namespace zplugin { namespace Wrapper {

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)


[Windows::Foundation::Metadata::WebHostHidden]
public interface class ICallback
{
public:

	//Exec(..) is the virtual method that will be implemented in your .cs file
	virtual void Exec( Platform::String ^Command, Platform::String ^Param); 
};

public ref class BroswerEventHelper sealed
{ 
public: 
	BroswerEventHelper ( void );
	static void SetCallback( ICallback ^Callback);
	static void callCSharp();
};



#endif

}}} // namespace cocos2d { namespace zplugin { namespace Wrapper {

#endif /* __ZPLUGIN_WRAPPER_H__ */