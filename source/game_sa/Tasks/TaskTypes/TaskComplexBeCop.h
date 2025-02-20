#pragma once

#include "TaskComplexWanderCop.h"

class NOTSA_EXPORT_VTABLE CTaskComplexBeCop : public CTaskComplexWanderCop {
    static constexpr auto Type = TASK_COMPLEX_BE_COP;

    CTaskComplexBeCop(uint8 moveState, bool dir, CTask* task) : CTaskComplexWanderCop(moveState, dir) {
        m_pGoToPointAndStandStillTask = static_cast<CTaskComplexGoToPointAndStandStill*>(task);
    };

    eTaskType GetTaskType() override { return Type; }
    CTask* Clone() override { return new CTaskComplexBeCop(m_nMoveState, m_nDir, m_pGoToPointAndStandStillTask->Clone()); }
};
VALIDATE_SIZE(CTaskComplexBeCop, 0x50);
