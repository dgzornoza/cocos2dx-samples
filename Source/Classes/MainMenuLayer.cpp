#include "MainMenuLayer.h"

using namespace cocos2d;

// Namespace anonimo para crear objetos SOLO en el ambito de este archivo cpp
namespace
{
	/** Estructura para crear la lista de tests de la aplicaicon */
	typedef struct st_testList
	{
		/** Nombre del test */
		const char* name;
		/** Puntero a la funcion con la escena del test a ejecutar */
		std::function<Scene*()> callback;

	} TestList;

	/** Estructura para crear la lista de tests de la aplicacion */
	TestList g_testList[] = {
				
		//
		// TESTS ORDENADOS ALFABETICAMENTE
		//
		{ "Ejemplo Sprites", [](){ return BasicScene<SpritesSampleLayer>::create(); } },
	};

	/** Numero de elementos de la lista con los tests */
	static int g_testListCount = sizeof(g_testList) / sizeof(g_testList[0]);
}

/** Constructor por defecto de la clase */
MainMenuLayer::MainMenuLayer(void)
{

}

/** Destructor por defecto de la clase */
MainMenuLayer::~MainMenuLayer(void)
{
}

/** 
* Metodo sobreescrito que sera invocado para inicializar la instancia de la clase
* @return True si se puede ha inicializado correctamente, false en caso contrario
*/
bool MainMenuLayer::init()
{
	// Inicializar la clase base
	if ( !Layer::init() ) return false;

	// obtener dimensiones de diseño
	Size screenSize = Director::getInstance()->getWinSize();

	// cachear los spriteframes del menu
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MainMenu.plist", "MainMenu.png");
	    
	// crear un layout principal para los controles UI
	ui::Layout* layout = ui::Layout::create();
	layout->setSize(screenSize);
	this->addChild(layout);

	// crear el menu con los ejemplos
	this->_createMenu(layout);
	// crear el boton para cerrar la aplicacion
	this->_createCloseButton(layout);


	// inicializacion correcta
	return true;
}	

/** Funcion para la creacion del menu principal */
void MainMenuLayer::_createMenu(ui::Layout* _layout)
{
	// crear el list view
	ui::ListView* lv = ui::ListView::create();
    lv->setItemsMargin(10);
	lv->setGravity(ui::ListView::Gravity::CENTER_HORIZONTAL);
	lv->setSize(Size(Director::getInstance()->getWinSize().width, 250.0f));	

	// añadir todos los tests al list view
	for (int i = 0; i < g_testListCount; ++i)
    {
		ui::Text* text = ui::Text::create(g_testList[i].name, "fonts/American Typewriter.ttf", 25);
		text->setColor(Color3B(159, 168, 176));
		text->setTouchEnabled(true);		
		lv->pushBackCustomItem(text);
    }
	
	// eventos de seleccion de items
	//lv->addEventListener((ui::ListView::ccListViewCallback)CC_CALLBACK_2(UIListViewTest_Vertical::selectedItemEvent, this));
	lv->addEventListener((ui::ListView::ccListViewCallback)[](Ref* _sender, ui::ListView::EventType _type)		
	{
		// evaluar el tipo de evento generado
		switch (_type)
		{

		case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
				
			// eliminar todos los datos de la cache de esta capa
			Director::getInstance()->purgeCachedData();

			// crear la escena con el ejemplo seleccionado por el indice del listview
			Scene* scene = g_testList[static_cast<ui::ListView*>(_sender)->getCurSelectedIndex()].callback();

			// cambiar a la escena del ejemplo
			Director::getInstance()->replaceScene(scene);

			break;
		}
	});


	// añadir el listview al layout
    _layout->addChild(lv);
}

/** Funcion para crear el boton para cerrar la aplicacion */
void MainMenuLayer::_createCloseButton(ui::Layout* _layout)
{
	// Crear el boton para cerrar la aplicacion
    ui::Button* closeBtn = ui::Button::create("close_normal.png",	"close_selected.png", "", ui::Widget::TextureResType::PLIST);
	closeBtn->setPosition(Director::getInstance()->getWinSize() - closeBtn->getSize());

	// eventos
	closeBtn->addTouchEventListener([](Ref* _sender, ui::Widget::TouchEventType _evtType)
	{			
		// evaluar el tipo de evento generado
		switch (_evtType)
		{

		case ui::Widget::TouchEventType::ENDED :

				// Finalizar la aplicacion
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
				MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
				return;
#endif
				Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
				exit(0);
#endif
				break;

		}
	});

    _layout->addChild(closeBtn);
}

