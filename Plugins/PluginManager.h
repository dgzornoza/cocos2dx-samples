#ifndef __ZPLUGIN_PLUGINMANAGER_H__
#define __ZPLUGIN_PLUGINMANAGER_H__

#include "IPlugin.h"
#include <map>
#include <string>

namespace cocos2d { namespace zplugin {

/**
 * Interface for manage cocos2dx zplugins
*/
class PluginManager
{

public:

	/** Default destructor */
	virtual ~PluginManager();

	/** Get singleton of PluginManager 
	 * @return Unique instance of PluginManager
	 */
    static PluginManager* getInstance();
    
    /** load the plugin by name
	 * @param _pluginName plugin name for load
	 * @return plugin loaded
	 */
    IPlugin* loadPlugin(const char* _pluginName);

    /** unload the plugin by name 
	* @param _pluginName plugin name for load
	*/
    void unloadPlugin(const char* _pluginName);

private:

	/** Default constructor  */
	PluginManager (void);     
	/** Default constructor copy */
	PluginManager (PluginManager const &);

	/** Map of loaded plugins */
    std::map<const char*, IPlugin*> m_pluginsMap;

	/** singleton instance */
	static PluginManager* s_pluginManager;
};


}} //namespace cocos2d { namespace zplugin {

#endif /* __ZPLUGIN_PLUGINMANAGER_H__ */
