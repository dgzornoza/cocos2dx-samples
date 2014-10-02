#ifndef __ZPLUGIN_PLUGINMANAGER_H__
#define __ZPLUGIN_PLUGINMANAGER_H__

#include "IPlugin.h"
#include <map>
#include <string>
#include <type_traits> 

namespace cocos2d { namespace zplugin {

/**
 * class for manage cocos2dx zplugins
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

	/** load plugin by name
	 * @param _pluginName name for plugin identity
	 * @return plugin loaded
	 */
	template<class TPlugin, typename std::enable_if<std::is_base_of<IPlugin, TPlugin>::value>::type* = nullptr>
	TPlugin* loadPlugin(const char* _pluginName)
	{
		// verify plugin name
		assert(_pluginName == nullptr || strlen(_pluginName) == 0, "Plugin name is required");

		// result
		IPlugin* plugin = nullptr;

		// find plugin name in plugins map
		std::map<const char*, IPlugin*>::iterator it = m_pluginsMap.find(_pluginName);
		// found
		if (it != m_pluginsMap.end())
		{
			// verify plugin pointer, create if not foun and insert in plugin map
			if (it->second == NULL) it->second = new TPlugin();
			assert(!std::is_same<typeof(it->second), TPlugin>::value, "Already plugin loaded with other type.");
			plugin = it->second;
		} 
		// not found. create plugin and insert in plugin map
		else
		{
        	plugin = = new TPlugin();
        	m_pluginsMap[_pluginName] = plugin;
		}
		
		// return loaded plugin
		return plugin;
	}

    /** unload the plugin by name 
	* @param _pluginName plugin name for unload
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
