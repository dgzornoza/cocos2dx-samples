#ifndef __LANGUAGE_MANAGER_H__
#define __LANGUAGE_MANAGER_H__

#include <string>
#include "cocos2d.h"
#include "json\document.h"


/** 
*@brief Clase para gestionar el multi-idioma en la aplicacion.
*/
class LanguageManager
{	

public:

	/** constructor por defecto */
	virtual ~LanguageManager();

	/** Funcion para obtener la instancia de la clase
	 * @return Unica instancia de la clase 'LanguageManager'
	 */
    static LanguageManager* getInstance();

	/** Funcion para obtener una cadena especificada por la clave de entrada en el idioma actual. Se permiten claves anidadas en forma de objetos ej: "SpritesSampleLayer.title"
	* @param _key clave a buscar en los recursos de idiomas
	* @return cadena en el idioma actual para la clave especificada, cadena vacia en caso de no encontrarse.
	*/
    std::string localize(std::string _key);


private:

	/** Constructor por defecto  */
	LanguageManager ();     
	/** constructor copia  */
	LanguageManager (LanguageManager const &);

	/** singleton instance */
	static LanguageManager* s_languageManager;

	/** Rapidjson document with json data for current language */
	rapidjson::Document m_jsonLangdocument;

};


#endif // __LANGUAGE_MANAGER_H__

