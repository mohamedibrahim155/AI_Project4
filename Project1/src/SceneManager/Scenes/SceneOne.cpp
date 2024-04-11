#include "SceneOne.h"
#include "../../ApplicationRenderer.h"
#include "../../Player/PlayerController.h"
#include "../../PostProcessing bounds/CubeVolume.h"
SceneOne::SceneOne(const std::string& sceneName) : BaseScene::BaseScene(sceneName)
{
	
}

void SceneOne::Start()
{
    Light* directionLight = new Light();
    directionLight->Initialize(LightType::DIRECTION_LIGHT, 1);
    directionLight->SetAmbientColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.0f));

    directionLight->SetColor(glm::vec4(1, 1, 1, 1.0f));
    directionLight->SetAttenuation(1, 1, 0.01f);
    directionLight->SetInnerAndOuterCutoffAngle(11, 12);

    directionLight->transform.SetRotation(glm::vec3(-28.0f, 0, 0));
    directionLight->transform.SetPosition(glm::vec3(0, 0, 5));

    PlayerController* player = new PlayerController(application);

    //PhysXObject* terrain = new PhysXObject();
    //terrain->LoadModel("Models/Terrain/Terrain.fbx");
    //GraphicsRender::GetInstance().AddModelAndShader(terrain, application->defaultShader);
    //terrain->name = "Terrain";
    //terrain->transform.SetPosition(glm::vec3(0, -2, 0));
    //terrain->transform.SetRotation(glm::vec3(-90, 0, 0));
    //terrain->Initialize(RigidBody::RigidBodyType::STATIC, BaseCollider::ColliderShape::MESH);

    PhysXObject* plane = new PhysXObject();
    plane->LoadModel("Models/DefaultCube/DefaultCube.fbx");
    GraphicsRender::GetInstance().AddModelAndShader(plane, application->defaultShader);

    plane->transform.SetPosition(glm::vec3(0, -2, 0));
    plane->transform.SetScale(glm::vec3(30.0f,0.2f, 30.0f));
    plane->Initialize(RigidBody::RigidBodyType::STATIC, BaseCollider::ColliderShape::BOX);


}

void SceneOne::Update()
{
}

void SceneOne::Render()
{
}
