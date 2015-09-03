#include "LanguageManager.h"
#include "Toolkit.Helpers\include\StringUtils.h"

using namespace cocos2d;

// inicializar el singleton
LanguageManager* LanguageManager::s_languageManager = nullptr;

/** Constructor por defecto  */
LanguageManager::LanguageManager()
{
    // obtener el nombre del archivo con el idioma
	std::string langFile = "locales/" + std::string(Application::getInstance()->getCurrentLanguageCode()) + ".lang";

	// abrir el archivo de recursos con el idioma correspondiente	
	std::string data = CCFileUtils::getInstance()->getStringFromFile(langFile);

	// verificar que existe, en caso contrario se carga el idioma por defecto
	if(data.empty())
	{
		CCLOG("Idioma desconocido o no implementado, sera usado ingles por defecto");
		data = CCFileUtils::getInstance()->getStringFromFile("locales/en.lang");
	}

	// parsear el documento usando la libreria rapidjson
    m_jsonLangdocument.Parse<0>(data.c_str());
    if(m_jsonLangdocument.HasParseError())
    {
		CCLOG((std::string("Error al parsear el archivo de idioma : ") + langFile).c_str());
        return;
    }
}

/** Destructor por defecto  */
LanguageManager::~LanguageManager()
{
}


/** Funcion para obtener la instancia de la clase */
LanguageManager* LanguageManager::getInstance()
{
	// crear solo la primera vez
	if (nullptr == s_languageManager) s_languageManager = new LanguageManager();
    return s_languageManager;
}

/** Funcion para obtener una cadena especificada por la clave de entrada en el idioma actual. Se permiten claves anidadas en forma de objetos ej: "SpritesSampleLayer.title" */
std::string LanguageManager::localize(std::string _key)
{
	std::string result;

	// separar la clave por puntos (para permitir usar objetos complejos)
	std::vector<std::string> keys = Toolkit::Helpers::StringUtils::Split(_key, ".");

	// obtener la referencia al primer objeto	
	if (!m_jsonLangdocument.HasMember(keys.front().c_str())) return result;
	rapidjson::Value& currentObj = m_jsonLangdocument[keys.front().c_str()];

	// recorrer todas las claves anidadas en el objeto json para obtener el valor final
	for (size_t i = 1; i < keys.size(); i++)
	{
		// verificar que existe la clave
		if (!currentObj.HasMember(keys[i].c_str())) break;
		// actualizar la referencia al objeto anidado
		currentObj = currentObj[keys[i].c_str()];
	}
		
	// obtener la cadena y retornarla
	CCASSERT(currentObj.IsString(), "Error in JSON file for language, value should be string");

	return currentObj.GetString();
}