#pragma once

#include "Vector.h"
#include "TaskSimpleRunNamedAnim.h"

constexpr auto STAND_STILL_TIME = 20000; // 0x86DB24

class CTaskSimpleSlideToCoord : public CTaskSimpleRunNamedAnim {
public:
    CVector m_SlideToPos;
    float   m_fAimingRotation; // Heading
    float   m_fSpeed;
    bool    m_bFirstTime : 1;
    bool    m_bRunningAnim : 1;
    int32   m_Timer;

public:
    static constexpr auto Type = TASK_SIMPLE_SLIDE_TO_COORD;

    CTaskSimpleSlideToCoord(const CVector& slideToPos, float fAimingRotation, float speed);
    CTaskSimpleSlideToCoord(const CVector& slideToPos, float aimingRotation, float speed, const char* animBlockName, const char* animGroupName, uint32 animFlags, float animBlendDelta, bool bRunInSequence, uint32 time);
    ~CTaskSimpleSlideToCoord() override = default;

    CTask* Clone() override;
    eTaskType GetTaskType() override { return Type; }
    bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event) override;
    bool ProcessPed(CPed* ped) override;

private:
    friend void InjectHooksMain();
    static void InjectHooks();

    CTaskSimpleSlideToCoord* Constructor(const CVector& pos, float fAimingRotation, float radius) { this->CTaskSimpleSlideToCoord::CTaskSimpleSlideToCoord(pos, fAimingRotation, radius); return this; }
    CTaskSimpleSlideToCoord* Constructor(const CVector& pos, float aimRot, float radius, const char* animName, const char* fileName, int32 flags, float frameDelta, bool isActiveSequence, int32 time) { this->CTaskSimpleSlideToCoord::CTaskSimpleSlideToCoord(pos, aimRot, radius, animName, fileName, flags, frameDelta, isActiveSequence, time); return this; }
    CTaskSimpleSlideToCoord* Destructor() { this->CTaskSimpleSlideToCoord::~CTaskSimpleSlideToCoord(); return this; }
    CTask* Clone_Reversed() { return CTaskSimpleSlideToCoord::Clone(); }
    eTaskType GetTaskType_Reversed() { return CTaskSimpleSlideToCoord::GetTaskType(); }
    bool MakeAbortable_Reversed(CPed* ped, eAbortPriority priority, const CEvent* event) { return CTaskSimpleSlideToCoord::MakeAbortable(ped, priority, event); }
    bool ProcessPed_Reversed(CPed* ped) { return CTaskSimpleSlideToCoord::ProcessPed(ped); }
};
VALIDATE_SIZE(CTaskSimpleSlideToCoord, 0x80);
