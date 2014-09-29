#include "PluginManager.h"
#include "PluginFactory.h"

namespace cocos2d { namespace zplugin {

// initialize singleton
PluginManager* PluginManager::s_pluginManager = nullptr;

/** Default constructor */
PluginManager::PluginManager(void)
{
}

/** Default destructor */
PluginManager::~PluginManager()
{
	// delete all plugins
	for (auto &_plugin : m_pluginsMap)
	{
		if(_plugin.second != nullptr) delete _plugin.second;
	};

	// clean plugins map
	m_pluginsMap.clear();

	// ?
	//PluginFactory::purgeFactory();

	// remove instance
	s_pluginManager = nullptr;
}

/** Get singleton of PluginManager */
PluginManager* PluginManager::getInstance()
{
	// create only first
	if (s_pluginManager == nullptr) s_pluginManager = new PluginManager();

    return s_pluginManager;
}

/** load the plugin by name */
IPlugin* loadPlugin(const char* _pluginName)
{
    IPlugin* plugin = nullptr;
    do {
		if (_pluginName == nullptr || strlen(_pluginName) == 0) break;
        std::map<const char*, IPlugin*>::iterator it = m_pluginsMap.find(_pluginName);
        if (it != m_pluginsMap.end())
        {
            if (it->second == NULL) {
                it->second = PluginFactory::getInstance()->createPlugin(m_pluginsMap);
            }
            plugin = it->second;
        } else
        {
        	plugin = PluginFactory::getInstance()->createPlugin(m_pluginsMap);
        	m_pluginsMap[_pluginName] = plugin;
        }
    } while (false);

    return plugin;
}


/** unload the plugin by name */
void unloadPlugin(const char* _pluginName)
{
    do {
        if (_pluginName == NULL || strlen(_pluginName) == 0) break;
        std::map<std::string, PluginProtocol*>::iterator it = m_pluginsMap.find(_pluginName);
		if (it != m_pluginsMap.end())
        {
            if (it->second != nullptr) {
                delete it->second;
                it->second = nullptr;
            }
        }
    } while (false);
}

}} //namespace cocos2d { namespace zplugin {
