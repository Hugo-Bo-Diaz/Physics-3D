#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "Timer.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

struct CircuitPart {
	PhysBody3D* body;
	Primitive* shape;

	~CircuitPart()
	{
		
	}
};

struct Sensor {
	Cube* shape;
	PhysBody3D* body;
	int id;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	void SetToCP(PhysVehicle3D* v);

public:

	//Plane p;
	Cube* pl;
	PhysBody3D* plane_sensor;

	p2List<CircuitPart*> circuit;

	p2List<Sensor*> sensors;

	int last_cp = 1;

	bool set_to_cp = false;

	Timer reset_timer;

};
