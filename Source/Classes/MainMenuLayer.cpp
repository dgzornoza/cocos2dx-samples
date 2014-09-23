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
		{ "Ejemplo Sprites", [](){ return BasicScene<MainMenuLayer>::create(); } },
	};

	/** Numero de elementos de la lista con los tests */
	static int g_testListCount = sizeof(g_testList) / sizeof(g_testList[0]);

	/** Enumeracion con los tags de los nodos a crear */
	enum class enumNodeTags : int
	{
		/** Layout del GUI principal */
		MAIN_LAYOUT = 1000
	};
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
	Size size = Director::getInstance()->getWinSize();

	// cachear los spriteframes del menu
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MainMenu.plist", "MainMenu.png");
	    
	// crear un layout principal para los controles UI
	ui::Layout* layout = ui::Layout::create();
	layout->setTag(static_cast<int>(enumNodeTags::MAIN_LAYOUT));
	this->addChild(layout);

	// crear el menu con los ejemplos
	this->_createMenu();

	// Crear el boton para cerrar la aplicacion
    ui::Button* button = ui::Button::create("cocosui/animationbuttonnormal.png",
		"cocosui/animationbuttonpressed.png", "", ui::Widget::TextureResType::PLIST);
    button->setPosition(Vec2(widgetSize.width / 2.0f, widgetSize.height / 2.0f));
//        button->addTouchEventListener(this, toucheventselector(UIButtonTest::touchEvent));
    button->addTouchEventListener(CC_CALLBACK_2(UIButtonTest::touchEvent, this));
    _uiLayer->addChild(button);

	// inicializacion correcta
	return true;
}	

/** Funcion para la creacion del menu principal */
void MainMenuLayer::_createMenu()
{		
	// obtener dimensiones de diseño
	Size size = Director::getInstance()->getWinSize();

	// obtener el layout principal del ui
	ui::Layout* layout = static_cast<ui::Layout*>(this->getChildByTag(static_cast<int>(enumNodeTags::MAIN_LAYOUT)));
	
	// crear el list view
	ui::ListView* lv = ui::ListView::create();
    lv->setItemsMargin(10);
	lv->setGravity(ui::ListView::Gravity::CENTER_HORIZONTAL);
	lv->setSize(Size(size.width, 250.0f));	
	
	// añadir todos los tests al list view
	for (int i = 0; i < g_testListCount; ++i)
    {
		ui::Text* text = ui::Text::create(g_testList[i].name, "fonts/American Typewriter.ttf", 25);
		text->setColor(Color3B(159, 168, 176));
		text->setTouchEnabled(true);		
		lv->pushBackCustomItem(text);
    }

	// añadir el listview al layout
    layout->addChild(lv);
}

/** Funcion callback para cerrar la aplicacion */
void MainMenuLayer::_menuCloseCallback(Ref* _sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}