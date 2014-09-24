#include "AppDelegate.h"

using namespace cocos2d;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	// HACK: verificar (NO funciona)
	//std::locale::global(std::locale(""));
	
    // inicializar director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("SamplesGLView"); // 3:2
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1280, 1024)); // 5:4
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1280, 720)); // 16:9
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1067, 600)); // 16:9

		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 960, 640)); // 3:2
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 480, 320)); // 3:2
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1024, 768)); // 4:3
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1280, 768)); // 5:3
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 1280, 720)); // 16:9

		// portrait
		//glview = GLView::createWithRect("SamplesGLView", Rect(0,0, 640, 960)); // 3:2

        director->setOpenGLView(glview);
    }

    // activar depuracion FPS
    director->setDisplayStats(true);
	
	// establecer FPS. El valor por defecto es 1.0/60 si no se llama
    director->setAnimationInterval(1.0 / 60);

	// MULTIRESOLUCION -----------------------------------------

	// guardar dimensiones de pantalla y resolucion de diseño
	Size screenSize = glview->getFrameSize();
	Size designSize = Size(480, 320); // 4 pixeles por pixel
	
	// guardar directorio y dimensiones usados en los recursos
    std::vector<std::string> searchPaths;
	Size resourceSize;
	if (screenSize.width > 960)
    {
		resourceSize = Size(1920, 1280);
        searchPaths.push_back("HDR");
    }
	else if (screenSize.width > 480)
    {
        resourceSize = Size(960, 640);
        searchPaths.push_back("HD");
    }
	else
	{
		resourceSize = Size(480, 320);
		searchPaths.push_back("SD");
	}

	// establecer el factor de escala basado en el tamaño de los recursos y las dimensiones de diseño
	director->setContentScaleFactor(resourceSize.width/designSize.width);
	// establecer la resolucion de diseño
	glview->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::FIXED_HEIGHT);
	// establecer directorios base de los recursos
	FileUtils::getInstance()->setSearchPaths(searchPaths);

	// ----------------------------------------------------------
	
    // Crear la escena principal y ejecutarla
	Scene* scene = BasicScene<MainMenuLayer>::create();
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
