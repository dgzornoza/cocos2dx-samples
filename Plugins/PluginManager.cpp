#include "PluginManager.h"

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

/** unload the plugin by name */
void PluginManager::unloadPlugin(const char* _pluginName)
{
	// verify plugin name
	assert(_pluginName == nullptr || strlen(_pluginName) == 0, "Plugin name is required");

	// find plugin name in plugins map
    std::map<const char*, IPlugin*>::iterator it = m_pluginsMap.find(_pluginName);
	// if found, delete
	if (it != m_pluginsMap.end())
    {
        if (it->second != nullptr) 
		{
            delete it->second;
            it->second = nullptr;
        }
		m_pluginsMap.erase(it);
    }
}

}} //namespace cocos2d { namespace zplugin {
