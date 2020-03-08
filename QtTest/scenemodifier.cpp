#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity) : m_rootEntity(rootEntity)
{
	// Cuboid shape data
	Qt3DExtras::QCuboidMesh *cuboid = new Qt3DExtras::QCuboidMesh();

	// CuboidMesh Transform
	Qt3DCore::QTransform *cuboidTransform = new Qt3DCore::QTransform();
	cuboidTransform->setScale(4.0f);
	cuboidTransform->setTranslation(QVector3D(0.0f, -8.0f, 0.0f));

	Qt3DExtras::QPhongMaterial *cuboidMaterial = new Qt3DExtras::QPhongMaterial();
	cuboidMaterial->setDiffuse(QColor(QRgb(0x665423)));

	//Cuboid
	m_cuboidEntity = new Qt3DCore::QEntity(m_rootEntity);
	m_cuboidEntity->addComponent(cuboid);
	m_cuboidEntity->addComponent(cuboidMaterial);
	m_cuboidEntity->addComponent(cuboidTransform);

	// Plane shape data
	Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
	planeMesh->setWidth(20);
	planeMesh->setHeight(20);

	// Plane mesh transform
	Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
	//planeTransform->setScale(1.3f);
	//planeTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
	planeTransform->setTranslation(QVector3D(0.0f, -10.0f, 0.0f));

	Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
	planeMaterial->setDiffuse(QColor(QRgb(0xa69929)));

	// Plane
	m_planeEntity = new Qt3DCore::QEntity(m_rootEntity);
	m_planeEntity->addComponent(planeMesh);
	m_planeEntity->addComponent(planeMaterial);
	m_planeEntity->addComponent(planeTransform);
}
