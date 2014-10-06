#include "Wrapper.h"

namespace cocos2d { namespace zplugin { namespace Wrapper {


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)

BroswerEventHelper::BroswerEventHelper(void){}

ICallback ^CSCallback = nullptr;
void BroswerEventHelper::SetCallback( ICallback ^Callback)
{
	CSCallback = Callback;
}

void BroswerEventHelper::callCSharp()
{
	CCLog("in CPP method");
	if (CSCallback != nullptr)
	{
		CCLog("Value not null");
		//Send your parameters from here 
		CSCallback->Exec( "Hello", "Suveer Jacob" );
	}
}

#endif

}}} // namespace cocos2d { namespace zplugin { namespace Wrapper {