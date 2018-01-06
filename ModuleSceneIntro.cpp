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
	s.SetPos(0, 2.501f, 20);

	sensor = App->physics->AddBody(s, 0.0f);
	sensor->SetAsSensor(true);
	sensor->collision_listeners.add(this);

	//Create Map

	//principal circuit
	{//1
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(14, 1, 50);
		shape->SetPos(-1, shape->size.y / 2, 0);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}
	{//2
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 20);
		shape->SetPos(-6.7, shape->size.y / 2, 19.5 + shape->size.z/2);
		shape->SetRotation(-30, {0,1,0});

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}
	{//3
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 30);
		shape->SetPos(-10, shape->size.y / 2 + 5, 48.0f);
		shape->SetRotation(-20, {1,0,0});

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//4
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 15);
		shape->SetPos(-10, shape->size.y / 2 + 10.2, 69.2f);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}


	{//5
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(20, 1, 30);
		shape->SetPos(0, shape->size.y / 2 + 10.2, 79.8f);

		//float inc_y = sin(45 * 3.14/180);
		//float inc_z = sin(60 * 3.14 / 180);

		shape->SetRotation(45, {0,1,0 });
		//shape->SetRotation( 90, { 0,0,inc_z });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//6
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 30);
		shape->SetPos(19, shape->size.y / 2 + 10.2, 91.0f);

		//float inc_y = sin(45 * 3.14/180);
		//float inc_z = sin(60 * 3.14 / 180);

		shape->SetRotation(90, { 0,1,0 });
		//shape->SetRotation( 90, { 0,0,inc_z });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//7
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(17, 1, 30);
		shape->SetPos(36, shape->size.y / 2 + 10.2, 82.0f);

		//float inc_y = sin(45 * 3.14/180);
		//float inc_z = sin(60 * 3.14 / 180);

		shape->SetRotation(135, { 0,1,0 });
		//shape->SetRotation( 40, { 0,0,1 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//8
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 60);
		shape->SetPos(45, shape->size.y / 2 + 10.2, 50.2f);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//9
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(15, 1, 30);
		shape->SetPos(40, shape->size.y / 2 + 10.2, 15.0f);

		shape->SetRotation(30, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//10
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(35, 1, 15);
		shape->SetPos(20, shape->size.y / 2 + 10.2, 5.5f);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//11
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(20, 1, 15);
		shape->SetPos(-7, shape->size.y / 2 + 8.5f, 5.5f);
	
		shape->SetRotation(10, {0,0,1});

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//12
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(25, 1, 15);
		shape->SetPos(-29, shape->size.y / 2 + 3.5f, 5.5f);

		shape->SetRotation(15, { 0,0,1 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//13
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(25, 1, 15);
		shape->SetPos(-50, shape->size.y / 2, 5.5f);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//14
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(20, 1, /**/18);
		shape->SetPos(-65, shape->size.y / 2, 10);
		shape->SetRotation(45, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//15
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(20, 1, /**/18);
		shape->SetPos(-73, shape->size.y / 2, 22);
		shape->SetRotation(75, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//16
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(/**/18, 1, 35);
		shape->SetPos(-75, shape->size.y / 2, 47.5);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//17
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(/**/18, 1, 20);
		shape->SetPos(-71, shape->size.y / 2, 70);
		shape->SetRotation(30, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//18
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(/**/18, 1, 20);
		shape->SetPos(-62, shape->size.y / 2, 80);
		shape->SetRotation(60, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//19
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(30, 1, 18/**/);
		shape->SetPos(-48, shape->size.y / 2, 85);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//20
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 35);
		shape->SetPos(-23, shape->size.y / 2, 78);
		shape->SetRotation(120, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//21
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 70);
		shape->SetPos(0, shape->size.y / 2, 58);
		shape->SetRotation(140, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//22
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 35);
		shape->SetPos(22, shape->size.y / 2, 20);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//23
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 10);
		shape->SetPos(22, shape->size.y / 2 + 0.5, -2);
		shape->SetRotation(6, { 1,0,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	//{//24
	//	CircuitPart* part = new CircuitPart;
	//	Cube* shape = new Cube;
	//	shape->size = vec3(18/**/, 1, 10);
	//	shape->SetPos(22, shape->size.y / 2 + 1, -40);
	//	shape->SetRotation(-10, { 1,0,0 });
	//	part->body = App->physics->AddBody(*shape, 0);
	//	part->shape = shape;
	//	circuit.add(part);
	//}

	{//24
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 60);
		shape->SetPos(22, shape->size.y / 2, -55);

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//25
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 25);
		shape->SetPos(15, shape->size.y / 2, -89);
		shape->SetRotation(45, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//26
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 25);
		shape->SetPos(8, shape->size.y / 2, -89);
		shape->SetRotation(135, { 0,1,0 });

		part->body = App->physics->AddBody(*shape, 0);
		part->shape = shape;
		circuit.add(part);
	}

	{//27
		CircuitPart* part = new CircuitPart;
		Cube* shape = new Cube;

		shape->size = vec3(18/**/, 1, 65);
		shape->SetPos(0, shape->size.y / 2, -57);

		part->body = App->physics->AddBody(*shape, 0);
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
	if (body1->IsSensor() || body2->IsSensor()) {
		LOG("Hit!");

	}

}

