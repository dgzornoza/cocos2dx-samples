#ifndef __ZPLUGIN_IPLUGIN_H__
#define __ZPLUGIN_IPLUGIN_H__

namespace cocos2d { namespace zplugin {

/**
 * Interface for create cocos2dx zplugins
*/
class IPlugin
{

public:

	/** Default constructor */
    IPlugin() {}

	/** Default destructor */
	virtual ~IPlugin(void) {}

	/** Get plug-in name 
	 * @return plugin name
	 */
    virtual const char* getPluginName() const = 0;
	/** Get plug-in version 
	 * @return plugin version
	 */
	virtual const char* getPluginVersion() const = 0;

protected:

	/**
     * Method for invoke platform native code
	 * @param _className class namespace and name
	 * @param _funcName function name to execute
	 * @param _params function parameters
	 * @return return value from platform code
     */
    void exec(const char* _className, const char* _funcName, std::string _params)
	{

	};
	
};


}} //namespace cocos2d { namespace zplugin {

#endif /* __ZPLUGIN_IPLUGIN_H__ */
