#ifndef __SPRITES_SAMPLE_LAYER_H__
#define __SPRITES_SAMPLE_LAYER_H__

#include "cocos2d.h"
#include "Headers.h"

/** 
*@brief Clase con la capa para el ejemplo del articulo dedicado a los sprites
*/
class SpritesSampleLayer : public LayerBase
{

public:

	/** Destructor por defecto de la clase */
	virtual ~SpritesSampleLayer(void);

	/** 
	* Macro que sera desplegada en un metodo estatico 'create' para crear e inicializar la instancia de la clase.
	* La instancia de la clase debe ser creada invocando el metodo 'SpritesSampleLayer::create()'
	*/
	CREATE_FUNC(SpritesSampleLayer);


	// se hace uso de la macro de cocos2dx para definir el acceso de metodos heredados
	// con la finalidad de no violar el principio de sustitucion de Liskov y usar el mismo modificador de las clases base)
CC_CONSTRUCTOR_ACCESS:

	/** 
	* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase.
	* @return True si se puede ha inicializado correctamente, false en caso contrario
	*/
	virtual bool init() override;

protected:

	/** Constructor por defecto de la clase (protegido para evitar que se creen instancias desde fuera de la clase, deben crearse mediante el metodo 'SpritesSampleLayer::create()')*/
	SpritesSampleLayer(void);



private:



};

#endif // __SPRITES_SAMPLE_LAYER_H__
