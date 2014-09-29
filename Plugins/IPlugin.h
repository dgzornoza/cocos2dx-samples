#ifndef __ZPLUGIN_IPLUGIN_H__
#define __ZPLUGIN_IPLUGIN_H__

namespace cocos2d { namespace zplugin {

/**
 * Interface for create cocos2dx zplugins
*/
class IPlugin
{

public:

	/** Default destructor */
    virtual ~IPlugin(void);

	/** Get plug-in name 
	 * @return plugin name
	 */
    virtual const char* getPluginName() const = 0;
	/** Get plug-in version 
	 * @return plugin version
	 */
    virtual const char* getPluginVersion() const;

    /**
     * Async method for invoke platform code
	 * @param _funcName function name to execute
	 * @param _params function parameters
     */
    void execAsync(const char* _funcName, std::string _params);

	/**
     * Method for invoke platform code
	 * @param _funcName function name to execute
	 * @param _params function parameters
	 * @return return value from platform code
     */
    std::string exec(const char* funcName, std::string _params);

protected:

	/** Default constructor */
    IPlugin() {}

};

}} //namespace cocos2d { namespace zplugin {

#endif /* __ZPLUGIN_IPLUGIN_H__ */
