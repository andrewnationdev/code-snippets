// Simulação de World Streaming e Pooling do GTA 3 no PS2

#include <iostream>

const int MAX_VEHICLES = 140;

struct Vehicle {
    bool active;
    Vector3 position;
    Matrix4x4 matrix;
    ModelID modelId;
};

Vehicle vehiclePool[MAX_VEHICLES];

Vehicle* CreateVehicle(ModelID id, Vector3 pos) {
    for (int i = 0; i < MAX_VEHICLES; i++) {
        if (!vehiclePool[i].active) {
            vehiclePool[i].active = true;
            vehiclePool[i].position = pos;
            vehiclePool[i].modelId = id;
            return &vehiclePool[i];
        }
    }
    return nullptr;
}

void DestroyVehicle(Vehicle* veh) {
    veh->active = false;
}

void UpdateWorldStreaming(Vector3 playerPos) {
    SectorId currentSector = GetSectorAt(playerPos);

    for (int i = 0; i < TOTAL_LOADED_SECTORS; i++) {
        SectorId sector = loadedSectors[i];
        if (Distance(sector, currentSector) > STREAM_OUT_DISTANCE) {
            UnloadSectorFromMemory(sector);
        }
    }

    for (int i = 0; i < TOTAL_SECTORS; i++) {
        SectorId sector = allSectors[i];
        if (Distance(sector, currentSector) <= STREAM_IN_DISTANCE && !IsLoaded(sector)) {
            RequestAsyncLoadFromDVD(sector);
        }
    }
}

void RenderScene() {
    RwCameraBeginUpdate(camera);

    for (int i = 0; i < MAX_VISIBLE_ENTITIES; i++) {
        Entity* ent = visibleEntities[i];
        if (IsInFrustum(ent, camera)) {
            // Envia os dados de vértices e matriz para a Vector Unit 1
            RwD3DSubmitAtom(ent->mesh, &ent->transformMatrix);
        }
    }

    RwCameraEndUpdate(camera);
}

int main() {
    // Write C++ code here

    std::cout << "Try clicking the Run button.";
    return 0;
}
