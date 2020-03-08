#include "GLWidget.h"

GLWidget::GLWidget()
{
	Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
	view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
	QWidget *container = QWidget::createWindowContainer(view);
	
	QHBoxLayout *hLayout = new QHBoxLayout(this);
	hLayout->addWidget(container, 1);

	Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
	view->registerAspect(input);

	// Root entity
	Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

	// Camera
	Qt3DRender::QCamera *cameraEntity = view->camera();

	cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
	cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
	cameraEntity->setUpVector(QVector3D(0, 1, 0));
	cameraEntity->setViewCenter(QVector3D(0, 0, 0));

	Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
	Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
	light->setColor("white");
	light->setIntensity(1);
	lightEntity->addComponent(light);
	Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
	lightTransform->setTranslation(cameraEntity->position());
	lightEntity->addComponent(lightTransform);

	// For camera controls
	Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
	camController->setCamera(cameraEntity);

	// Scenemodifier
	SceneModifier *modifier = new SceneModifier(rootEntity);

	// Set root object of the scene
	view->setRootEntity(rootEntity);
}