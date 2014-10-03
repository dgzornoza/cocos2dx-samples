#ifndef __ZPLUGIN_PLUGINFACTORY_H__
#define __ZPLUGIN_PLUGINFACTORY_H__

#include "IPlugin.h"
#include <map>
#include <string>
#include <type_traits> 

namespace cocos2d { namespace zplugin {

/**
 * class for manage cocos2dx zplugins
*/
class PluginFactory
{

public:

	/** Default destructor */
	virtual ~PluginFactory();

	/** Get singleton of PluginFactory 
	 * @return Unique instance of PluginFactory
	 */
    static PluginFactory* getInstance();

	/** load plugin by name
	 * @param _pluginName unique name for plugin identity
	 * @return plugin loaded
	 */
	template<class TPlugin, typename std::enable_if<std::is_base_of<IPlugin, TPlugin>::value>::type*>
	TPlugin* loadPlugin(const char* _pluginName)
	{
		// verify plugin name
		CCASSERT(_pluginName == nullptr || strlen(_pluginName) == 0, "Plugin name is required");

		// result
		TPlugin* plugin = nullptr;

		// find plugin name in plugins map		
		std::map<const char*, IPlugin*>::iterator it = m_pluginsMap.find(_pluginName);
		// found
		if (it != m_pluginsMap.end())
		{
			// verify plugin pointer, create if not found and insert in plugins map
			if (it->second == nullptr) it->second = new TPlugin();
			CCASSERT(plugin = dynamic_cast<TPlugin>(it->second), "Already plugin loaded with other type.");			
		}
		// not found. create plugin and insert in plugin map
		else
		{
        	plugin = new TPlugin();
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
	PluginFactory (void);     
	/** Default constructor copy */
	PluginFactory (PluginFactory const &);

	/** Map of loaded plugins */
    std::map<const char*, IPlugin*> m_pluginsMap;

	/** singleton instance */
	static PluginFactory* s_pluginFactory;
};


}} //namespace cocos2d { namespace zplugin {

#endif /* __ZPLUGIN_PLUGINFACTORY_H__ */
