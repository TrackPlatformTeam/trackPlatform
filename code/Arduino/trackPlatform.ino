#include <FastCRC_tables.h>
#include <FastCRC_cpu.h>
#include <FastCRC.h>
#include <SoftwareSerial.h>
#include <Servo.h>
#include "connection/DebugSerial.h"
#include "management/MainManager.h"
#include "management/CommandManager.h"
#include "connection/ConnectionManager.h"

void setup()
{
	DEBUG_PRINTF("Firmware was compiled on %s %s\n", __DATE__, __TIME__);
	DEBUG_PRINTF("Supports API from %d to %d\n", CommandManager::min_api, CommandManager::max_api);

	DEBUG_PRINTLN("Trying to start Arduino");

	// First init of static fields
	MainManager::get_manager();
	ConnectionManager::get_manager();
	CommandManager::getManager();

	DEBUG_PRINTLN("Arduino was started");
}

void loop()
{
	MainManager::get_manager()->run();
}
