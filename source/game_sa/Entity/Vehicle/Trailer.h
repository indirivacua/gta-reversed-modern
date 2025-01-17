/*
    Plugin-SDK file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "Automobile.h"

enum eTrailerNodes {
    TRAILER_NODE_NONE  = 0,
    TRAILER_CHASSIS    = 1,
    TRAILER_WHEEL_RF   = 2,
    TRAILER_WHEEL_RM   = 3,
    TRAILER_WHEEL_RB   = 4,
    TRAILER_WHEEL_LF   = 5,
    TRAILER_WHEEL_LM   = 6,
    TRAILER_WHEEL_LB   = 7,
    TRAILER_DOOR_RF    = 8,
    TRAILER_DOOR_RR    = 9,
    TRAILER_DOOR_LF    = 10,
    TRAILER_DOOR_LR    = 11,
    TRAILER_BUMP_FRONT = 12,
    TRAILER_BUMP_REAR  = 13,
    TRAILER_WING_RF    = 14,
    TRAILER_WING_LF    = 15,
    TRAILER_BONNET     = 16,
    TRAILER_BOOT       = 17,
    TRAILER_WINDSCREEN = 18,
    TRAILER_EXHAUST    = 19,
    TRAILER_MISC_A     = 20,
    TRAILER_MISC_B     = 21,
    TRAILER_MISC_C     = 22,

    TRAILER_NUM_NODES
};

class NOTSA_EXPORT_VTABLE CTrailer : public CAutomobile {
    static constexpr auto NUM_TRAILER_WHEELS = 4;
    static constexpr auto NUM_TRAILER_SUPPORTS = 2;
    static constexpr auto NUM_TRAILER_SUSP_LINES = NUM_TRAILER_WHEELS + NUM_TRAILER_SUPPORTS;
public:
    std::array<CColPoint, NUM_TRAILER_SUPPORTS> m_supportCPs{};
    std::array<float, NUM_TRAILER_SUPPORTS> m_supportRatios{ 1.f, 1.f };
    float     m_fHeight; // 0x6CF3DC, 0x6CFC11
    float     m_fTrailerTowedRatio{ 1.f };
    float     m_fTrailerTowedRatio2{ 1.f };

public:
    CTrailer(int32 modelIndex, eVehicleCreatedBy createdBy);
    ~CTrailer() override = default; // 0x6CED10

    bool SetTowLink(CVehicle* tractor, bool setMyPosToTowBar) override;
    void ScanForTowLink();

    void SetupSuspensionLines() override;
    void ResetSuspension() override;
    void ProcessSuspension() override;

    int32 ProcessEntityCollision(CEntity* entity, CColPoint* colPoint) override;
    void  ProcessControl() override;
    bool  ProcessAI(uint32& extraHandlingFlags) override;

    void  PreRender() override;

    bool  GetTowHitchPos(CVector& outPos, bool bCheckModelInfo, CVehicle* vehicle) override;
    bool  GetTowBarPos(CVector& outPos, bool bCheckModelInfo, CVehicle* vehicle) override;
    bool  BreakTowLink() override;

private:
    friend void InjectHooksMain();
    static void InjectHooks();

    CTrailer* Constructor(int32 modelIndex, eVehicleCreatedBy createdBy) { this->CTrailer::CTrailer(modelIndex, createdBy); return this; }
};

VALIDATE_SIZE(CTrailer, 0x9F4);
