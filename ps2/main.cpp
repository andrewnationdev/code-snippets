#include <iostream>
#include <cstdint>
#include <vector>
#include <fstream>
#include <string>

struct EmotionEngineRAM {
    std::vector<uint8_t> memory;
    uint32_t PC;

    EmotionEngineRAM(size_t size) {
        memory.resize(size, 0);
        PC = 0;
    }
};

bool system_loaded = false;

void init_hardware(){
    printf("[HW] Zerando barramentos de memória...\n");
    printf("[HW] Limpando registradores do Emotion Engine (R5900)...\n");
    printf("[HW] Inicializando controladores de DMA...\n");
}

void run_POST_cheks(){
    printf("[POST] Verificando integridade da RAM principal (32MB)...\n");
    printf("[POST] Verificando subsistema gráfico (GS VRAM 4MB)...\n");
    printf("[POST] Status: OK. Nenhum erro crítico encontrado.\n");
}

void load_BIOS_to_RAM(){
    printf("[BIOS] Lendo imagem da ROM (ROM0 / ROM1)...\n");
    printf("[BIOS] Copiando dados do kernel para o mapa de memória...\n");
    printf("[BIOS] Pulando rotina de verificação de região (para fins de simulação)...\n");
}

void init_emotion_engine(){
    printf("[EE] CPU R5900 iniciada em modo 300MHz.\n");
    printf("[EE] Unidades Vectoriais (VU0 / VU1) prontas.\n");
}

void load_graphics_synthesizer(){
    printf("[GS] Graphics Synthesizer inicializado.\n");
    printf("[GS] Configurando modo de vídeo padrão (NTSC / PAL)...\n");
}

void load_system_settings(){
    system_loaded = true;
}

bool is_there_optical_media(){
    return true;
}

void init_browser_menu(){
    printf("[BROWSER] Carregando interface de gerenciamento de Memory Card e Configurações...\n");
    printf("[BROWSER] Aguardando input do usuário...\n");
}

bool is_system_loaded(){
    return system_loaded;
}

bool load_ELF_file(const std::string& filepath, EmotionEngineRAM& ee) {
    // 1. Abre o arquivo e vai direto para o fim para medir o tamanho
    std::ifstream file(filepath, std::ios::binary | std::ios::ate);

    // Trava 1: Se não abriu, avisa no terminal em vez de dar segfault
    if (!file.is_open()) {
        std::cerr << "[ERRO CRÍTICO] Não foi possível encontrar ou abrir o arquivo: " << filepath << "\n";
        std::cerr << "Dica: Verifique se o caminho está correto em relação a onde você executou o binário.\n";
        return false;
    }

    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg); // Volta para o início

    // Trava 2: Se o arquivo estiver vazio (0 bytes), evita leitura inválida
    if (fileSize <= 0) {
        std::cerr << "[ERRO] O arquivo ELF está vazio!\n";
        return false;
    }

    uint32_t load_address = 0x00100000; // Endereço base na RAM

    // Trava 3: Verifica se o arquivo cabe na RAM simulada antes de copiar
    if (load_address + fileSize > ee.memory.size()) {
        std::cerr << "[ERRO] O arquivo é maior do que a RAM simulada (32MB)!\n";
        return false;
    }

    // Leitura segura protegida
    if (file.read(reinterpret_cast<char*>(&ee.memory[load_address]), fileSize)) {
        std::cout << "[ELF] Carregado com sucesso: " << filepath << " (" << fileSize << " bytes)\n";
        ee.PC = load_address;
        return true;
    }

    std::cerr << "[ERRO] Falha na leitura dos bytes do arquivo.\n";
    return false;
}

// Ciclo de CPU
void exec_CPU_cycle(EmotionEngineRAM& ee) {
    // Validação de segurança para o PC não estourar a RAM
    if (ee.PC + 4 > ee.memory.size()) {
        std::cerr << "[ERRO] PC fora dos limites da RAM: 0x" << std::hex << ee.PC << "\n";
        system_loaded = false; // Para o loop
        return;
    }

    // [FETCH seguro]: Lê 4 bytes da RAM simulada respeitando a ordem Little Endian
    uint32_t instruction =
            (static_cast<uint32_t>(ee.memory[ee.PC + 0])) |
            (static_cast<uint32_t>(ee.memory[ee.PC + 1]) << 8) |
            (static_cast<uint32_t>(ee.memory[ee.PC + 2]) << 16) |
            (static_cast<uint32_t>(ee.memory[ee.PC + 3]) << 24);

    // Avança para a próxima instrução
    ee.PC += 4;
}

int main(){
    init_hardware();
    run_POST_cheks();
    load_BIOS_to_RAM();
    init_emotion_engine();
    load_graphics_synthesizer();
    load_system_settings();

    EmotionEngineRAM ps2_ram(32 * 1024 * 1024);

    if(is_there_optical_media()){
        printf("Mídia detectada. Carregando executável..\n");
        load_ELF_file("./drive/game/GAME.ELF", ps2_ram);
        //load_game();
    } else {
        printf("Nenhuma mídia. Iniciando Browser do PS2...\n");
        init_browser_menu();
    }

    while(is_system_loaded()){
        exec_CPU_cycle(ps2_ram);
        //update_graphics_synthesizer();
    }

    return 0;
}
