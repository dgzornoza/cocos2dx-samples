#ifndef __ZPLUGIN_ZMEDIA_H__
#define __ZPLUGIN_ZMEDIA_H__

#include "ZPlugin/IPlugin.h"

/**
* @addtogroup ZPlugin
* @{
*/

namespace cocos2d { namespace zplugin { namespace zmedia {

/**
 * Class for create ZMedia plugin. This plugin access to media files in device. audio, video and photos
*/
class ZMedia : public IPlugin
{

public:

	/// @{
    /// @name Enums

	/** enum with album type in device */
	enum class enumAlbumTypes : char
	{
		/** pictures album */
		PICTURES = 0
	};
    
	/** enum with album type in device */
	enum class enumAlbumItemTypes : char
	{
		/** album item type (album folder) */
		ALBUM = 0,
	   /** image item type */
        IMAGE = 1
	};

	/// @} End Enums


	/** Default constructor */
    ZMedia() {}

	/** Default destructor */
	virtual ~ZMedia() {}

	/// @{
    /// @name Properties setter/getters

	/** Get plug-in name 
	 * @return plugin name
	 */
	virtual const char* getPluginName() const override { return "ZMedia"; }
	/** Get plug-in version 
	 * @return plugin version
	 */
	virtual const char* getPluginVersion() const override { return "1.0"; }

	/// @} End Properties setter/getters




	/// @{
    /// @name Plugin functions


	void test()
	{
		// invocar codigo nativo del dispositivo
		this->exec("ZMedia", "test", "prueba de parametros");
	}

	/**
	* Funcion asincrona para obtener los items de un albun especificado mediante los parametros de entrada
	*
	* @param {Function} _albumFilter: Objeto del tipo 'AlbumFilterModel' serializado en JSON con el filtro para obtener los items
	* @param {Function} _successCallback: funcion que sera llamada si la peticion es correcta, 
	*   la funcion obtendra un parametro conteniendo un array de bytes con la imagen, o null en caso de no haber seleccionado ninguna
	* @param {Function} _errorCallback: funcion que sera llamada si en la peticion ocurre un error, la funcion obtendra un parametro con una cadena conteniendo el error
	* @param {Function} _allwaysCallback: funcion que sera llamada siempre tras la peticion, ocurra un error o no.
	*/
	//void GetAlbumItems(_albumFilter) 
	//{
	//	// invocar codigo nativo del dispositivo
	//	exec(function (_result) {
	//		_successCallback(_result);
	//		_allwaysCallback();
	//	},
	//		function (_error) {
	//			_errorCallback(_error);
	//			_allwaysCallback();
	//		},
	//		'ZMedia', 'GetAlbumItems', [JSON.stringify(_albumFilter)]);
	//};

	/// @} End Properties setter/getters


};


}}} //namespace cocos2d { namespace zplugin { namespace zmedia {

// end of ZPlugin group
/// @}

#endif /* __ZPLUGIN_ZMEDIA_H__ */
