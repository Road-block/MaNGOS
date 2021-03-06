/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef DEF_TEMPLE_OF_AHNQIRAJ_H
#define DEF_TEMPLE_OF_AHNQIRAJ_H

enum
{
    MAX_ENCOUNTER               = 10,

    TYPE_SKERAM                 = 0,
    TYPE_VEM                    = 1,
    TYPE_TWINS                  = 2,
    TYPE_CTHUN_PHASE            = 3,
    TYPE_SARTURA                = 4,
    TYPE_FANKRISS               = 5,
    TYPE_VISCIDUS               = 6,
    TYPE_HUHURAN                = 7,
    TYPE_OURO                   = 8,
    TYPE_ANUBISATH              = 9,

    // NPC_SKERAM               = 15263,
    NPC_YAUJ                    = 15543,
    NPC_KRI                     = 15511,
    NPC_VEM                     = 15544,
    NPC_FANKRISS            = 15510,
    NPC_HUHURAN             = 15509,
    NPC_VISCIDUS                = 15299,
    NPC_VEKLOR                  = 15276,
    NPC_VEKNILASH               = 15275,
    NPC_EYE_OF_CTHUN     = 15589,
    NPC_CTHUN                   = 15727,
    NPC_VISCIDUS_DUMMY = 800109,
    NPC_OURO_GROUND = 157120,
    NPC_EVADE_DUMMY = 800114,
    
    // Trash
    NPC_ANUBISATH_DEFENDER = 15277,    
    
    // Skeram trash
    OBSIDIAN_ERADICATOR = 15262,
    ANUBISATH_SENTINEL = 15264,
    
    // Sartura trash
    QIRAJI_MINDSLAYER = 15247,
    VEKNISS_WARRIOR = 15230,
    VEKNISS_GUARDIAN = 15233,
    
    // Fankriss trash
    VEKNISS_SOLDIER = 15229,
    
    // Huhuran trash
    VEKNISS_HIVE_CRAWLER = 15240,
    VEKNISS_WASP = 15236,
    VEKNISS_STINGER = 15235,
    QIRAJI_LASHER = 15249,
    

    GO_SKERAM_GATE              = 180636,
    GO_TWINS_ENTER_DOOR         = 180634,
    GO_TWINS_EXIT_DOOR          = 180635,

    DATA_BUG_TRIO_DEATH         = 10,
};

enum CThunPhase
{
    PHASE_NOT_STARTED           = 0,
    PHASE_EYE_NORMAL            = 1,
    PHASE_EYE_DARK_GLARE        = 2,
    PHASE_TRANSITION            = 3,
    PHASE_CTHUN                 = 4,
    PHASE_CTHUN_WEAKENED        = 5,
    PHASE_FINISH                = 6,
};

typedef UNORDERED_MAP<ObjectGuid, bool> StomachMap;

class MANGOS_DLL_DECL instance_temple_of_ahnqiraj : public ScriptedInstance
{
    public:
        instance_temple_of_ahnqiraj(Map* pMap);

        void Initialize();

        bool IsEncounterInProgress() const;

        void OnCreatureCreate(Creature* pCreature);
        void OnCreatureDeath(Creature* pCreature);
        
        void OnObjectCreate(GameObject* pGo);

        void SetData(uint32 uiType, uint32 uiData);
        uint32 GetData(uint32 uiType);

        const char* Save() { return m_strInstData.c_str(); }
        void Load(const char* chrIn);

        void OnPlayerDeath(Player* pPlayer);

        // Map for storing players in C'Thun's stomach.
        StomachMap& GetStomachMap() { return m_mStomachMap; }

    private:
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;                

        uint32 m_uiBugTrioDeathCount;
        
        GUIDList m_lSkeramTrash;
        GUIDList m_lFankrissTrash;
        GUIDList m_lSarturaTrash;
        GUIDList m_lHuhuranTrash;
        
        uint32 m_lAnbDefenderCounter;
        
        // Stomach map, bool = true then in stomach
        StomachMap m_mStomachMap;
};

#endif
