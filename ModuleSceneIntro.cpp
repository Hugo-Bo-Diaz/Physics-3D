#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	s.size = vec3(12, 3, 1);
	s.SetPos(0, 2.5f, 20);

	sensor = App->physics->AddBody(s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);

	//Create Map
	{
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(12, 1, 70);
		shape->SetPos(0, shape->size.y / 2, 0);

		part->body = App->physics->AddBody(*shape, 10000.0f);
		part->shape = shape;
		circuit.add(part);
	}
	{
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(12, 1, 25);
		shape->SetPos(-shape->size.x/2, shape->size.y / 2, 35.0f + shape->size.z/2);

		part->body = App->physics->AddBody(*shape, 10000.0f);
		part->shape = shape;
		circuit.add(part);
	}
	{
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(25, 1, 12);
		shape->SetPos(shape->size.x / 2 - 6, shape->size.y / 2, 35.0f + shape->size.z / 2 + 25);

		part->body = App->physics->AddBody(*shape, 10000.0f);
		part->shape = shape;
		circuit.add(part);
	}

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	


	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	sensor->GetTransform(&s.transform);
	s.Render();

	p2List_item<CircuitPart*>*  item = circuit.getFirst();

	while (item != NULL) {
		
		item->data->shape->Render();

		item = item->next;
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	LOG("Hit!");
}

