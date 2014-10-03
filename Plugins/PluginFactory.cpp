﻿#include "PluginFactory.h"

namespace cocos2d { namespace zplugin {

// initialize singleton
PluginFactory* PluginFactory::s_pluginFactory = nullptr;

/** Default constructor */
PluginFactory::PluginFactory(void)
{
}

/** Default destructor */
PluginFactory::~PluginFactory()
{
	// delete all plugins
	for (auto& _plugin : m_pluginsMap)
	{
		if(_plugin.second != nullptr) delete _plugin.second;
	};

	// clean plugins map
	m_pluginsMap.clear();

	// remove instance
	s_pluginFactory = nullptr;
}

/** Get singleton of PluginManager */
PluginFactory* PluginFactory::getInstance()
{
	// create only first
	if (s_pluginFactory == nullptr) s_pluginFactory = new PluginFactory();

    return s_pluginFactory;
}

/** unload the plugin by name */
void PluginFactory::unloadPlugin(const char* _pluginName)
{
	// verify plugin name
	CCASSERT(_pluginName == nullptr || strlen(_pluginName) == 0, "Plugin name is required");

	// find plugin name in plugins map
    std::map<const char*, IPlugin*>::iterator it = m_pluginsMap.find(_pluginName);
	// if not found, return
	if (it == m_pluginsMap.end()) return;

	// delete plugin and erase key/value from plugins map
    if (it->second != nullptr) delete it->second;
	m_pluginsMap.erase(it);
}

}} //namespace cocos2d { namespace zplugin {
