#include "hooks.h"

bool CreateMove::SendPacket = true;

bool Hooks::CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd)
{
	clientMode_vmt->GetOriginalMethod<CreateMoveFn>(25)(thisptr, flInputSampleTime, cmd);

	if (cmd && cmd->command_number)
	{
		*bSendPacket = CreateMove::SendPacket;
		CreateMove::SendPacket = true;

		BHop::CreateMove(cmd);
		AutoStrafe::CreateMove(cmd);
		Chams::CreateMove(cmd);
		ShowRanks::CreateMove(cmd);

		PredictionSystem::StartPrediction(cmd);
		Aimbot::CreateMove(cmd);
		Triggerbot::CreateMove(cmd);
		AntiAim::CreateMove(cmd);
		Airstuck::CreateMove(cmd);
		Teleport::CreateMove(cmd);
		FakeLag::CreateMove(cmd);
		PredictionSystem::EndPrediction();
	}

	return false;
}
