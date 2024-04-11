#include "SceneOne.h"
#include "../../ApplicationRenderer.h"
#include "../../Player/PlayerController.h"
#include "../../PostProcessing bounds/CubeVolume.h"
#include "../../AI/Enemy.h"
#include "../../AI/GameManager.h"
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
    plane->name = "Plane";

    plane->LoadModel("Models/DefaultCube/DefaultCube.fbx");
    GraphicsRender::GetInstance().AddModelAndShader(plane, application->defaultShader);

    plane->transform.SetPosition(glm::vec3(0, -0.25f, 0));
    plane->transform.SetScale(glm::vec3(30.0f,0.2f, 30.0f));
    plane->Initialize(RigidBody::RigidBodyType::STATIC, BaseCollider::ColliderShape::BOX);

    Enemy* enemyOne = new Enemy(player);
    enemyOne->name = "Enemy 1";
    enemyOne->randomPointColor = glm::vec4(0, 0, 1, 1);

    enemyOne->AddRoamingPoints(20, 1, 1);
    enemyOne->AddRoamingPoints(12.10f, 1, 9.50f);
    enemyOne->AddRoamingPoints(16.80f, 1, -11.00f);
    enemyOne->AddRoamingPoints(5.40f, 1, -18.60f);
    enemyOne->AddRoamingPoints(6, 1, 14);



    Enemy* enemyTwo = new Enemy(player);
    enemyTwo->transform.SetPosition(glm::vec3(-2, 0, 0));
    enemyTwo->name = "Enemy 2";
    enemyTwo->randomPointColor = glm::vec4(0.25f, 0.75f, 1, 1);

    enemyTwo->AddRoamingPoints(-20, 1, 1);
    enemyTwo->AddRoamingPoints(-12.10f, 1, -9.50f);
    enemyTwo->AddRoamingPoints(-16.80f, 1, 11.00f);
    enemyTwo->AddRoamingPoints(-5.40f, 1, -18.60f);
    enemyTwo->AddRoamingPoints( -25.0f, 1, 5.0f);


    GameManager* gameManager = new GameManager();
    gameManager->player = player;
    gameManager->AddEnemies(enemyOne);
    gameManager->AddEnemies(enemyTwo);
}

void SceneOne::Update()
{
}

void SceneOne::Render()
{
}
